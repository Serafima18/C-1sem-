#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cctype>
#include <cstdlib>

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '%') return 2;
    return 0;
}

double calculate(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

double evaluateExpression(const std::string& expression) {
    std::stack<double> values;
    std::stack<char> ops;
    
    for (size_t i = 0; i < expression.length(); i++) {
        // Пропускаем пробелы
        if (isspace(expression[i])) continue;

        // Если текущее выражение - число
        if (isdigit(expression[i])) {
            std::stringstream ss;
            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                ss << expression[i++];
            }
            values.push(std::stod(ss.str()));
            i--; // Вернуться к последнему числу
        } 
        // Если это открытая скобка
        else if (expression[i] == '(' || expression[i] == '{') {
            ops.push(expression[i]);
        } 
        // Если это закрытая скобка
        else if (expression[i] == ')' || expression[i] == '}') {
            while (!ops.empty() && ops.top() != '(' && ops.top() != '{') {
                double val2 = values.top(); values.pop();
                double val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(calculate(val1, val2, op));
            }
            ops.pop(); // Убираем открывающую скобку
        } 
        // Если это оператор
        else if (isOperator(expression[i])) {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expression[i])) {
                double val2 = values.top(); values.pop();
                double val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(calculate(val1, val2, op));
            }
            ops.push(expression[i]);
        }
    }

    // Обработка оставшихся операторов
    while (!ops.empty()) {
        double val2 = values.top(); values.pop();
        double val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(calculate(val1, val2, op));
    }

    return values.top();
}

int main() {
    std::string expression = "{(4+5) * 6}/(3+4)";
    double result = evaluateExpression(expression);
    
    std::cout << "The result of the expression " << expression << " = " << result << std::endl;

    return 0;
}