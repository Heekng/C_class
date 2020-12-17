#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //���ڿ��� ���õ� �Լ�
#include <process.h> //�ü���� �ִ� pause, stop��ɾ� ���

#define _FILE_ "ADDRBOOK.dat"

//����ü ����
struct data {
	char cName[8];
	char cTel[16];
	char cAddr[32];
};

void SelOne(unsigned rsize, struct data* Book1); //�ڷ� �Է�
void SelTwo(unsigned rsize, struct data* Book2); //�ڷ� �˻�
void SelThree(unsigned rsize, struct data* Book2); //�ڷ� ����
void SelFour(unsigned rsize, struct data* Book2); //�ڷ� ����
void SelFive(unsigned rsize, struct data* Book2); //�ڷ� ��ȸ

int Cnt_data(unsigned rsize); //���ڵ��� �ο����� �����ִ� �Լ�

int main(int argc, char* argv[]) {
	char cBtn, cc;
	int Lec;
	unsigned rsize = sizeof(struct data); // 56byte
	struct data* Book1; //����ü�� �����ϱ� ���ؼ� �ʿ��� ���� Book1�Դϴ�. �׷��� �̰��� ������ ������ �� ��
	struct data* Book2; //����ü�� �ּ�!
	
	while (1) {
		//������ ���� ����, ���Ͽ� ����ִ� ���ڵ� ���� ����
		Lec = Cnt_data(rsize);
		Book1 = (struct data*)malloc(1 * sizeof(struct data));
		//malloc �����Ҵ�, 1�� ���ڵ� ���� �޸𸮸� Ȯ��
		Book2 = (struct data*)malloc(Lec * sizeof(struct data));
		//���� �ȿ� �������� ���ڵ带 ���� �޸� Ȯ��
		system("cls"); //process.h, cmdâ Ŀ��� ��ɾ��̸� ȭ���� Ŭ�����ϴ� �Լ��̴�.
		printf("����ü ũ��: %d\n", rsize);
		printf("������ ����: %d\n", Lec);

		if (Lec != 0) { //���Ͽ� �����Ͱ� �̹� �ִ� ���
			printf("1. �ڷ� �Է� \n");
			printf("2. �ڷ� �˻� \n");
			printf("3. �ڷ� ���� \n");
			printf("4. �ڷ� ���� \n");
			printf("5. �ڷ� ��ȸ \n");
			printf("0. ��	  �� \n");
			printf("�����ϼ��� : ");
			scanf_s("%c", &cBtn);
			
		}
		else {//���� ó�� �ƹ��͵� ���� ����
			cBtn = '1';
		}
		
		if (cBtn == '1') {
			system("cls");
			SelOne(rsize, Book1);
		}
		else if (cBtn == '2') {
			if (Lec == 0) {
				printf("�˻��� �����Ͱ� �����ϴ�\n");
				system("pause");
			}
			else {
				system("cls");
				SelTwo(rsize, Book2);
			}
		}
		else if (cBtn == '3') {
			if (Lec == 0) {
				printf("������ �����Ͱ� �����ϴ�\n");
				system("pause");
			}
			else {
				system("cls");
				SelThree(rsize, Book2);
			}
		}
		else if (cBtn == '4') {
			if (Lec == 0) {
				printf("������ �����Ͱ� �����ϴ�.\n");
				system("pause");
			}
			else {
				system("cls");
				SelFour(rsize, Book2);
			}
		}
		else if (cBtn == '5') {
			if (Lec == 0) {
				printf("��ȸ�� �����Ͱ� �����ϴ�\n");
				system("pause");
			}
			else {
				system("cls");
				SelFive(rsize, Book2);
			}
		}
		else if (cBtn == '0') {
			break;
		}
	}
	/*
	char word[5] = "abcde";
	char* word1 = "abc";
	int word_size = sizeof(word);
	int word1_size = sizeof(word1);

	printf("%d\t", word_size);
	printf("%d\t", word1_size);
	printf("%s\t", word);
	printf("%s\t", word1);
	*/
	return 0;
}

//���ڵ� ���� �����ִ� �Լ�
int Cnt_data(unsigned rsize) { //56
	int Cnt;
	FILE* fload; //fload��� ������ FILE�� ������ �����̴�.
	
	fload = fopen(_FILE_, "r");//�б������� r �������� w
	if (fload == NULL) {
		Cnt = 0;
	}
	else {
		fseek(fload, -1, SEEK_END);//fload��� �ּ��� -1����(ó��) ������ ã�Ƴ���.
		//�����ϸ� 0 �����ϸ� -1
		//fseek ��������ġ �����ϴ� �Լ�
		Cnt = (ftell(fload) / rsize) + 1;
		int a = ftell(fload)/rsize;
		//ftell ��Ʈ���� ���� ��ġ ���ϴ� �Լ�
		fclose(fload);
	}
	return Cnt;
}

