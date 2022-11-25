#include <stdio.h>
#include <conio.h>

#define DATA 100
#define KEY 5

void logo();


typedef struct MEMBER {			// 저장할 데이터 구조체
	int stdCode;
	char name[10];
	char majorCode[5];
} MEMBER;

void main() {
	int stdCode = 0;		// 탐색용
	int selectNum = 0;		// 기능 선택
	int i = 0, j,k = 0;
	int i0 = 0, i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0;
	int pass;				// 중복 확인 통과 함수
	int remainder = 0;		// 나머지 함수
	int remainder1 = 0;		// 나머지 함수2

	MEMBER *Member;
	MEMBER *Member0;
	MEMBER *Member1;
	MEMBER *Member2;
	MEMBER *Member3;
	MEMBER *Member4;


	Member = (MEMBER *)malloc((25 * DATA) * sizeof(MEMBER)); //동적 메모리 할당
	if (Member == NULL) {
		printf("메모리 할당 오류\n");
		exit(1);
	}
	Member0 = (MEMBER *)malloc((25 * DATA) * sizeof(MEMBER)); 
	if (Member0 == NULL) {
		printf("메모리 할당 오류\n");
		exit(1);
	}
	Member1 = (MEMBER *)malloc((25 * DATA) * sizeof(MEMBER));
	if (Member1 == NULL) {
		printf("메모리 할당 오류\n");
		exit(1);
	}
	Member2 = (MEMBER *)malloc((25 * DATA) * sizeof(MEMBER));
	if (Member2 == NULL) {
		printf("메모리 할당 오류\n");
		exit(1);
	}
	Member3 = (MEMBER *)malloc((25 * DATA) * sizeof(MEMBER));
	if (Member3 == NULL) {
		printf("메모리 할당 오류\n");
		exit(1);
	}
	Member4 = (MEMBER *)malloc((25 * DATA) * sizeof(MEMBER));
	if (Member4 == NULL) {
		printf("메모리 할당 오류\n");
		exit(1);
	}


	while (1) {

		logo();		// 로고

		printf(" 현재 저장 데이터 수 : %d\n", i);
		printf(" 현재 키값별 저장 데이터 수 >> \n");
		printf("[0] : %d개 [1] : %d개 [2] : %d개 [3] : %d개 [4] : %d개\n", i0, i1, i2, i3, i4);

		while(1) {
			printf("기능을 선택해 주세요 : ");
			scanf_s("%d", &selectNum);
			if (selectNum > 0 && selectNum < 5)	// 기능 외의 번호 선택 방지
				break;
			printf("번호를 다시 입력해 주세요\n");
		}

		switch (selectNum) {
		case 1:	// 학생 정보 입력
			printf("데이터를 입력하세요. \n\n");
			getchar();

			do {
				pass = 0;	// 중복검사 시작
				printf("[학번] : ");
				scanf_s("%d", &Member[i].stdCode);
				remainder = Member[i].stdCode % KEY;	// stdCode값을 키값으로 나눔
				getchar();

				switch (remainder) {	// 나머지 결과에 따라 비교 내용 변화 (0 ~ 4)
				case 0:
					for (j = 0; j < i0; j++) {
						if (Member0[j].stdCode == Member[i].stdCode) {// 동일한 내용이 있다면 실행
							printf("해당 학번이 이미 존재 합니다. 재입력 하세요\n");
							pass++;
							break;
						}
					}
				case 1:
					for (j = 0; j < i1; j++) {
						if (Member1[j].stdCode == Member[i].stdCode) {
							printf("해당 학번이 이미 존재 합니다. 재입력 하세요\n");
							pass++;
							break;
						}
					}
				case 2:
					for (j = 0; j < i2; j++) {
						if (Member2[j].stdCode == Member[i].stdCode) {
							printf("해당 학번이 이미 존재 합니다. 재입력 하세요\n");
							pass++;
							break;
						}
					}
				case 3:
					for (j = 0; j < i3; j++) {
						if (Member3[j].stdCode == Member[i].stdCode) {
							printf("해당 학번이 이미 존재 합니다. 재입력 하세요\n");
							pass++;
							break;
						}
					}
				case 4:
					for (j = 0; j < i4; j++) {
						if (Member4[j].stdCode == Member[i].stdCode) {
							printf("해당 학번이 이미 존재 합니다. 재입력 하세요\n");
							pass++;
							break;
						}
					}
				}
			} while (pass); // 중복하는 내용이 없을시 통과

			printf("[이름] : ");		// 나머지 내용 입력
			gets_s(&Member[i].name, 10);
			printf("[학과] : ");
			gets_s(&Member[i].majorCode, 5);

			switch (remainder) { // 이전 나머지 값에 해당하는 위치에 값  저장하고 해당 위치의 수량 증가
			case 0:
				Member0[i0].stdCode = Member[i].stdCode;
				strcpy_s(Member0[i0].name, 10, Member[i].name);
				strcpy_s(Member0[i0].majorCode, 5, Member[i].majorCode);
				i0++; break;
			case 1:
				Member1[i1].stdCode = Member[i].stdCode;
				strcpy_s(Member1[i1].name, 10, Member[i].name);
				strcpy_s(Member1[i1].majorCode, 5, Member[i].majorCode);
				i1++; break;
			case 2:
				Member2[i2].stdCode = Member[i].stdCode;
				strcpy_s(Member2[i2].name, 10, Member[i].name);
				strcpy_s(Member2[i2].majorCode, 5, Member[i].majorCode);
				i2++; break;
			case 3:
				Member3[i3].stdCode = Member[i].stdCode;
				strcpy_s(Member3[i3].name, 10, Member[i].name);
				strcpy_s(Member3[i3].majorCode, 5, Member[i].majorCode);
				i3++; break;
			case 4:
				Member4[i4].stdCode = Member[i].stdCode;
				strcpy_s(Member4[i4].name, 10, Member[i].name);
				strcpy_s(Member4[i4].majorCode, 5, Member[i].majorCode);
				i4++; break;
			}

			i++;	// 총수량 1증가

			printf("\n");

			// 저장 내용 모두 출력

			printf("[0]번 키값\n");
			for (j = 0; j < i0; j++)
				printf("->[학번] : %d [이름] : %s [학과] : %s\n", Member0[j].stdCode, 
					Member0[j].name, Member0[j].majorCode);
			printf("[1]번 키값\n");
			for (j = 0; j < i1; j++)
				printf("->[학번] : %d [이름] : %s [학과] : %s\n", Member1[j].stdCode, 
					Member1[j].name, Member1[j].majorCode);
			printf("[2]번 키값\n");
			for (j = 0; j < i2; j++)
				printf("->[학번] : %d [이름] : %s [학과] : %s\n", Member2[j].stdCode, 
					Member2[j].name, Member2[j].majorCode);
			printf("[3]번 키값\n");
			for (j = 0; j < i3; j++)
				printf("->[학번] : %d [이름] : %s [학과] : %s\n", Member3[j].stdCode, 
					Member3[j].name, Member3[j].majorCode);
			printf("[4]번 키값\n");
			for (j = 0; j < i4; j++)
				printf("->[학번] : %d [이름] : %s [학과] : %s\n", Member4[j].stdCode, 
					Member4[j].name, Member4[j].majorCode);

			break;

		case 2: // 학생 정보 삭제
			getchar();
			printf("삭제할 학생의 학번 입력 : ");
			scanf_s("%d", &stdCode);
			remainder1 = stdCode % KEY;

			switch (remainder1) {
			case 0:
				for (j = 0; j < i0; j++) {
					if (Member0[j].stdCode == stdCode) {
						printf("[학번] : %d [이름] : %s [학과] : %s\n", Member0[j].stdCode, 
							Member0[j].name, Member0[j].majorCode);
						for (; j < i0; j++) {	// 해당 위치값을 다음값으로 반복해서 덮어 씌운다
							Member0[j] = Member0[j + 1];
						}
						i0--;	// 해당 위치의 총 수량 감소
						break;
					}
				}printf("해당 학생이 존재 하지 않음\n"); break;
			case 1:
				for (j = 0; j < i1; j++) {
					if (Member1[j].stdCode == stdCode) {
						printf("[학번] : %d [이름] : %s [학과] : %s\n", Member1[j].stdCode, 
							Member1[j].name, Member1[j].majorCode);
						for (; j < i1; j++) {
							Member1[j] = Member1[j + 1];
						}
						i1--;
						break;
					}
				}printf("해당 학생이 존재 하지 않음\n"); break;
			case 2:
				for (j = 0; j < i2; j++) {
					if (Member2[j].stdCode == stdCode) {
						printf("[학번] : %d [이름] : %s [학과] : %s\n", Member2[j].stdCode, 
							Member2[j].name, Member2[j].majorCode);
						for (; j < i2; j++) {
							Member2[j] = Member2[j + 1];
						}
						i2--;
						break;
					}
				}printf("해당 학생이 존재 하지 않음\n"); break;
			case 3:
				for (j = 0; j < i3; j++) {
					if (Member3[j].stdCode == stdCode) {
						printf("[학번] : %d [이름] : %s [학과] : %s\n", Member3[j].stdCode, 
							Member3[j].name, Member3[j].majorCode);
						for (; j < i3; j++) {
							Member3[j] = Member3[j + 1];
						}
						i3--;
						break;
					}
				}printf("해당 학생이 존재 하지 않음\n"); break;
			case 4:
				for (j = 0; j < i4; j++) {
					if (Member4[j].stdCode == stdCode) {
						printf("[학번] : %d [이름] : %s [학과] : %s\n", Member4[j].stdCode, 
							Member4[j].name, Member4[j].majorCode);
						for (; j < i4; j++) {
							Member4[j] = Member4[j + 1];
						}
						i4--;
						break;
					}
				}printf("해당 학생이 존재 하지 않음\n"); break;
			}

			i--; // 총수량 감소


			// 삭제 이후 정보 출력
			printf("수정 후 데이터\n");
			printf("\n");
			printf("[0]번 키값\n");
			for (j = 0; j < i0; j++)
				printf("->[학번] : %d [이름] : %s [학과] : %s\n", Member0[j].stdCode, 
					Member0[j].name, Member0[j].majorCode);
			printf("[1]번 키값\n");
			for (j = 0; j < i1; j++)
				printf("->[학번] : %d [이름] : %s [학과] : %s\n", Member1[j].stdCode, 
					Member1[j].name, Member1[j].majorCode);
			printf("[2]번 키값\n");
			for (j = 0; j < i2; j++)
				printf("->[학번] : %d [이름] : %s [학과] : %s\n", Member2[j].stdCode, 
					Member2[j].name, Member2[j].majorCode);
			printf("[3]번 키값\n");
			for (j = 0; j < i3; j++)
				printf("->[학번] : %d [이름] : %s [학과] : %s\n", Member3[j].stdCode, 
					Member3[j].name, Member3[j].majorCode);
			printf("[4]번 키값\n");
			for (j = 0; j < i4; j++)
				printf("->[학번] : %d [이름] : %s [학과] : %s\n", Member4[j].stdCode, 
					Member4[j].name, Member4[j].majorCode);


			break;

		case 3: // 학생 탐색
			getchar();
			printf("찾을 학생의 학번 입력 : ");
			scanf_s("%d", &stdCode);
			remainder1 = stdCode % KEY;

			switch (remainder1) {	
			case 0:
				for (j = 0; j < i0; j++) {
					if (Member0[j].stdCode == stdCode) { // 동일 내용  존재시 출력해줌
						printf("[학번] : %d [이름] : %s [학과] : %s\n", Member0[j].stdCode, 
							Member0[j].name, Member0[j].majorCode);
						break;
					}			
				}printf("해당 학생이 존재 하지 않음\n"); break;
			case 1:
				for (j = 0; j < i1; j++) {
					if (Member1[j].stdCode == stdCode) {
						printf("[학번] : %d [이름] : %s [학과] : %s\n", Member1[j].stdCode, 
							Member1[j].name, Member1[j].majorCode);
						break;
					}
				}printf("해당 학생이 존재 하지 않음\n"); break;
			case 2:
				for (j = 0; j < i2; j++) {
					if (Member2[j].stdCode == stdCode) {
						printf("[학번] : %d [이름] : %s [학과] : %s\n", Member2[j].stdCode, 
							Member2[j].name, Member2[j].majorCode);
						break;
					}
				}printf("해당 학생이 존재 하지 않음\n"); break;
			case 3:
				for (j = 0; j < i3; j++) {
					if (Member3[j].stdCode == stdCode) {
						printf("[학번] : %d [이름] : %s [학과] : %s\n", Member3[j].stdCode, 
							Member3[j].name, Member3[j].majorCode);
						break;
					}
				}printf("해당 학생이 존재 하지 않음\n"); break;
			case 4:
				for (j = 0; j < i4; j++) {
					if (Member4[j].stdCode == stdCode) {
						printf("[학번] : %d [이름] : %s [학과] : %s\n", Member4[j].stdCode, 
							Member4[j].name, Member4[j].majorCode);
						break;
					}	
				}printf("해당 학생이 존재 하지 않음\n"); break;
			}
			break;


		case 4:
			free(Member); // 동적 메모리 반납
			free(Member0);
			free(Member1);
			free(Member2);
			free(Member3);
			free(Member4); return;
		}


		while (!_kbhit());
		getchar();
		system("cls");	// 화면 초기화
	}

	free(Member); // 동적 메모리 반납
	free(Member0);
	free(Member1);
	free(Member2);
	free(Member3);
	free(Member4);
	return;
}


void logo() {
	printf("=========================================\n");
	printf("==       기     능     선     택       ==\n");
	printf("==                                     ==\n");
	printf("==  1. 추가  2. 삭제  3. 검색  4. 종료 ==\n");
	printf("=========================================\n");
}
