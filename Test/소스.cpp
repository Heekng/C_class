#include <stdio.h>

//void : ��ȯ���� ����.
//int, char, float: ��׸� �����ҰŴ�. �׷��ϱ�return �� �̰� ���
void hello(char a[]) {
	printf("�ȳ�? %s!!", a);
}

int main() {
	//char a[] = "�����"; //�迭
	char name[] = "������";
	hello(name);

	return 0;
}
