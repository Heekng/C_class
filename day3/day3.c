#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	int a = 0;
	int b = 1; //���� �Ǻ���ġ���� ��
	int c;
	int cnt = 1;
	int sum = 0;
	while (cnt <= 10) {
		sum += b;
		printf("%d %d\n", b, sum);
		c = a;
		a = b;
		b = a + c;
		cnt++;
	}

	/*
	int int_val1;
	int int_val2;

	printf("����1: ");
	scanf_s("%d", &int_val1);
	printf("����2: ");
	scanf_s("%d", &int_val2);

	printf("���� ����Ʈ ���� %d\n", int_val1 << int_val2); // 10 << 3 ==> 10 * 2^3
	printf("������ ����Ʈ ���� %d\n", int_val1 << int_val2); // 10 >> 3 ==> 10 / 2^3   50 / 2^2
	*/

	/*
	int num = 100;

	printf("%o\t %x", num, num);
	printf("%d", num << 2);
	printf("%d", num >> 3);
	*/

	/*
	//3�� ���� == ���Ǻ� ����
	int a = 20;
	int sa = 0;

	printf("%d", (a >= sa) ? a : sa);
	*/

	/*
	short short_val1;
	int int_val1 = 20;
	double double_val1 = 3.15;

	//short_val1 = (short) int_val1;
	//printf("%d", short_val1);

	//double_val1 = int_val1;
	//printf("%lf", double_val1);

	int_val1 = (int)double_val1;
	printf("%d", sizeof(int_val1));
	*/

	/*
	char char_val = 'a';
	short short_val = 10;
	long long_val = 10L;
	int int_val = 20;
	float float_val = 3.14f;
	double double_val = 3.15;

	printf("%d byte\n" sizeof(int_val));
	printf("%d byte\n" sizeof(short_val));
	printf("%d byte\n" sizeof(long_val));
	printf("%d byte\n" sizeof(int_val));
	printf("%d byte\n" sizeof(float_val));
	printf("%d byte\n" sizeof(double_val));
	*/

	/*
	//���� 2�� �Է�]
	//�հ谡 180�̻��̸� �հ� * 10% �����ؼ� ���
	//160�̻� 8%, 140�̻� 5%, �̸� ���� x
	int a, b, sum;
	float sum2;
	printf("1��° ���� �Է�(��, 100�� ����): ");
	scanf_s("%d", &a);
	printf("2��° ���� �Է�(��, 100�� ����): ");
	scanf_s("%d", &b);
	sum = a + b;


	if (sum >= 180) {
		sum2 = sum * 0.9;
	}
	else if (sum >= 160) {
		sum2 = sum * 0.92;
	}
	else if (sum >= 140) {
		sum2 = sum * 0.95;
	}
	else {
		sum2 = sum;
	}

	int result = sum / 10;
	switch (result) {
		case 20:
		case 19:
		case 18:sum2 = sum * 0.9;
			break;
		case 17:
		case 16:sum2 = sum * 0.92;
			break;
		case 15:
		case 14:sum2 = sum * 0.95;
			break;
		default:sum2 = sum;
			break;
	}
	printf("���: %d", (int)sum2);
	*/

	/*
	char ch;
	printf("�����Է�: ");
	scanf_s("%c", &ch);

	switch (ch) {
		case 'A':
		case 'a': printf("a�Դϴ�."); break;
		case 'B':
		case 'b': printf("b�Դϴ�."); break;
		case 'C':
		case 'c': printf("c�Դϴ�."); break;
		default: printf("�ƹ��͵� �ƴմϴ�.");
	}
	*/

	/*
	int a = 10;

	do {
		printf("a�� 100�� �ƴմϴ�. %d \n", a);
		a += 10;
	} while (a != 100);
	*/

	/*
		// 7��
		int n = 1;
		int sum = 1;
		printf("n sum\n");
		while (n <= 20){//������ 20
			sum *= n;
			printf("%d %d\n", n, sum);
			n++;
		}
		printf("������� %d �Դϴ�.\n\n", sum);

		//8��
		n = 1;
		int nn = 2;
		double sum2 = 0.0;
		printf("n  nn  sum\n");
		while (n <= 49) {
			sum2 += (double)n / nn;
			printf("%d %d %lf\n", n, nn, sum2);
			n++;
			nn++;
		}
		*/
	return 0;
}