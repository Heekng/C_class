#include <stdio.h>
#include <math.h>

int sum(int i, int j, int k); //�Լ��� ���� �����ϴ� �κ�
double avg(double i, double j, double k, double l);
int compute_sum(int i);
int pass(int number);
void main() {
	int age[2][3], i, j;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3; j++) {
			scanf_s("%d", &age[i][j]);
		}
	}





	/*
	int i = 0; //for������ ����(��) ����� ����: ÷�� ����(i, j, k, l, m, n)
	for (i = 0; i < 10; i++)
	{
		printf("%d \t", i);
	}
	*/

	/*
	//1~100 �ձ��ϱ�
	int i;
	int sum = 0;

	for (i = 1; i < 101; i++)
	{
		sum += i;
	}
	printf("1~100�� ��: %d", sum);
	*/

	/*
	//����� 1��
	int num, i, j;
	printf("�ڿ��� N�Է�: ");
	scanf_s("%d", &num);
	for (i = 0; i < num; i++) {
		for (j = 0; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
	*/

	/*
	//����� 2��
	int num, i, j;
	printf("�ڿ��� N�Է�: ");
	scanf_s("%d", &num);
	for (i = 0; i < num; i++) {
		for (j = 0; j < num - i-1; j++) {
			printf(" ");
		}
		for (j = 0; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
	*/

	/*
	//����� 3��
	int num, i, j;
	printf("�ڿ��� N�Է�: ");
	scanf_s("%d", &num);
	for (i = 0; i < num; i++) {
		for (j = 0; j < num - i; j++) {
			printf("*");
		}
		for (j = 0; j < i; j++) {
			printf(" ");
		}
		printf("\n");
	}
	*/

	/*
	//����� 4��
	int num, i, j;
	printf("�ڿ��� N�Է�: ");
	scanf_s("%d", &num);
	for (i = 0; i < num; i++) {
		for (j = 0; j < i; j++) {
			printf(" ");
		}
		for (j = 0; j < num - i; j++) {
			printf("*");
		}
		printf("\n");
	}
	*/

	/*
	//����� 5�� �̿ϼ�
	// (num - 1)/2 - ��-1 �� ���ʿ� ��������
	int num, i, j;
	printf("�ڿ��� N�Է�: ");
	scanf_s("%d", &num);
	for (i = 0; i < num; i++) {
		for (j = 0; j < (num - 1) / 2 - i+1; j++) {
			printf(" ");
		}
		for (j = 0; j < 1 + i * 2; j++) {
			printf("*");
		}
		for (j = 0; j < (num - 1) / 2 - i+1; j++) {
			printf(" ");
		}
		printf("\n");
	}

	/*
	int number1, number2, total;
	printf("���� 1 �Է� : ");
	scanf_s("%d", &number1);
	printf("���� 2 �Է� : ");
	scanf_s("%d", &number2);

	total = sum(number1, number2, 50); //�Լ� ȣ��
	double avg2 = avg(number1, number2, 70.25, 542.2);
	printf("����: %d\n", total);
	printf("�����: %lf", avg2);
	*/

	/*
	//1��
	int degree;
	double radian;
	double PI = 3.141592;
		for (degree = 0; degree <= 180; degree += 30) {
		radian = PI * degree / 180;
		printf("sin<%d> = %lf\n", degree, radian);
	}
		//2��
	int num;
	printf("���� ���� ���� �Է�: ");
	scanf_s("%d", &num);
	printf("1���� %d������ ���� %d�Դϴ�.\n\n", num, compute_sum(num));
		//3��
	int time;
	printf("�Ἦ�ð��� �Է��ϼ���.(����: �ð�): ");
	scanf_s("%d", &time);
	if (pass(time) == 1) {
		printf("�⼮ ����Ͽ����ϴ�.");
	}
	else {
		printf("������� ���߽��ϴ�.");
	}
	*/
	/*
	int age[5];
	double score[5];
	char ch[5], empty;
	int i, size;
	size = sizeof(age)/sizeof(int);
		for (i = 0; i < size; i++) {
		printf("����: ");
		scanf_s("%d", age[i]);
		printf("����: ");
		scanf_s("%lf", score[i]);
		scanf_s("%c", &empty);
		printf("����: ");
		scanf_s("%c", ch[i]);
	}
	for (i = 0; i < size; i++) {
		printf("%d\t%lf\t%c\n", age[i], score[i], ch[i]);
	}
	*/

	/*
	int age[] = {10, 20, 30, 40, 50, 60,70, 80};
	int i;
	for(i = 0; i < sizeof(age) / sizeof(int); i++) {
		printf("age[%d] = %d\t", i, age[i]);
	}
	*/
}

int sum(int i, int j, int k) {
	return i + j + k;
}

double avg(double i, double j, double k, double l) {
	return (i + j + k + l) / 4;
}

int compute_sum(int i) {
	int j;
	int sum = 0;
	for (j = 1; j <= i; j++)
	{
		sum += j;
	}
	return sum;
}

int pass(int number) {
	if (number < 6) {
		return 1;
	}
	else {
		return 0;
	}
}