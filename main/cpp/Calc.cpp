//
// Created by tobesoft on 2020-10-20.
//

//#include "header.h"
#include "Cal.h"
using namespace std;

void Cal::Calc()
{
    bool isthere = false; // 괄호유무

    cout << '\n' << "---계산시작---" << '\n' << '\n';

    if (v_op[0] == "+" || v_op[0] == "-" || v_op[0] == "/" || v_op[0] == "*")
    {
        cout << "처음에 연산자 사용불가" << endl;
        v_op.erase(v_op.begin() + 0);
        exit(0);
    }
    for (int i = 0; i < v_op.size(); i++)
    {
        //////////////////// 괄호 시작 ///////////////////////////
        if (v_op[i] == "(")
        { //괄호 시작

            for (int j = i + 1; j < v_op.size(); j++) //)만날때까지
            {
                if (v_op[j] == "(")
                {
                    cout << "괄호중첩 불가" << endl;
                    exit(0);
                }

                if (v_op[j] == ")") //괄호짝 맞음
                {
                    if (j != (i + 4)) //i+4에 ')'가 와야 (A+B)형식 맞출수있음
                    {
                        //괄호가 식에 안맞음
                        cout << "괄호 형식 맞추시오!" << endl;
                        exit(0);
                    }
                    isthere = true;
                    break;
                }
            }

            if (isthere == false) //괄호부조합시 ')'가 없음
            {
                cout << "괄호 형식 맞추시오!(부조합)" << endl;
                exit(0);
            }

            else //괄호 있다(조합)
            {
                int getNum = stoi(v_op[i + 1]); //string to int
                if (getNum == 0)
                { //getNum 이 0, 오류
                    cout << "괄호안에 입력된 문자를 다시 확인해주세요." << endl;
                    exit(0);
                }

                getNum = stoi(v_op[i + 3]); //string to int
                if (getNum == 0)
                { //getNum 이 0, 오류
                    cout << "괄호안에 입력된 문자를 다시 확인해주세요." << endl;
                    exit(0);
                }

                // 연산함수(v_op[i + 2]);
                int result = Operator(v_op[i + 2], stoi(v_op[i + 1]), stoi(v_op[i + 3]));
                v_op.erase(v_op.begin() + i, v_op.begin() + (i + 5)); //i ~ i+4 까지 지우기
                v_op.insert(v_op.begin() + i, to_string(result)); //해당자리에 위치 삽입
            }
        }
        ////////////////////////////////괄호 처리///////////////////////////////////
    }
    //Cal_Print();

    //---------------------------------계산처리--------------------------
    for (int i = 0; i < v_op.size(); i++)
    {
        if (v_op[i] == "/" || v_op[i] == "*") //우선순위 높음
        {
            int result = Operator(v_op[i], stoi(v_op[i - 1]), stoi(v_op[i + 1]));
            v_op.erase(v_op.begin() + (i - 1), v_op.begin() + (i + 2)); //i-1 ~ i+1 까지 지우기
            v_op.insert(v_op.begin() + (i - 1), to_string(result)); //해당자리에 위치 삽입
            i = 0;
        }
    }
    for (int i = 0; i < v_op.size(); i++)
    {
        if (v_op[i] == "+" || v_op[i] == "-") //우선순위 아래
        {
            int result = Operator(v_op[i], stoi(v_op[i - 1]), stoi(v_op[i + 1]));
            v_op.erase(v_op.begin() + (i - 1), v_op.begin() + (i + 2)); //i-1 ~ i+1 까지 지우기
            v_op.insert(v_op.begin() + (i - 1), to_string(result)); //해당자리에 위치 삽입
            i = 0;
        }
    }
    //-------------------------------완료-----------------------------------
}