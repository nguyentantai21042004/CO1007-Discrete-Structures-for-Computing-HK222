#include "calculate.h"

bool isLogicoperator(char c)
{
    if (c == '<' || c == '>' || c == '|' || c == '&' || c == '~')
        return true;
    return false;
}

int onLogicpredence(string op)
{
    if (op == "<->")
        return 1;
    else if (op == "->")
        return 2;
    else if (op == "|" || op == "&")
        return 3;
    else if (op == "~")
        return 4;

    else
        return 0;
}

bool checkLogicPostfixPredence(string a, string b)
{
    return onLogicpredence(a) >= onLogicpredence(b);
}

string PostfixCalculator(string input, string varlue)
{
    string final;

    map<char, bool> vari;
    vector<char> tmp1;
    vector<int> tmp2;
    for (int i = 0; i < (int)(varlue.length()); i++)
    {
        if (varlue[i] == ' ')
            continue;
        else if (isalpha(varlue[i]))
            tmp1.push_back(varlue[i]);
        else if (isdigit(varlue[i]))
            tmp2.push_back(varlue[i] - '0');
    }
    for (int i = 0; i < (int)(tmp1.size()); i++)
        vari[tmp1[i]] = tmp2[i];
    tmp1.clear();
    tmp2.clear();

    stack<bool> S;
    bool output = 0;
    for (int i = 0; i < (int)(input.size()); i++)
    {
        if (isalpha(input[i]))
        {
            S.push(vari[input[i]]);
        }
        else if (isLogicoperator(input[i]) && input[i - 2] != '<')
        {
            if (input[i] == '~')
            {
                bool operand1;
                if (!S.empty())
                {
                    operand1 = S.top();
                    S.pop();
                }
                bool result = LogicCalculate("~", operand1, 0);
                S.push(result);
            }
            else
            {
                string tmp;
                if (input[i] == '<')
                    tmp = "<->";
                else if (input[i] == '>' && input[i - 2] != '<')
                    tmp = "->";
                else
                {
                    string op(1, input[i]);
                    tmp = op;
                }
                bool operand2, operand1;
                if (!S.empty())
                {
                    operand2 = S.top();
                    S.pop();
                }
                if (!S.empty())
                {
                    operand1 = S.top();
                    S.pop();
                }

                bool result = LogicCalculate(tmp, operand1, operand2);
                S.push(result);
            }
        }
    }
    if (!S.empty())
        output = S.top();
    while (!S.empty())
        S.pop();
    input.clear();
    varlue.clear();
    vari.clear();

    if (output == 1)
        final = "TRUE";
    else
        final = "FALSE";
    return final;
}

string calculateLogicPostfixAndPrefix(string input, string varlue)
{
    if (isLogicoperator(input[0]))
    {
        LogicChange(input);
        return PostfixCalculator(input, varlue);
    }
    else
        return PostfixCalculator(input, varlue);
}