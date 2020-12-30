//
// Created by tobesoft on 2020-10-20.
//

#include "header.h"
#include "Cal.h"
using namespace std;

int Cal::Operator(string getOper, int num1, int num2)
{
    int result; //조합 계산결과값 저장

    if (getOper == "*")
    {
        result = num1 * num2;
    }
    if (getOper == "/")
    {
        result = num1 / num2;
    }
    if (getOper == "+")
    {
        result = num1 + num2;
    }
    if (getOper == "-")
    {
        result = num1 - num2;
    }

    return result;
}