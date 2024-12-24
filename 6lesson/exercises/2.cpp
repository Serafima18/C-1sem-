// базовый калькулятор

#include "std_lib.h"

// Моделирует токен на основе входных данных
class Token {
public:
	char kind;  
	double value;
	string name;

	Token(char ch) :kind{ch} { }
	Token(char ch, double val) :kind{ch}, value{val} { }
	Token(char ch, string n) : kind{ch}, name{n} { }
};

// Модели могут быть представлены в виде потока токенов
class Token_stream {
public:
    //Token_stream() :full{false}, buffer{0} { }
	Token get();
	void putback(Token t) { buffer.push_back(t); }
	void ignore(char c);
private:
	vector<Token> buffer;
};

// Типы токенов
const char let = 'L';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char sqrtfun = 's';
const char powfun = 'p';
// Ключевые слова
const string declkey = "let";
const string quitkey = "quit";
// Встроенные функции
const string sqrtkey = "sqrt";
const string powkey = "pow";

Token Token_stream::get(){
// Обрабатывает cin для получения токенов из реализованной грамматики
    if (!buffer.empty()) {
        Token t = buffer.back();
        buffer.pop_back();
        return t;
    }

	char ch;
	cin >> ch;
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
	case ',': // Добавлен в качестве разделителя для списков аргументов функций
	return Token{ch}; // Тип токена
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':   // Числовой литерал
	{	cin.putback(ch);
		double val;
		cin >> val;
		return Token{number, val};
	} 
	default:
	    // Ключевый слова для объявления
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s += ch;
			cin.putback(ch);
			if (s == declkey) return Token{let};	
			if (s == quitkey) return Token{quit};
			if (s == sqrtkey) return Token{sqrtfun};
			if (s == powkey) return Token{powfun};
			return Token{name,s};
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c){
// Очищать ввода до тех пор, пока найден c или '\n'

    // Сначала проверим, не буферизован ли токен типа c
    while (!buffer.empty() && buffer.back().kind != c) buffer.pop_back();
    // Буфер содержит токен типа c
    if (!buffer.empty()) return;

	char ch{' '};
    while (ch != c && ch != '\n') ch = cin.get();
    return;
}

class Variable {
public:
	string name;
	double value;
};

vector<Variable> var_table;	

double get_value(string s){
	for (const Variable& v : var_table)
	    if (v.name == s) return v.value;
	error("get: undefined name ", s);
}

void set_value(string s, double d)
{
    for (Variable& v : var_table)
        if (v.name == s) {
            v.value = d;
            return;
        }

	error("set: undefined name ", s);
}

bool is_declared(string s)
{
	for (const Variable& v : var_table)
	    if (v.name == s) return true;
	return false;
}

Token_stream ts;

double expression();

double eval_function(char c){
// Вычисляет функцию типа c.

    vector<double> args;    // Вектор для хранения (номера переменной) функции
    Token t = ts.get();
    if (t.kind != '(') error("'(' expected after function call");

    // Обработка списока аргументов.
    switch (c) {
    case sqrtfun:
        args.push_back(expression());
        break;
    case powfun:
        args.push_back(expression());
        t = ts.get();
        if (t.kind != ',') error("Bad number of function arguments");
        args.push_back(expression());
        break;
    }

    t = ts.get();
    if (t.kind != ')') error("Bad number of function arguments");

    // Внедрение ограничений
    switch (c) {
    case sqrtfun:
        if (args[0] < 0) error("sqrt() is undefined for negative numbers");
        return sqrt(args[0]);
    case powfun: return pow(args[0], narrow_cast<int>(args[1]));
    default: error("Function not implemented");
        // В случае, если мы определили имя как токен, но не выполнили его вычисление
    }
}

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d;
	}
	case '-': return - primary(); // Отрицательные числа
	case '+': return primary(); // Положительные числа
	case number: return t.value;
    case name: return get_value(t.name); // Переменная: получение значения из таблицы
	case sqrtfun:
	case powfun: return eval_function(t.kind); // Вызов eval_function с помощью t.kind, чтобы мы могли свернуть вычисление
	default: error("primary expected");
	}
}

double term()
{
	double left = primary();
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':{
            double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			break;
		}
        case '%':{
            double d = primary();
            if (d == 0) error("divide by zero");
            left = fmod(left, d);
            break;
        }
		default:
			ts.putback(t);
			return left;
		}
	}
}

double expression(){
	double left = term();
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

double assignment(){
    // Следующими будут имя и '='.
    Token t = ts.get();
    string var_name = t.name;
    if (!is_declared(var_name)) error(var_name, " has not been declared");

    ts.get(); // Избавление от '='
    double d = expression();
    set_value(var_name, d);
    return d;
}


double declaration(){
    // Проверяем по частям грамматическое правило объявления, стоящее за "let"
	Token t = ts.get();
	if (t.kind != name) error ("name expected in declaration");
	string var_name = t.name;
	if (is_declared(var_name)) error(var_name, " declared twice");

	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of " ,var_name);

	double d = expression();
	var_table.push_back(Variable{var_name,d});
	return d;
}

double statement()
{
	Token t = ts.get();
	switch(t.kind) {
	case let: return declaration();
	case name: {
	    Token t2 = ts.get();
	    // Откат
        ts.putback(t2);
        ts.putback(t);
	    if (t2.kind == '=') {
	        return assignment();
	    }
	    return expression();
	}
	default:
		ts.putback(t);
		return expression();
	}
}

void clean_up_mess(){
	ts.ignore(print); // Отмена ввода до тех пор, пока не будет найдена команда печати или новая строка
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while(true) 
	try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get(); // Удаление команды печати
		if (t.kind == quit) return;
		ts.putback(t);
		cout << result << statement() << '\n';
	}
	catch(exception& e) {
		cerr << e.what() << '\n';
		clean_up_mess(); // Приглащение пользователя снова - отброс оставшихся вводимых данных
	}
}

int main()
try {
    // Предопределенные переменные
    var_table.push_back(Variable{"k", 1000});
    
    calculate();
    return 0;
}
catch (exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Uknown exception!\n";
	return 2;
}