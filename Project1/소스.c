#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int numSum(int a, int b); //�Լ� ���� �����ϱ�
float numSum(float a, float b); //������ �̸��� �Լ� �����ε�

int main(int argc, char* argv[]) {

	float num = (float)numSum(3.7, 7.1); //�Լ� ȣ���ϱ�
	printf("�� ���� ���� %f !", num);
	
	return 0;
}

int numSum(int a, int b) { //�Լ� �����ϱ�
	int c = a + b;
	return c;
}
float numSum(float a, float b) { //������ �̸��� �Լ� �����ε�
	float c = a + b;
	return c;
}