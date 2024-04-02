#include "calculate.h"

string convertLogicInfix2LogicPostfix(string infix)
{
    string postfix = "";
    stack<string> S;

    for (int i = 0; i < (int)(infix.length()); i++)
    {
        if (infix[i] == '(')
        {
            string tmp(1, infix[i]);
            S.push(tmp);
        }

        else if (isalpha(infix[i]))
            postfix += infix[i];

        else if (isLogicoperator(infix[i]) && infix[i - 2] != '<')
        {
            string tmp;
            if (infix[i] == '<')
                tmp = "<->";
            else if (infix[i] == '>' && infix[i - 2] != '<')
                tmp = "->";
            else
            {
                string op(1, infix[i]);
                tmp = op;
            }

            while (!S.empty() && S.top() != "(" && checkLogicPostfixPredence(S.top(), tmp))
            {
                postfix += S.top();
                S.pop();
            }
            S.push(tmp);
        }

        else if (infix[i] == ')')
        {
            while (!S.empty() && S.top() != "(")
            {
                postfix += S.top();
                S.pop();
            }
            S.pop();
        }
    }

    while (!S.empty())
    {
        postfix += S.top();
        S.pop();
    }

    return postfix;
}

string convertLogicInfix2LogicPrefix(string infix)
{
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < (int)(infix.length()); i++)
    {
        if (infix[i] == '(')
            infix.replace(i, 1, ")");
        else if (infix[i] == ')')
            infix.replace(i, 1, "(");
    }
    string prefix = convertLogicInfix2LogicPostfix(infix);
    reverse(prefix.begin(), prefix.end());
    for (int i = 0; i < (int)(prefix.length()) - 2; i++)
    {
        if (prefix[i] == '>' && prefix[i + 1] == '-')
        {
            if (prefix[i + 2] == '<')
            {
                prefix.replace(i, 1, "<");
                prefix.replace(i + 1, 1, "-");
                prefix.replace(i + 2, 1, ">");
            }
            else
            {
                prefix.replace(i, 1, "-");
                prefix.replace(i + 1, 1, ">");
            }
        }
    }
    return prefix;
}