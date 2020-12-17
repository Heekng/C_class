#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <process.h>

#define FLUSH fflush(stdin)

struct banking{

	char acct_no[10]; //계좌번호
	char acct_name[10]; //계좌 성명
	int balance; //금액
};

int menu_disp();
void init(struct banking* init, struct banking* init_rcv); //초기화하기 구조체안에 기존의 자료가 있다면 모두 지우기
void open(struct banking* popen, struct banking* prcv);
void input(struct banking* pinput);
void output(struct banking* output);
void transfer(struct banking* ptransfer, struct banking* prcv);
void check(struct banking* pcheck, struct banking* prcv);

int main(int argc, char* argv[]) {
	int choice;
	struct banking* account; //발신 계좌
	struct banking* rcv_acct; //수신 계좌

	account = (struct banking*)malloc(sizeof(struct banking));
	rcv_acct = (struct banking*)malloc(sizeof(struct banking));

	init(account, rcv_acct); //초기화하기 구조체안에 기존의 자료가 있다면 모두 지우기
	while (1) {
		choice = menu_disp(); //메뉴 보이게 하는 함수
		switch (choice) {
		case 1: open(account, rcv_acct); break;//계좌 등록
		case 2: input(account); break; //입금
		case 3: output(account); break; //출금
		case 4: transfer(account, rcv_acct); break; //계좌이체
		case 5: check(account, rcv_acct); break; //잔액조회
		case 9: exit(0);//종료하기
		default: break;
		}
	}


	return 0;
}

int menu_disp() {
	int ch;
	system("cls");
	printf("1. 계좌 등록 \n");
	printf("2. 입     금 \n");
	printf("3. 출     금 \n");
	printf("4. 계좌 이체 \n");
	printf("5. 잔액 조회 \n");
	printf("9. 종     료 \n");
	printf("선택 [ ]\b\b"); //\b: 백스페이스
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
void open(struct banking* popen, struct banking* prcv) {//입금
	int tx_rx;

	printf("1. 발신 계좌 등록 \n");
	printf("2. 수신 계좌 등록 \n");
	printf("선택 [ ]\b\b");
	scanf_s("%d", &tx_rx);
	rewind(stdin);
	if (tx_rx == 1) {
		printf("계좌 번호 (10)자 이내: "); FLUSH; gets(popen->acct_no);
		printf("계좌 성명 (10)자 이내: "); FLUSH; gets(popen->acct_name);
	}
	else if(tx_rx == 2){
		printf("계좌 번호 (10)자 이내: "); FLUSH; gets(prcv->acct_no);
		printf("계좌 성명 (10)자 이내: "); FLUSH; gets(prcv->acct_name);
	}

	FLUSH;
	rewind(stdin);
	printf("첫 거래 감사합니다. "); 
	printf(" Press any key to continue...");
	getchar();
}
void input(struct banking* pinput) {
	char temp_acct_no[10];
	int result, money;
	printf("입/출금은 발신 계좌에서만 가능합니다. \n");
	printf("게좌번호 [10자 이내] : ");
	scanf(" %s", temp_acct_no);
	//두개 자료 비교해서 같으면 0을 리턴
	result = strcmp(pinput->acct_no, temp_acct_no);
	if (result == 0) {
		printf("입금할 금액 : ");
		scanf("%d", &money);
		pinput->balance = pinput->balance + money;
	}
	else {
		printf("일치하는 계좌번호가 없습니다.");
		
	}
	FLUSH;
	rewind(stdin);
	printf("... Press any key continue...");
	getchar();
}
void output(struct banking* output) {
	char temp_acct_no[10];
	int result, money;
	printf("입/출금은 발신 계좌에서만 가능합니다. \n");
	printf("출금할 계좌번호[10자 이내]: ");
	scanf(" %s", temp_acct_no);
	result = strcmp(output->acct_no, temp_acct_no);
	if (result == 0) {
		printf("출금할 금액 : ");
		scanf("%d", &money);
		if (money > output->balance) {
			printf("잔액이 부족합니다..");
		}
		else {
			output->balance = output->balance - money;
			printf("%d원 출금되었습니다.", money);
		}
	}
	else {
		printf("일치하는 계좌번호가 없습니다.");
	}
	FLUSH;
	rewind(stdin);
	printf("...Press any key continue...");
	getchar();
}
void transfer(struct banking* ptransfer, struct banking* prcv) {
	char temp1_acct_no[10], temp2_acct_no[10];
	int money, result1, result2;

	printf("보내는 계좌 번호 : ");
	scanf_s("%s", temp1_acct_no);
	printf("받을 계좌 번호 : ");
	scanf_s("%s", temp2_acct_no);
	

	result1 = strcmp(ptransfer->acct_no, temp1_acct_no);
	result2 = strcmp(prcv->acct_no, temp2_acct_no);
	if (result1 == 0 && result2 == 0) {
		printf("이체할 금액 : ");
		scanf_s("%d", &money);
		if (ptransfer->balance >= money) {
			ptransfer->balance -= money;
			prcv->balance += money;
			printf("발신 계좌번호 : %s의 잔액은 %d 원 있습니다. \n", ptransfer->acct_no, ptransfer->balance);
			printf("수신 계좌번호 : %s의 잔액은 %d 원 있습니다. ", prcv->acct_no, prcv->balance);
		}
		else {
			printf("잔액이 부족하여 이체 불가합니다.");
		}
	}
	else {
		printf("계좌번호를 확인해주세요.");
	}
	FLUSH;
	rewind(stdin);
	printf("... Press any key continue...");
	getchar;
}
void check(struct banking* pcheck, struct banking* prcv) {
	char temp_acct_no[10];
	int result, match = 0;
	printf("게좌 번호 : ");
	scanf("%s", temp_acct_no);
	result = strcmp(pcheck->acct_no, temp_acct_no);


	if (result == 0) {
		printf("계좌 번호 : %s", pcheck->acct_no);
		printf("계좌 성명 : %s", pcheck->acct_name);
		printf("금     액 : %d", pcheck->balance);
		match = 1;
	}

	result = strcmp(pcheck->acct_no, temp_acct_no);

	if (result == 0) {
		printf("계좌 번호 : %s", prcv->acct_no);
		printf("계좌 성명 : %s", prcv->acct_name);
		printf("금     액 : %d", prcv->balance);
		match = 1;
	}
	if (match == 0)
		printf("계좌번호 오류 입니다.");
	FLUSH;
	rewind(stdin);
	printf("...Press any key to continue...");
	getchar();
}