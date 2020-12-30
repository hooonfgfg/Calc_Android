//
// Created by tobesoft on 2020-10-20.
//

#ifndef MY_APPLICATION_CAL_H
#define MY_APPLICATION_CAL_H

#endif //MY_APPLICATION_CAL_H
//#include <string>
#include "header.h"

class Cal
{
private:
    vector<string> v_op; //문자열 벡터
    string arr; //스트링

public:
    Cal() { v_op.clear(); } //자동 초기화
    ~Cal() { v_op.clear(); }

    void Cal_Stack(string op) { v_op.push_back(op); } //스택
    void Cal_Set(string arr){this->arr=arr;}
    string Cal_return(){return v_op[0];}

    void Cal_Str(); //문자열
    void Calc(); //계산
    int Operator(string getOper, int num1, int num2);
};