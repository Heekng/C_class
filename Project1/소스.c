#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int numSum(int a, int b); //함수 원형 선언하기
float numSum(float a, float b); //동일한 이름의 함수 오버로드

int main(int argc, char* argv[]) {

	float num = (float)numSum(3.7, 7.1); //함수 호출하기
	printf("두 수의 합은 %f !", num);
	
	return 0;
}

int numSum(int a, int b) { //함수 선언하기
	int c = a + b;
	return c;
}
float numSum(float a, float b) { //동일한 이름의 함수 오버로드
	float c = a + b;
	return c;
}