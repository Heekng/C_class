#include <stdio.h>

//�Լ�����
void swap(int* sw_pnum1, int* sw_pnum2);
int sum(int num1, int num2);
int main(int argc, char* argv[]) {
	char* month[] = { "January", "Freburary", "March" };
	char ch = 'A';//������

	char* pch, ** ppch;

	pch = &ch;
	ppch = &pch;

	printf("ch : %c *pch : %c **ppch : %c\n", ch, *pch, **ppch);

	ppch = month;

	printf("*(pch+0) : %s\n", *(ppch + 0));
	printf("*(pch+1) : %s\n", *(ppch + 1));
	printf("*(pch+2) : %s\n", *(ppch + 2));

	/*
	int matrix[][3] = { 1, 2, 3, 4, 5, 6 };
	int i, j;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d \t", matrix[i][j]);
		}
		printf("\n");
	}
	*/

	/*
	char id[14] = "9011032683231";
	printf("%c%c�⵵�� �¾ ", id[0], id[1]);
	if (id[6] == '1')
		printf("����");
	else
		printf("����");
	*/

	/*
	char city[4][6] = { "seoul", "busan", "daegu", "ulsan" };
	char city_kor[4][5];
	int i, j, row_size, col_size;
	row_size = sizeof(city)/sizeof(city[6]);
	col_size = sizeof(city[6]);
	for (i = 0; i < row_size; i++) {
		for (j = 0; j < col_size; j++) {
			printf("%c", city[i][j]);
		}
		printf("\t");
	}
	*/

	/*
	int int_val1 = 10;
	double double_val1 = 3.14;
	char char_val1 = 'a';
	int int_arr[5] = { 1, 2, 3, 4, 5 };

	//�ּҰ� �� ����: ������ ����
	int* p_int_val1; //*�� ������ ������� ��
	//�� ������ �ּҸ� ã�� 4����Ʈ(int)�� ������ ������ ����ִ�.
	double* p_double_val1; //8����Ʈ�� �д´�.
	char* p_char_val1;

	//������ ���� �ֱ�
	p_int_val1 = &int_val1;
	p_double_val1 = &double_val1;
	p_char_val1 = &char_val1;
	//�Ϲݺ����ȿ� ������ �ֱ� �ȵ�
	//�޸��� �ּҴ� � �ڷḦ ��� �ִ��Ŀ� ������� ������ 8����Ʈ(�ü�� 64bit)�̴�.

	printf("%d %d\n", &int_val1, p_int_val1);
	printf("%d %d\n", sizeof(&int_val1), sizeof(p_int_val1));
	printf("%d %d\n", &double_val1, p_double_val1);
	printf("%d %d\n", sizeof(&double_val1), sizeof(p_double_val1));
	printf("%d %d\n", &char_val1, p_char_val1);
	printf("%d %d\n", sizeof(&char_val1), sizeof(p_char_val1));

	printf("%d\t", &int_arr[0]);
	printf("%d\t", &int_arr[1]);
	printf("%d\t", &int_arr[2]);
	printf("%d\t", &int_arr[3]);
	printf("%d\t", &int_arr[4]);
	printf("%d\t", int_arr); //�迭�� �ּҰ��� �迭�� 0���ε��� �ּҰ��� ����.

	*/

	/*
	int a[5] = { 10, 20, 30, 40, 50 };
	//������ ���� ����
	int* ptr; //ptr������ ������ ������� �ǹ� *

	ptr = a; //������ ������ �迭 ����
	ptr = &a[3];//ptr = &a[0]

	ptr = ptr + 1;

	printf("�ּ�: %d\t", ptr);
	printf("�ּ�: %d\t", &a[3]);

	//ptr++;
	printf("ptr++: %d\n", *ptr); //������ ������ �ּҸ� ã�ư��� �� �ȿ� ����ִ� ��
	*/

	/*
	//������ ������ ����
	int* ptr, * ptr_a;
	//���� �迭 ���� �� �ʱ�ȭ
	int a[5] = { 10, 20, 30, 40, 50 };
	int ptr_v;

	//������ �� ���� �� ���
	ptr = a; //ptr = &a[0]
	printf("*ptr: %d \t ptr: %p \t address a: %p\n", *ptr, ptr, a);

	//ptr++�� ���
	ptr_a = ptr++; //ptr_a = ptr , ptr = ptr + 1
	printf("*ptr: %d \t ptr: %p \t ptr_a = ptr++ : %p\n", *ptr, ptr, ptr_a);

	//*ptr++�� ���
	ptr_v = *ptr++; //ptr_v = *ptr, ptr = ptr + 1;
	printf("*ptr: %d \t ptr: %p \t ptr_v: %d\n", *ptr, ptr, ptr_v);

	//(*ptr)++ �� ���
	ptr_v = (*ptr)++;
	printf("*ptr: %d \t ptr: %p \t ptr_v = (*ptr)++ : %d\n", *ptr, ptr, ptr_v);
	*/

	/*
	int a = 10;
	int* pa;
	int** ppa;//���� ������ ����
	int*** pppa;

	pa = &a;
	ppa = &pa;
	pppa = &ppa;

	//10�� ����ϱ�
	printf("%d %d %d %d\n", a, *pa, **ppa, ***pppa);
	//�ּҸ� ����ϱ�
	printf("%d %d\n", &a, ***pppa);
	*/

	/*
	int num1 = 10, num2 = 20;
	int* ptr1 = &num1, *ptr2 = &num2;

	int** dptr1 = &ptr1, ** dptr2 = &ptr2;
	
	int sum;

	sum = num1 + num2;
	printf("%d\t", sum);
	sum = *ptr1 + num2;
	printf("%d\t", sum);
	sum = num1 + *ptr2;
	printf("%d\t", sum);
	sum = *ptr1 + *ptr2;
	printf("%d\t", sum);

	sum = **dptr1 + **dptr2;
	printf("%d\t", sum);
	*/
	
	/*
	int num1 = 10, num2 = 20, total;
	int* ptr1 = &num1, * ptr2 = &num2;

	swap(ptr1, ptr2);
	printf("%d %d", num1, num2);

	total = sum(num1, num2);
	printf("\n %d", total);
	*/

	/*
	// * << �ּҰ��� ��Ÿ���� ��, 
	int a[5] = { 10, 20, 30, 40,50};
	int* pa = a;
	int i;
	for (i = 0; i < sizeof(a)/sizeof(int); i++) {
		printf("%d %d\n", a[i], *(pa + i));
	}
	*/

	/*
	char *name[5] = {"memory", "cpu", "main board", "hdd", "mouse"};
	printf("%d\t", name[0]);
	printf("%d\t", name[1]);
	printf("%d\t", name[2]);
	printf("%d\t", name[3]);
	printf("%d\n", name[4]);

	
	printf("%s\t", name[0]);
	printf("%s\t", name[1]);
	printf("%s\t", name[2]);
	printf("%s\t", name[3]);
	printf("%s\t", name[4]);
	*/

	/*
	char* month[] = { "January", "Freburary", "March" };
	char ch = 'A';//������

	char* pch, ** ppch;

	pch = &ch;
	ppch = &pch;

	printf("ch : %c *pch : %c **ppch : %c\n", ch, *pch, **ppch);

	ppch = month;

	printf("*(pch+0) : %s\n", *(ppch + 0));
	printf("*(pch+1) : %s\n", *(ppch + 1));
	printf("*(pch+2) : %s\n", *(ppch + 2));
	*/
return 0;
}
void swap(int *sw_pnum1, int *sw_pnum2) {
	/*
	printf("�ּ�: %d %d \n", sw_pnum1, sw_pnum2);
	printf("��: %d %d \n", *sw_pnum1, *sw_pnum2);
	*/
	int tmp;
	tmp = *sw_pnum2;
	*sw_pnum2 = *sw_pnum1;
	*sw_pnum1 = tmp;
}
int sum(int num1, int num2) {
	return num1 + num2;
}