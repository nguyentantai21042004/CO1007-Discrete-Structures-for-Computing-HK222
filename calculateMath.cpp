#include "calculate.h"

bool isMathoperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    return false;
}

int onMathpredence(char c)
{
    if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    return 0;
}

bool checkMathPostfixPredence(char a, char b)
{
    return onMathpredence(a) >= onMathpredence(b);
}


bool checkMathPrefixPredence(char a, char b)
{
    return onMathpredence(a) > onMathpredence(b);
}


string Double2String(double number)
{
    string str = to_string(number);
    size_t pos = str.find('.');
    if (str[pos + 5] >= '5' && str[pos + 4] <= '8')
    {
        str[pos + 4] += 1;
    }
    else if (str[pos + 5] >= '5' && str[pos + 4] == '9')
    {
        str[pos + 3] += 1;
        str[pos + 4] = 0;
    }
    if (pos != string::npos)
    {
        str = str.substr(0, pos + 5);
    }
    for (int i = int(str.length() - 1); i >= 0; i--)
    {
        if (str[i] == '0')
        {
            str.erase(str.length() - 1, 1);
        }
        else
        {
            if (i > 0 && str[i] == '.')
            {
                str.erase(str.length() - 1, 1);
            }
            break;
        }
    }
    return str;
}

string MathChange(string &tmp)
{
    string turn = "";
    vector<string> arr;
    stringstream ss(tmp);
    string k;
    while (ss >> k)
    {
        arr.push_back(k);
    }
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        turn += arr[i];
        turn += ' ';
    }
    return turn;
}

double MathCalculate(char operation, double operand1, double operand2)
{
    if (operation == '+')
        return operand1 + operand2;
    else if (operation == '-')
        return operand1 - operand2;
    else if (operation == '*')
        return operand1 * operand2;
    else if (operation == '/')
        return operand1 / operand2;
    else if (operation == '^')
        return pow(operand1, operand2);
    return 0;
}

string PostfixCalculator(string input)
{
    stack<double> operandStack;

    stringstream ss(input);
    string token;

    while (ss >> token)
    {
        if (isdigit(token[0]))
        {
            double operand = stod(token);
            operandStack.push(operand);
        }
        else if (isMathoperator(token[0]))
        {
            double operand2 = operandStack.top();
            if (!operandStack.empty())
                operandStack.pop();
            double operand1 = operandStack.top();
            if (!operandStack.empty())
                operandStack.pop();

            double result = MathCalculate(token[0], operand1, operand2);
            operandStack.push(result);
        }
    }
    double result = operandStack.top();
    while (!operandStack.empty())
    {
        operandStack.pop();
    }
    return Double2String(result);
}

string PrefixCalculator(string input)
{
    stack<double> operandStack;
    istringstream iss(input);
    string token;

    while (iss >> token)
    {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])))
        {
            operandStack.push(stof(token));
        }
        else
        {
            double operand1 = operandStack.top();
            if (!operandStack.empty())
                operandStack.pop();
            double operand2 = operandStack.top();
            if (!operandStack.empty())
                operandStack.pop();

            double result = MathCalculate(token[0], operand1, operand2);
            operandStack.push(result);
        }
    }
    double result = operandStack.top();
    while (!operandStack.empty())
    {
        operandStack.pop();
    }
    return Double2String(result);
}

string calulateMathPostfixAndPrefix(string input)
{
    if (isMathoperator(input[0]))
    {
        string tmp = MathChange(input);
        return PrefixCalculator(tmp);
    }
    else
        return PostfixCalculator(input);
}






bool LogicCalculate(string operation, bool operand1, bool operand2)
{
    if (operation == "->")
    {
        if (operand1 == 1 && operand2 == 0)
            return false;
        return true;
    }
    else if (operation == "<->")
    {
        if (operand1 != operand2)
            return false;
        return true;
    }
    else if (operation == "|")
    {
        if (operand1 == 0 && operand2 == 0)
            return 0;
        return 1;
    }
    else if (operation == "&")
    {
        if (operand1 == 1 && operand2 == 1)
            return 1;
        return 0;
    }
    else if (operation == "~")
    {
        if (operand1 == 1)
            return 0;
        return 1;
    }

    return 0;
}

string LogicChange(string &tmp)
{
    reverse(tmp.begin(), tmp.end());
    for (int i = 0; i < (int)(tmp.length()) - 2; i++)
    {
        if (tmp[i] == '>' && tmp[i + 1] == '-')
        {
            if (tmp[i + 2] == '<')
            {
                tmp.replace(i, 1, "<");
                tmp.replace(i + 1, 1, "-");
                tmp.replace(i + 2, 1, ">");
            }
            else
            {
                tmp.replace(i, 1, "-");
                tmp.replace(i + 1, 1, ">");
            }
        }
    }
    return tmp;
}

string PostfixCalculatorMath(string input, string varlue)
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
