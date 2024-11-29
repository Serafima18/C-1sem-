#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <map>

enum class TokenType {
    Number,
    Not,
    And,
    Or,
    Xor,
    LParen,
    RParen,
    End
};

struct Token {
    TokenType type;
    bool value; // Для логических значений
};

class Lexer {
public:
    Lexer(const std::string& input) : input(input), pos(0) {}

    Token nextToken() {
        while (pos < input.size() && isspace(input[pos])) {
            pos++;
        }

        if (pos >= input.size()) {
            return {TokenType::End, false};
        }

        char current = input[pos];
        switch (current) {
            case '0':
                pos++;
                return {TokenType::Number, false};
            case '1':
                pos++;
                return {TokenType::Number, true};
            case '!':
                pos++;
                return {TokenType::Not, false};
            case '&':
                pos++;
                return {TokenType::And, false};
            case '|':
                pos++;
                return {TokenType::Or, false};
            case '^':
                pos++;
                return {TokenType::Xor, false};
            case '(':
                pos++;
                return {TokenType::LParen, false};
            case ')':
                pos++;
                return {TokenType::RParen, false};
            default:
                throw std::runtime_error("Unexpected character");
        }
    }

private:
    std::string input;
    size_t pos;
};

class Parser {
public:
    Parser(Lexer& lexer) : lexer(lexer), currentToken(lexer.nextToken()) {}

    bool parse() {
        return expression();
    }

private:
    Lexer& lexer;
    Token currentToken;

    void eat(TokenType type) {
        if (currentToken.type == type) {
            currentToken = lexer.nextToken();
        } else {
            throw std::runtime_error("Unexpected token");
        }
    }

    bool expression() {
        bool left = term();

        while (currentToken.type == TokenType::Or) {
            eat(TokenType::Or);
            left = left || term();
        }

        return left;
    }

    bool term() {
        bool left = factor();

        while (currentToken.type == TokenType::And) {
            eat(TokenType::And);
            left = left && factor();
        }

        return left;
    }

    bool factor() {
        if (currentToken.type == TokenType::Not) {
            eat(TokenType::Not);
            return !factor();
        } else if (currentToken.type == TokenType::Number) {
            bool value = currentToken.value;
            eat(TokenType::Number);
            return value;
        } else if (currentToken.type == TokenType::LParen) {
            eat(TokenType::LParen);
            bool value = expression();
            eat(TokenType::RParen);
            return value;
        } else {
            throw std::runtime_error("Unexpected token in factor");
        }
    }
};

int main() {
    std::string input;
    std::cout << "Enter a boolean expression (example: 1 & 0 | !1): ";
    std::getline(std::cin, input);

    try {
        Lexer lexer(input);
        Parser parser(lexer);
        bool result = parser.parse();
        std::cout << "Result: " << result << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}