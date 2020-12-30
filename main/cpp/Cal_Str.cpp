//
// Created by tobesoft on 2020-10-20.
//

#include "header.h"
#include "Cal.h"
using namespace std;

void Cal::Cal_Str()
{
    //Cal_Input(); //입력
    int arr_len = arr.length();// 길이
    int number = 0; //숫자 최종추출값
    int number_last; //마지막 위치
    int ten; //자릿수 계산 변수(10단위)

    for (int i = 0; i < arr_len; i++)
    {
        if (arr[i] >= 48 && arr[i] <= 57) //정수로 변환했을때 1~9 이하 즉, 숫자이면 tree구조에 삽입
        {
            ten = 1; //초기화
            number = 0; //초기화

            for (int j = i; arr[j] >= 48 && arr[j] <= 57; j++) //숫자 아닐때까지 반복
            {
                number_last = j;
            }
            for (int j = number_last; j >= i; j--)
            {
                number = number + (ten*(arr[j] - 48)); //최종 정수값 구하기
                ten *= 10; //곱해주기
            }

            i = number_last; //숫자마지막위치 저장
            string getNum = to_string(number);
            this->Cal_Stack(getNum);
        }

        else if (arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/' || arr[i] == '(' || arr[i] == ')')
        {
            string getch(1, arr[i]); //char형 얻기
            this->Cal_Stack(getch);
        }

        else //그 밖의 문자들 알파벳이나 특이숫자
        {
            cout << "입력 문자를 재확인하세요" << endl;
            exit(0);
        }

    }
}