void SelOne(unsigned rsize, struct data*Book1) { //�ڷ� �Է�
	FILE* fsave;

	fflush(stdin); //���۸� ����� �ʱ�ȭ�Ѵ�.
	printf("\n ��    ��[8��]: ");
	gets(Book1->cName); //Book1�� ����Ű�� cName�� �־����.
	printf("\n ��ȭ��ȣ[8��]: ");
	gets(Book1->cTel);
	printf("\n ��    ��[8��]: ");
	gets(Book1->cAddr);

	if (strlen(Book1->cName) < 1 || strlen(Book1->cTel) < 1 || strlen(Book1->cAddr) < 1) {
		printf("�ƹ��� �Է��� ���� �ּҷ��� �������� �ʾҽ��ϴ�.");
	}
	else {
		fsave = fopen(_FILE_, "a+");
		//a+: ������ ������ �����, �ִٸ� �߰�(appen), ����
		fwrite(Book1, rsize, 1, fsave); //����ϱ�
		//Book1(������� �������� �޸� ���� �ּ�, rsize������ũ�����, 1 ���� ����, fsave������ ����
		fclose(fsave);//�ݱ�
	}
	system("pause");
	
}
void SelTwo(unsigned rsize, struct data* Book2) { //�ڷ� �˻�
	int nNum, i;
	int Cnt = Cnt_data(rsize); //������(���ڵ�)���� �����ִ� �Լ� ȣ��
	FILE* fload;
	printf("�� %d���� �����Ͱ� �ֽ��ϴ�.\n", Cnt);
	printf("�� ��° �����͸� ��ȸ�Ͻðڽ��ϱ�?");
	scanf_s("%d", &nNum);

	fload = fopen(_FILE_, "r+"); //���� �б�
	fread(Book2, rsize, Cnt, fload);//���� ������ �����ϴ� �ּ�, ������ ũ�����, ���� ��������, ���� ����
	for (i = 0; i < Cnt; i++) {
		if (nNum - 1 == i) {
			printf("\n%d�� ° ������\n", i + 1);
			printf("��    ��: %s\n", (Book2 + i)->cName);
			printf("��ȭ��ȣ: %s\n", (Book2 + i)->cTel);
			printf("��    ��: %s\n", (Book2 + i)->cAddr);
		}
	}
	fclose(fload);
	system("pause");
}
void SelThree(unsigned rsize, struct data* Book2) { //�ڷ� ����
	int Cnt, i, nNum, temp = 0;
	FILE* fsave;
	FILE* fload;

	Cnt = Cnt_data(rsize);

	printf("�� %d���� �����Ͱ� �ֽ��ϴ�.\n", Cnt);
	printf("�� ��° �����͸� �����Ͻðڽ��ϱ�?");
	scanf_s("%d", &nNum);

	fload = fopen(_FILE_, "r+");
	fread(Book2, rsize, Cnt, fload);
	for (i = 0; i < Cnt; i++) {
		if (nNum - 1 == i) {
			printf("\n %d�� ° ������ \n", i + 1);
			fflush(stdin);
			rewind(stdin); // ���͸Ա�, �Ű����� ��Ʈ�� �ʱ�ȭ
			printf("��    ��: ");
			gets((Book2 + i)->cName);
			printf("��ȭ��ȣ: ");
			gets((Book2 + i)->cTel);
			printf("��    ��: ");
			gets((Book2 + i)->cAddr);
			if (strlen((Book2 + i)->cName) < 1 || strlen((Book2 + i)->cTel) < 1 || strlen((Book2 + i)->cAddr) < 1) {
				temp++;
			}
		}
	}
	if (temp > 0) {
		printf("�ƹ��� �Է��� ���� �ּҷ��� �������� �ʾҽ��ϴ�.");
	}else{
		fsave = fopen(_FILE_, "w+"); //�������Ϸ� ����
		fwrite(Book2, rsize * Cnt, 1, fsave);
		fclose(fsave);
	}
	fclose(fload);
	system("pause");
}
void SelFour(unsigned rsize, struct data* Book2) { //�ڷ� ����
	int i, j = 0;
	int nNum;
	char cYN;
	int Cnt = Cnt_data(rsize);
	FILE* fsave; //�б��
	FILE* fload; //�����
	printf("�� %d���� �����Ͱ� �ֽ��ϴ�.\n", Cnt);
	if (Cnt == 1) {
		printf("1���� �����͸� �����ϹǷ� ������ �Ұ����մϴ�.");
		fflush(stdin);
		printf("��� �����Ͻðڽ��ϱ�?(Y/N)");
		cYN = getchar();
		if (cYN == 'Y' || cYN == 'y') {
			_unlink(_FILE_);
		}
		else {
			printf("��ҵǾ����ϴ�.");
		}
	}
	else {
		while (1) {
			printf("�� ��° �����͸� �����Ͻðڽ��ϱ�?");
			scanf_s("%d", &nNum);
			if (nNum <= Cnt) break;
		}
		fload = fopen(_FILE_, "r+");
		fread(Book2, rsize, Cnt, fload);
		for (i = 0; i < Cnt; i++) {
			if (i != nNum - 1) {
				if (j == 0) fsave = fopen(_FILE_, "w+");
				else fsave = fopen(_FILE_, "a+");
				fwrite(Book2 + i, rsize, 1, fsave);
				fclose(fsave);
				j++;
			}
		}
		printf("�����Ͻ� ���ڵ尡 �����Ǿ����ϴ�.\n");
		fclose(fload);
	}
	system("pause");
}
void SelFive(unsigned rsize, struct data* Book2) { //�ڷ� ��ȸ
	int i;
	int Cnt = Cnt_data(rsize);
	FILE* fload;

	printf("�� %d���� �����Ͱ� �ֽ��ϴ�. ", Cnt);
	fload = fopen(_FILE_, "r+");
	fread(Book2, rsize, Cnt, fload);
	for (i = 0; i < Cnt; i++) {
		printf("\n %d�� ° ������ \n", i + 1);
		printf("��    ��: %s \n", (Book2 + i)->cName);
		printf("��ȭ��ȣ: %s \n", (Book2 + i)->cTel);
		printf("��    ��: %s \n", (Book2 + i)->cAddr);
	}
	fclose(fload);
	system("pause");
}