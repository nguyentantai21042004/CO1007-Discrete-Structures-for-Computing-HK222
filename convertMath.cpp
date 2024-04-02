#include "calculate.h"

string convertInfixToPostfix(string infix)
{
    stack<char> S;
    string postfix = "";

    for (int i = 0; i < (int)(infix.length()); i++)
    {
        if (infix[i] == ' ')
            continue;

        else if (infix[i] == '(')
            S.push(infix[i]);

        else if (isdigit(infix[i]))
            postfix += infix[i];

        else if (isMathoperator(infix[i]))
        {
            postfix += ' ';
            while (!S.empty() && S.top() != '(' && checkMathPostfixPredence(S.top(), infix[i]))
            {
                postfix += S.top();
                postfix += ' ';
                S.pop();
            }
            S.push(infix[i]);
        }

        else if (infix[i] == ')')
        {
            while (!S.empty() && S.top() != '(')
            {
                postfix += ' ';
                postfix += S.top();
                S.pop();
            }
            S.pop();
        }
    }
    while (!S.empty())
    {
        postfix += ' ';
        postfix += S.top();
        S.pop();
    }
    return postfix;
}

string convertInfix2Prefix(string infix)
{
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < (int)(infix.length()); i++)
    {
        if (infix[i] == '(')
            infix.replace(i, 1, ")");
        else if (infix[i] == ')')
            infix.replace(i, 1, "(");
    }
    string prefix = convertInfixToPostfix(infix);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}