#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string infixToRPN(string infix) {
    string rpn = "";
    stack<char> opStack;

    for (char c : infix) {
        if (isalnum(c)) {
            rpn += c;  // Nếu là toán hạng, thêm vào RPN
        } else if (c == '(') {
            opStack.push(c);
        } else if (c == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                rpn += opStack.top();
                opStack.pop();
            }
            opStack.pop();  // Loại bỏ '(' khỏi ngăn xếp
        } else if (isOperator(c)) {
            while (!opStack.empty() && precedence(c) <= precedence(opStack.top())) {
                rpn += opStack.top();
                opStack.pop();
            }
            opStack.push(c);
        }
    }

    while (!opStack.empty()) {
        rpn += opStack.top();
        opStack.pop();
    }

    return rpn;
}

int main() {
    string infixExpression = "11 + ( ( 10 - 2 ) * 6 ) + 7";
    cout << "Nhap bieu thuc trung to: ";
    cin >> infixExpression;

    string rpnExpression = infixToRPN(infixExpression);
    cout << "Bieu thuc nghich dao ba lan (RPN): " << rpnExpression << endl;

    return 0;
}
