#include <bits/stdc++.h>
#include <string> // Thêm dòng này để bao gồm tiêu đề cho lớp "string"

#include "calculate.h"

using namespace std;

int main()
{
    string math_infix;
    cout << "Nhap Math Infix: ";
    getline(cin, math_infix);

    string mathpostfix = convertInfixToPostfix(math_infix);
    string mathprefix = convertInfix2Prefix(math_infix);
    cout << "Math Postfix: " << mathpostfix << endl;
    cout << "Math Prefix: " << mathprefix << endl;
    cout << "Math Postfix Calculate: " << calulateMathPostfixAndPrefix(mathpostfix) << endl;
    cout << "Math Prefix Calculate: " << calulateMathPostfixAndPrefix(mathprefix) << endl;

    string logic_infix, varlue;
    cout << "Nhap Logic Infix: ";
    getline(cin, logic_infix);
    cout << "Nhap Logic Varlue: ";
    getline(cin, varlue);
    string logicpostfix = convertLogicInfix2LogicPostfix(logic_infix);
    string logicprefix = convertLogicInfix2LogicPrefix(logic_infix);
    cout << "Logic Postfix: " << logicpostfix << endl;
    cout << "Logic Prefix: " << logicprefix << endl;
    cout << "Logic Prefix Postfix Calculate: " << calculateLogicPostfixAndPrefix(logicpostfix, varlue) << endl;

    return 0;
}
