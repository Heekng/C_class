#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //문자열에 관련된 함수
#include <process.h> //운영체제에 있는 pause, stop명령어 사용

#define _FILE_ "ADDRBOOK.dat"

//구조체 선언
struct data {
	char cName[8];
	char cTel[16];
	char cAddr[32];
};

void SelOne(unsigned rsize, struct data* Book1); //자료 입력
void SelTwo(unsigned rsize, struct data* Book2); //자료 검색
void SelThree(unsigned rsize, struct data* Book2); //자료 수정
void SelFour(unsigned rsize, struct data* Book2); //자료 삭제
void SelFive(unsigned rsize, struct data* Book2); //자료 조회

int Cnt_data(unsigned rsize); //레코드의 인원수를 세어주는 함수

int main(int argc, char* argv[]) {
	char cBtn, cc;
	int Lec;
	unsigned rsize = sizeof(struct data); // 56byte
	struct data* Book1; //구조체에 접근하기 위해서 필요한 변수 Book1입니다. 그런데 이것을 포인터 변수로 쓴 것
	struct data* Book2; //구조체의 주소!
	
	while (1) {
		//데이터 갯수 세기, 파일에 들어있는 레코드 갯수 세기
		Lec = Cnt_data(rsize);
		Book1 = (struct data*)malloc(1 * sizeof(struct data));
		//malloc 동적할당, 1개 레코드 넣을 메모리를 확보
		Book2 = (struct data*)malloc(Lec * sizeof(struct data));
		//파일 안에 여러개의 레코드를 넣을 메모리 확보
		system("cls"); //process.h, cmd창 커멘드 명령어이며 화면을 클리어하는 함수이다.
		printf("구조체 크기: %d\n", rsize);
		printf("데이터 개수: %d\n", Lec);

		if (Lec != 0) { //파일에 데이터가 이미 있는 경우
			printf("1. 자료 입력 \n");
			printf("2. 자료 검색 \n");
			printf("3. 자료 수정 \n");
			printf("4. 자료 삭제 \n");
			printf("5. 자료 조회 \n");
			printf("0. 종	  료 \n");
			printf("선택하세요 : ");
			scanf_s("%c", &cBtn);
			
		}
		else {//가장 처음 아무것도 없는 상태
			cBtn = '1';
		}
		
		if (cBtn == '1') {
			system("cls");
			SelOne(rsize, Book1);
		}
		else if (cBtn == '2') {
			if (Lec == 0) {
				printf("검색할 데이터가 없습니다\n");
				system("pause");
			}
			else {
				system("cls");
				SelTwo(rsize, Book2);
			}
		}
		else if (cBtn == '3') {
			if (Lec == 0) {
				printf("수정할 데이터가 없습니다\n");
				system("pause");
			}
			else {
				system("cls");
				SelThree(rsize, Book2);
			}
		}
		else if (cBtn == '4') {
			if (Lec == 0) {
				printf("삭제할 데이터가 없습니다.\n");
				system("pause");
			}
			else {
				system("cls");
				SelFour(rsize, Book2);
			}
		}
		else if (cBtn == '5') {
			if (Lec == 0) {
				printf("조회할 데이터가 없습니다\n");
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

//레코드 갯수 세어주는 함수
int Cnt_data(unsigned rsize) { //56
	int Cnt;
	FILE* fload; //fload라는 변수는 FILE의 포인터 변수이다.
	
	fload = fopen(_FILE_, "r");//읽기전용모드 r 쓰기전용 w
	if (fload == NULL) {
		Cnt = 0;
	}
	else {
		fseek(fload, -1, SEEK_END);//fload라는 주소의 -1부터(처음) 끝까지 찾아내라.
		//성공하면 0 실패하면 -1
		//fseek 포인터위치 설정하는 함수
		Cnt = (ftell(fload) / rsize) + 1;
		int a = ftell(fload)/rsize;
		//ftell 스트림의 현재 위치 구하는 함수
		fclose(fload);
	}
	return Cnt;
}

void SelOne(unsigned rsize, struct data*Book1) { //자료 입력
	FILE* fsave;

	fflush(stdin); //버퍼를 비워서 초기화한다.
	printf("\n 이    름[8자]: ");
	gets(Book1->cName); //Book1이 가리키는 cName에 넣어줘라.
	printf("\n 전화번호[8자]: ");
	gets(Book1->cTel);
	printf("\n 주    소[8자]: ");
	gets(Book1->cAddr);

	if (strlen(Book1->cName) < 1 || strlen(Book1->cTel) < 1 || strlen(Book1->cAddr) < 1) {
		printf("아무런 입력이 없어 주소록을 수정하지 않았습니다.");
	}
	else {
		fsave = fopen(_FILE_, "a+");
		//a+: 파일이 없으면 만들고, 있다면 추가(appen), 열기
		fwrite(Book1, rsize, 1, fsave); //사용하기
		//Book1(쓰고싶은 데이터의 메모리 시작 주소, rsize데이터크기단위, 1 단위 개수, fsave저장할 내용
		fclose(fsave);//닫기
	}
	system("pause");
	
}
void SelTwo(unsigned rsize, struct data* Book2) { //자료 검색
	int nNum, i;
	int Cnt = Cnt_data(rsize); //데이터(레코드)개수 세어주는 함수 호출
	FILE* fload;
	printf("총 %d개의 데이터가 있습니다.\n", Cnt);
	printf("몇 번째 데이터를 조회하시겠습니까?");
	scanf_s("%d", &nNum);

	fload = fopen(_FILE_, "r+"); //파일 읽기
	fread(Book2, rsize, Cnt, fload);//읽은 내용을 저장하는 주소, 데이터 크기단위, 읽을 단위개수, 읽을 파일
	for (i = 0; i < Cnt; i++) {
		if (nNum - 1 == i) {
			printf("\n%d번 째 데이터\n", i + 1);
			printf("이    름: %s\n", (Book2 + i)->cName);
			printf("전화번호: %s\n", (Book2 + i)->cTel);
			printf("주    소: %s\n", (Book2 + i)->cAddr);
		}
	}
	fclose(fload);
	system("pause");
}
void SelThree(unsigned rsize, struct data* Book2) { //자료 수정
	int Cnt, i, nNum, temp = 0;
	FILE* fsave;
	FILE* fload;

	Cnt = Cnt_data(rsize);

	printf("총 %d개의 데이터가 있습니다.\n", Cnt);
	printf("몇 번째 데이터를 수정하시겠습니까?");
	scanf_s("%d", &nNum);

	fload = fopen(_FILE_, "r+");
	fread(Book2, rsize, Cnt, fload);
	for (i = 0; i < Cnt; i++) {
		if (nNum - 1 == i) {
			printf("\n %d번 째 데이터 \n", i + 1);
			fflush(stdin);
			rewind(stdin); // 엔터먹기, 매개변수 스트림 초기화
			printf("이    름: ");
			gets((Book2 + i)->cName);
			printf("전화번호: ");
			gets((Book2 + i)->cTel);
			printf("주    소: ");
			gets((Book2 + i)->cAddr);
			if (strlen((Book2 + i)->cName) < 1 || strlen((Book2 + i)->cTel) < 1 || strlen((Book2 + i)->cAddr) < 1) {
				temp++;
			}
		}
	}
	if (temp > 0) {
		printf("아무런 입력이 없어 주소록을 수정하지 않았습니다.");
	}else{
		fsave = fopen(_FILE_, "w+"); //쓰기파일로 열기
		fwrite(Book2, rsize * Cnt, 1, fsave);
		fclose(fsave);
	}
	fclose(fload);
	system("pause");
}
void SelFour(unsigned rsize, struct data* Book2) { //자료 삭제
	int i, j = 0;
	int nNum;
	char cYN;
	int Cnt = Cnt_data(rsize);
	FILE* fsave; //읽기용
	FILE* fload; //쓰기용
	printf("총 %d개의 데이터가 있습니다.\n", Cnt);
	if (Cnt == 1) {
		printf("1개의 데이터만 존재하므로 삭제가 불가능합니다.");
		fflush(stdin);
		printf("모두 삭제하시겠습니까?(Y/N)");
		cYN = getchar();
		if (cYN == 'Y' || cYN == 'y') {
			_unlink(_FILE_);
		}
		else {
			printf("취소되었습니다.");
		}
	}
	else {
		while (1) {
			printf("몇 번째 데이터를 삭제하시겠습니까?");
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
		printf("선택하신 레코드가 삭제되었습니다.\n");
		fclose(fload);
	}
	system("pause");
}
void SelFive(unsigned rsize, struct data* Book2) { //자료 조회
	int i;
	int Cnt = Cnt_data(rsize);
	FILE* fload;

	printf("총 %d개의 데이터가 있습니다. ", Cnt);
	fload = fopen(_FILE_, "r+");
	fread(Book2, rsize, Cnt, fload);
	for (i = 0; i < Cnt; i++) {
		printf("\n %d번 째 데이터 \n", i + 1);
		printf("이    름: %s \n", (Book2 + i)->cName);
		printf("전화번호: %s \n", (Book2 + i)->cTel);
		printf("주    소: %s \n", (Book2 + i)->cAddr);
	}
	fclose(fload);
	system("pause");
}