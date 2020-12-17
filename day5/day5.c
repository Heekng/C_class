#include <stdio.h>

//함수선언
void swap(int* sw_pnum1, int* sw_pnum2);
int sum(int num1, int num2);
int main(int argc, char* argv[]) {
	char* month[] = { "January", "Freburary", "March" };
	char ch = 'A';//문자형

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
	printf("%c%c년도에 태어난 ", id[0], id[1]);
	if (id[6] == '1')
		printf("남자");
	else
		printf("여자");
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

	//주소가 들어갈 변수: 포인터 변수
	int* p_int_val1; //*이 포인터 변수라는 뜻
	//이 변수의 주소를 찾아 4바이트(int)를 읽으면 정수가 들어있다.
	double* p_double_val1; //8바이트를 읽는다.
	char* p_char_val1;

	//변수에 값을 넣기
	p_int_val1 = &int_val1;
	p_double_val1 = &double_val1;
	p_char_val1 = &char_val1;
	//일반변수안에 포인터 넣기 안됨
	//메모리의 주소는 어떤 자료를 담고 있느냐에 상관없이 무조건 8바이트(운영체제 64bit)이다.

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
	printf("%d\t", int_arr); //배열의 주소값은 배열의 0번인덱스 주소값과 같다.

	*/

	/*
	int a[5] = { 10, 20, 30, 40, 50 };
	//포인터 변수 선언
	int* ptr; //ptr변수는 포인터 변수라는 의미 *

	ptr = a; //포인터 변수에 배열 대입
	ptr = &a[3];//ptr = &a[0]

	ptr = ptr + 1;

	printf("주소: %d\t", ptr);
	printf("주소: %d\t", &a[3]);

	//ptr++;
	printf("ptr++: %d\n", *ptr); //포인터 변수의 주소를 찾아가면 그 안에 들어있는 값
	*/

	/*
	//포인터 변수의 선언
	int* ptr, * ptr_a;
	//문자 배열 선언 후 초기화
	int a[5] = { 10, 20, 30, 40, 50 };
	int ptr_v;

	//포인터 값 대입 후 출력
	ptr = a; //ptr = &a[0]
	printf("*ptr: %d \t ptr: %p \t address a: %p\n", *ptr, ptr, a);

	//ptr++후 출력
	ptr_a = ptr++; //ptr_a = ptr , ptr = ptr + 1
	printf("*ptr: %d \t ptr: %p \t ptr_a = ptr++ : %p\n", *ptr, ptr, ptr_a);

	//*ptr++후 출력
	ptr_v = *ptr++; //ptr_v = *ptr, ptr = ptr + 1;
	printf("*ptr: %d \t ptr: %p \t ptr_v: %d\n", *ptr, ptr, ptr_v);

	//(*ptr)++ 후 출력
	ptr_v = (*ptr)++;
	printf("*ptr: %d \t ptr: %p \t ptr_v = (*ptr)++ : %d\n", *ptr, ptr, ptr_v);
	*/

	/*
	int a = 10;
	int* pa;
	int** ppa;//이중 포인터 변수
	int*** pppa;

	pa = &a;
	ppa = &pa;
	pppa = &ppa;

	//10을 출력하기
	printf("%d %d %d %d\n", a, *pa, **ppa, ***pppa);
	//주소를 출력하기
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
	// * << 주소값이 나타내는 값, 
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
	char ch = 'A';//문자형

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
	printf("주소: %d %d \n", sw_pnum1, sw_pnum2);
	printf("값: %d %d \n", *sw_pnum1, *sw_pnum2);
	*/
	int tmp;
	tmp = *sw_pnum2;
	*sw_pnum2 = *sw_pnum1;
	*sw_pnum1 = tmp;
}
int sum(int num1, int num2) {
	return num1 + num2;
}