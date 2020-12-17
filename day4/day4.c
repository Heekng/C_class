#include <stdio.h>
#include <math.h>

int sum(int i, int j, int k); //함수의 구조 선언하는 부분
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
	int i = 0; //for문에서 임의(시) 사용할 변수: 첨자 변수(i, j, k, l, m, n)
	for (i = 0; i < 10; i++)
	{
		printf("%d \t", i);
	}
	*/

	/*
	//1~100 합구하기
	int i;
	int sum = 0;

	for (i = 1; i < 101; i++)
	{
		sum += i;
	}
	printf("1~100의 합: %d", sum);
	*/

	/*
	//별찍기 1번
	int num, i, j;
	printf("자연수 N입력: ");
	scanf_s("%d", &num);
	for (i = 0; i < num; i++) {
		for (j = 0; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
	*/

	/*
	//별찍기 2번
	int num, i, j;
	printf("자연수 N입력: ");
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
	//별찍기 3번
	int num, i, j;
	printf("자연수 N입력: ");
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
	//별찍기 4번
	int num, i, j;
	printf("자연수 N입력: ");
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
	//별찍기 5번 미완성
	// (num - 1)/2 - 행-1 가 양쪽에 공백으로
	int num, i, j;
	printf("자연수 N입력: ");
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
	printf("정수 1 입력 : ");
	scanf_s("%d", &number1);
	printf("정수 2 입력 : ");
	scanf_s("%d", &number2);

	total = sum(number1, number2, 50); //함수 호출
	double avg2 = avg(number1, number2, 70.25, 542.2);
	printf("합은: %d\n", total);
	printf("평균은: %lf", avg2);
	*/

	/*
	//1번
	int degree;
	double radian;
	double PI = 3.141592;
		for (degree = 0; degree <= 180; degree += 30) {
		radian = PI * degree / 180;
		printf("sin<%d> = %lf\n", degree, radian);
	}
		//2번
	int num;
	printf("합을 구할 정수 입력: ");
	scanf_s("%d", &num);
	printf("1부터 %d까지의 합은 %d입니다.\n\n", num, compute_sum(num));
		//3번
	int time;
	printf("결석시간을 입력하세요.(단위: 시간): ");
	scanf_s("%d", &time);
	if (pass(time) == 1) {
		printf("출석 통과하였습니다.");
	}
	else {
		printf("통과하지 못했습니다.");
	}
	*/
	/*
	int age[5];
	double score[5];
	char ch[5], empty;
	int i, size;
	size = sizeof(age)/sizeof(int);
		for (i = 0; i < size; i++) {
		printf("나이: ");
		scanf_s("%d", age[i]);
		printf("점수: ");
		scanf_s("%lf", score[i]);
		scanf_s("%c", &empty);
		printf("문자: ");
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