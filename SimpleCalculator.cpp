#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <cctype>

// Function declarations
double evaluateExpression(const std::string& expression);
double performOperation(double num1, double num2, char operation);

int main() {
    std::string expression;

    std::cout << "Simple Calculator (type 'quit' to exit)\n";

    while (true) {
        std::cout << "Enter an expression: ";
        std::getline(std::cin, expression);

        // Exit condition
        if (expression == "quit") {
            std::cout << "Quitting the calculator. Goodbye!" << std::endl;
            break;
        }

        // Evaluate the expression
        try {
            double result = evaluateExpression(expression);
            std::cout << "Result: " << result << std::endl;
        }
        catch (const std::invalid_argument&) {
            std::cout << "Invalid expression. Please try again." << std::endl;
        }
    }

    return 0;
}

// Function to evaluate a simple mathematical expression
double evaluateExpression(const std::string& expression) {
    std::istringstream stream(expression);
    double num1, num2;
    char operation;

    // Read the first number
    stream >> num1;

    while (stream >> operation) {
        // Check if the next character is a valid operator
        if (operation != '+' && operation != '-' && operation != '*' && operation != '/' && operation != '^') {
            throw std::invalid_argument("Invalid operator");
        }

        // Read the next number
        stream >> num2;

        // Perform the operation
        num1 = performOperation(num1, num2, operation);
    }

    return num1;
}

// Function to perform the operations
double performOperation(double num1, double num2, char operation) {
    switch (operation) {
    case '+': return num1 + num2;
    case '-': return num1 - num2;
    case '*': return num1 * num2;
    case '/':
        if (num2 == 0) {
            throw std::invalid_argument("Division by zero");
        }
        return num1 / num2;
    case '^': return pow(num1, num2);
    default: throw std::invalid_argument("Invalid operation");
    }
}
