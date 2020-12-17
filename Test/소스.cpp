#include <stdio.h>

//void : 반환값이 없다.
//int, char, float: 얘네를 리턴할거다. 그러니까return 값 이거 써라
void hello(char a[]) {
	printf("안녕? %s!!", a);
}

int main() {
	//char a[] = "연대생"; //배열
	char name[] = "이재혁";
	hello(name);

	return 0;
}
