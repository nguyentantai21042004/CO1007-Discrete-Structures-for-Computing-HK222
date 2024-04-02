#include <bits/stdc++.h>
#include <string> // Thêm dòng này để bao gồm tiêu đề cho lớp "string"

using namespace std;

#ifndef __CALCULATE_H__
#define __MATH_H__

bool isMathoperator(char c);
int onMathpredence(char c);

bool checkMathPostfixPredence(char a, char b);
string convertInfixToPostfix(string infix);

bool checkMathPrefixPredence(char a, char b);
string convertInfix2Prefix(string infix);

string Double2String(double number);
string MathChange(string &tmp);
double MathCalculate(char operation, double operand1, double operand2);
string PostfixCalculatorMath(string input);
string PrefixCalculator(string input);
string calulateMathPostfixAndPrefix(string input);

bool isLogicoperator(char c);
int onLogicpredence(string op);
bool checkLogicPostfixPredence(string a, string b);
string convertLogicInfix2LogicPostfix(string infix);

bool checkLogicPrefixPredence(string a, string b);
string convertLogicInfix2LogicPrefix(string infix);

bool LogicCalculate(string operation, bool operand1, bool operand2);
string LogicChange(string &tmp);
string PostfixCalculatorMath(string input, string varlue);
string calculateLogicPostfixAndPrefix(string input, string varlue);
#endif