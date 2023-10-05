#include <iostream>
#include <cstring>
#include<math.h>
#define MAX_SIZE 100

using namespace std;

class InfixToPostfixConverter {
private:
    char postfix[MAX_SIZE];
    int top;
    int top2;
    char stack[MAX_SIZE]; // New stack to hold operators
    int stack2[MAX_SIZE];

    int getPrecedence(char op) {
        if (op == '+' || op == '-')
            return 1;
        else if (op == '*' || op == '/')
            return 2;
        else if(op == '^')return 3;
        return 0; // For parentheses
    }

    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }

public:
    InfixToPostfixConverter() {
        top = -1;
        top2 = -1;
    }

    //function for stack with character data;
    void push(char c) {
        if (top < MAX_SIZE - 1) {
            stack[++top] = c; // Push onto the stack
        }
    }

    char pop() {
        if (top >= 0) {
            return stack[top--]; // Pop from the stack
        }
        return '\0';
    }

    char peek() {
        if (top >= 0) {
            return stack[top];
        }
        return '\0';
    }
    //function for stack with integer data
      void push2(int c) {
        if (top2 < MAX_SIZE - 1) {
            stack[++top2] = c; // Push onto the stack(integer)
        }
    }
      int pop2() {
        if (top2 >= 0) {
            return stack[top2--]; // Pop from the stack(integer)
        }
        return -1;
      }

      int peek2() {
        if (top2 >= 0) {
            return stack[top2];
        }
        return -1;
    }

    string convertToPostfix(string infixExpression) {
        int length = infixExpression.length();
        int j = 0;
        postfix[0] = '\0'; // Initialize the postfix array
        top = -1; // Reset the stack

        for (int i = 0; i < length; i++) {
            char c = infixExpression[i];

            if (isalnum(c)) {
                postfix[j++] = c; // If character is an operand, add it to postfix
            } else if (c == '(') {
                push(c); // Push '(' onto the stack
            } else if (c == ')') {
                while (top >= 0 && peek() != '(') {
                    postfix[j++] = pop(); // Pop operators from stack and add to postfix until '(' is encountered
                }
                if (top >= 0 && peek() == '(') {
                    pop(); // Pop and discard '('
                }
            } else {
                while (top >= 0 && getPrecedence(c) <= getPrecedence(peek())) {
                    postfix[j++] = pop(); // Pop operators with higher precedence and add to postfix
                }
                push(c); // Push current operator onto the stack
            }
        }

        while (top >= 0) {
            postfix[j++] = pop(); // Pop any remaining operators and add to postfix
        }

        postfix[j] = '\0'; // Null-terminate the postfix expression

        return postfix;
    }



    int calculate(string postfixExpression)
    {
      top2 = -1;//Reset the stack with integer data
      for(int i=0;i<postfixExpression.length();++i)
      {
        if(isalnum(postfixExpression[i]))//checking for alpha numeric
        {
          cout<<"Enter the value of "<<postfixExpression[i]<<":"<<endl;
          int x;
          cin>>x;
          push2(x);//pushing the number into the integer stack
        }
        else
        {
          int a = pop2();
          int b = pop2();//popping out the top two numbers to perform calculation
          int res;
          if(postfixExpression[i]=='+')
          {
            res = b+a;
            push2(res);
          }
          else if(postfixExpression[i]=='-')
          {
            res = b-a;
            push2(res);
          }
          else if(postfixExpression[i]=='/')
          {
            res = b/a;
            push2(res);
          }
          else if(postfixExpression[i]=='*')
          {
            res = b*a;
            push2(res);
          }
          else if(postfixExpression[i] == '^')
          {
            res = pow(b,a);
            push2(res);
          }
        }

      }
      return pop2();//returning the only the element in the integer stack
    }
};

int main() {
    InfixToPostfixConverter converter;
    string infixExpression;

    cout << "Enter the Infix expression: ";
    cin>>infixExpression; // Use getline to read the entire line

    string postfixExpression = converter.convertToPostfix(infixExpression);

    cout << "Postfix expression: " << postfixExpression << endl;
    while(1)
    {
      cout<<"1.Evaluate expression with numbers\n2.End the operation"<<endl;
      char x;
      cin>>x;
      if(x == '1')
      {
        cout<<"Evaluated expression is:"<<converter.calculate(postfixExpression)<<endl;
      }
      else break;
    }
    return 0;
}
