#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <process.h>

#define FLUSH fflush(stdin)

struct banking{

	char acct_no[10]; //���¹�ȣ
	char acct_name[10]; //���� ����
	int balance; //�ݾ�
};

int menu_disp();
void init(struct banking* init, struct banking* init_rcv); //�ʱ�ȭ�ϱ� ����ü�ȿ� ������ �ڷᰡ �ִٸ� ��� �����
void open(struct banking* popen, struct banking* prcv);
void input(struct banking* pinput);
void output(struct banking* output);
void transfer(struct banking* ptransfer, struct banking* prcv);
void check(struct banking* pcheck, struct banking* prcv);

int main(int argc, char* argv[]) {
	int choice;
	struct banking* account; //�߽� ����
	struct banking* rcv_acct; //���� ����

	account = (struct banking*)malloc(sizeof(struct banking));
	rcv_acct = (struct banking*)malloc(sizeof(struct banking));

	init(account, rcv_acct); //�ʱ�ȭ�ϱ� ����ü�ȿ� ������ �ڷᰡ �ִٸ� ��� �����
	while (1) {
		choice = menu_disp(); //�޴� ���̰� �ϴ� �Լ�
		switch (choice) {
		case 1: open(account, rcv_acct); break;//���� ���
		case 2: input(account); break; //�Ա�
		case 3: output(account); break; //���
		case 4: transfer(account, rcv_acct); break; //������ü
		case 5: check(account, rcv_acct); break; //�ܾ���ȸ
		case 9: exit(0);//�����ϱ�
		default: break;
		}
	}


	return 0;
}

int menu_disp() {
	int ch;
	system("cls");
	printf("1. ���� ��� \n");
	printf("2. ��     �� \n");
	printf("3. ��     �� \n");
	printf("4. ���� ��ü \n");
	printf("5. �ܾ� ��ȸ \n");
	printf("9. ��     �� \n");
	printf("���� [ ]\b\b"); //\b: �齺���̽�
	scanf_s("%d", &ch);
	return ch;
}

void init(struct banking* init, struct banking* init_rcv) {
	init->acct_no[1] = "";
	init->acct_name[0] = "";
	init->balance = 0;

	init_rcv->acct_no[0] = "";
	init_rcv->acct_name[0] = "";
	init_rcv->balance = 0;
}
void open(struct banking* popen, struct banking* prcv) {//�Ա�
	int tx_rx;

	printf("1. �߽� ���� ��� \n");
	printf("2. ���� ���� ��� \n");
	printf("���� [ ]\b\b");
	scanf_s("%d", &tx_rx);
	rewind(stdin);
	if (tx_rx == 1) {
		printf("���� ��ȣ (10)�� �̳�: "); FLUSH; gets(popen->acct_no);
		printf("���� ���� (10)�� �̳�: "); FLUSH; gets(popen->acct_name);
	}
	else if(tx_rx == 2){
		printf("���� ��ȣ (10)�� �̳�: "); FLUSH; gets(prcv->acct_no);
		printf("���� ���� (10)�� �̳�: "); FLUSH; gets(prcv->acct_name);
	}

	FLUSH;
	rewind(stdin);
	printf("ù �ŷ� �����մϴ�. "); 
	printf(" Press any key to continue...");
	getchar();
}
void input(struct banking* pinput) {
	char temp_acct_no[10];
	int result, money;
	printf("��/����� �߽� ���¿����� �����մϴ�. \n");
	printf("���¹�ȣ [10�� �̳�] : ");
	scanf(" %s", temp_acct_no);
	//�ΰ� �ڷ� ���ؼ� ������ 0�� ����
	result = strcmp(pinput->acct_no, temp_acct_no);
	if (result == 0) {
		printf("�Ա��� �ݾ� : ");
		scanf("%d", &money);
		pinput->balance = pinput->balance + money;
	}
	else {
		printf("��ġ�ϴ� ���¹�ȣ�� �����ϴ�.");
		
	}
	FLUSH;
	rewind(stdin);
	printf("... Press any key continue...");
	getchar();
}
void output(struct banking* output) {
	char temp_acct_no[10];
	int result, money;
	printf("��/����� �߽� ���¿����� �����մϴ�. \n");
	printf("����� ���¹�ȣ[10�� �̳�]: ");
	scanf(" %s", temp_acct_no);
	result = strcmp(output->acct_no, temp_acct_no);
	if (result == 0) {
		printf("����� �ݾ� : ");
		scanf("%d", &money);
		if (money > output->balance) {
			printf("�ܾ��� �����մϴ�..");
		}
		else {
			output->balance = output->balance - money;
			printf("%d�� ��ݵǾ����ϴ�.", money);
		}
	}
	else {
		printf("��ġ�ϴ� ���¹�ȣ�� �����ϴ�.");
	}
	FLUSH;
	rewind(stdin);
	printf("...Press any key continue...");
	getchar();
}
void transfer(struct banking* ptransfer, struct banking* prcv) {
	char temp1_acct_no[10], temp2_acct_no[10];
	int money, result1, result2;

	printf("������ ���� ��ȣ : ");
	scanf_s("%s", temp1_acct_no);
	printf("���� ���� ��ȣ : ");
	scanf_s("%s", temp2_acct_no);
	

	result1 = strcmp(ptransfer->acct_no, temp1_acct_no);
	result2 = strcmp(prcv->acct_no, temp2_acct_no);
	if (result1 == 0 && result2 == 0) {
		printf("��ü�� �ݾ� : ");
		scanf_s("%d", &money);
		if (ptransfer->balance >= money) {
			ptransfer->balance -= money;
			prcv->balance += money;
			printf("�߽� ���¹�ȣ : %s�� �ܾ��� %d �� �ֽ��ϴ�. \n", ptransfer->acct_no, ptransfer->balance);
			printf("���� ���¹�ȣ : %s�� �ܾ��� %d �� �ֽ��ϴ�. ", prcv->acct_no, prcv->balance);
		}
		else {
			printf("�ܾ��� �����Ͽ� ��ü �Ұ��մϴ�.");
		}
	}
	else {
		printf("���¹�ȣ�� Ȯ�����ּ���.");
	}
	FLUSH;
	rewind(stdin);
	printf("... Press any key continue...");
	getchar;
}
void check(struct banking* pcheck, struct banking* prcv) {
	char temp_acct_no[10];
	int result, match = 0;
	printf("���� ��ȣ : ");
	scanf("%s", temp_acct_no);
	result = strcmp(pcheck->acct_no, temp_acct_no);


	if (result == 0) {
		printf("���� ��ȣ : %s", pcheck->acct_no);
		printf("���� ���� : %s", pcheck->acct_name);
		printf("��     �� : %d", pcheck->balance);
		match = 1;
	}

	result = strcmp(pcheck->acct_no, temp_acct_no);

	if (result == 0) {
		printf("���� ��ȣ : %s", prcv->acct_no);
		printf("���� ���� : %s", prcv->acct_name);
		printf("��     �� : %d", prcv->balance);
		match = 1;
	}
	if (match == 0)
		printf("���¹�ȣ ���� �Դϴ�.");
	FLUSH;
	rewind(stdin);
	printf("...Press any key to continue...");
	getchar();
}