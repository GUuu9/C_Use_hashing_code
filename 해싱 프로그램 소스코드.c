#include <stdio.h>
#include <conio.h>

#define DATA 100
#define KEY 5

void logo();


typedef struct MEMBER {			// ������ ������ ����ü
	int stdCode;
	char name[10];
	char majorCode[5];
} MEMBER;

void main() {
	int stdCode = 0;		// Ž����
	int selectNum = 0;		// ��� ����
	int i = 0, j,k = 0;
	int i0 = 0, i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0;
	int pass;				// �ߺ� Ȯ�� ��� �Լ�
	int remainder = 0;		// ������ �Լ�
	int remainder1 = 0;		// ������ �Լ�2

	MEMBER *Member;
	MEMBER *Member0;
	MEMBER *Member1;
	MEMBER *Member2;
	MEMBER *Member3;
	MEMBER *Member4;


	Member = (MEMBER *)malloc((25 * DATA) * sizeof(MEMBER)); //���� �޸� �Ҵ�
	if (Member == NULL) {
		printf("�޸� �Ҵ� ����\n");
		exit(1);
	}
	Member0 = (MEMBER *)malloc((25 * DATA) * sizeof(MEMBER)); 
	if (Member0 == NULL) {
		printf("�޸� �Ҵ� ����\n");
		exit(1);
	}
	Member1 = (MEMBER *)malloc((25 * DATA) * sizeof(MEMBER));
	if (Member1 == NULL) {
		printf("�޸� �Ҵ� ����\n");
		exit(1);
	}
	Member2 = (MEMBER *)malloc((25 * DATA) * sizeof(MEMBER));
	if (Member2 == NULL) {
		printf("�޸� �Ҵ� ����\n");
		exit(1);
	}
	Member3 = (MEMBER *)malloc((25 * DATA) * sizeof(MEMBER));
	if (Member3 == NULL) {
		printf("�޸� �Ҵ� ����\n");
		exit(1);
	}
	Member4 = (MEMBER *)malloc((25 * DATA) * sizeof(MEMBER));
	if (Member4 == NULL) {
		printf("�޸� �Ҵ� ����\n");
		exit(1);
	}


	while (1) {

		logo();		// �ΰ�

		printf(" ���� ���� ������ �� : %d\n", i);
		printf(" ���� Ű���� ���� ������ �� >> \n");
		printf("[0] : %d�� [1] : %d�� [2] : %d�� [3] : %d�� [4] : %d��\n", i0, i1, i2, i3, i4);

		while(1) {
			printf("����� ������ �ּ��� : ");
			scanf_s("%d", &selectNum);
			if (selectNum > 0 && selectNum < 5)	// ��� ���� ��ȣ ���� ����
				break;
			printf("��ȣ�� �ٽ� �Է��� �ּ���\n");
		}

		switch (selectNum) {
		case 1:	// �л� ���� �Է�
			printf("�����͸� �Է��ϼ���. \n\n");
			getchar();

			do {
				pass = 0;	// �ߺ��˻� ����
				printf("[�й�] : ");
				scanf_s("%d", &Member[i].stdCode);
				remainder = Member[i].stdCode % KEY;	// stdCode���� Ű������ ����
				getchar();

				switch (remainder) {	// ������ ����� ���� �� ���� ��ȭ (0 ~ 4)
				case 0:
					for (j = 0; j < i0; j++) {
						if (Member0[j].stdCode == Member[i].stdCode) {// ������ ������ �ִٸ� ����
							printf("�ش� �й��� �̹� ���� �մϴ�. ���Է� �ϼ���\n");
							pass++;
							break;
						}
					}
				case 1:
					for (j = 0; j < i1; j++) {
						if (Member1[j].stdCode == Member[i].stdCode) {
							printf("�ش� �й��� �̹� ���� �մϴ�. ���Է� �ϼ���\n");
							pass++;
							break;
						}
					}
				case 2:
					for (j = 0; j < i2; j++) {
						if (Member2[j].stdCode == Member[i].stdCode) {
							printf("�ش� �й��� �̹� ���� �մϴ�. ���Է� �ϼ���\n");
							pass++;
							break;
						}
					}
				case 3:
					for (j = 0; j < i3; j++) {
						if (Member3[j].stdCode == Member[i].stdCode) {
							printf("�ش� �й��� �̹� ���� �մϴ�. ���Է� �ϼ���\n");
							pass++;
							break;
						}
					}
				case 4:
					for (j = 0; j < i4; j++) {
						if (Member4[j].stdCode == Member[i].stdCode) {
							printf("�ش� �й��� �̹� ���� �մϴ�. ���Է� �ϼ���\n");
							pass++;
							break;
						}
					}
				}
			} while (pass); // �ߺ��ϴ� ������ ������ ���

			printf("[�̸�] : ");		// ������ ���� �Է�
			gets_s(&Member[i].name, 10);
			printf("[�а�] : ");
			gets_s(&Member[i].majorCode, 5);

			switch (remainder) { // ���� ������ ���� �ش��ϴ� ��ġ�� ��  �����ϰ� �ش� ��ġ�� ���� ����
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

			i++;	// �Ѽ��� 1����

			printf("\n");

			// ���� ���� ��� ���

			printf("[0]�� Ű��\n");
			for (j = 0; j < i0; j++)
				printf("->[�й�] : %d [�̸�] : %s [�а�] : %s\n", Member0[j].stdCode, 
					Member0[j].name, Member0[j].majorCode);
			printf("[1]�� Ű��\n");
			for (j = 0; j < i1; j++)
				printf("->[�й�] : %d [�̸�] : %s [�а�] : %s\n", Member1[j].stdCode, 
					Member1[j].name, Member1[j].majorCode);
			printf("[2]�� Ű��\n");
			for (j = 0; j < i2; j++)
				printf("->[�й�] : %d [�̸�] : %s [�а�] : %s\n", Member2[j].stdCode, 
					Member2[j].name, Member2[j].majorCode);
			printf("[3]�� Ű��\n");
			for (j = 0; j < i3; j++)
				printf("->[�й�] : %d [�̸�] : %s [�а�] : %s\n", Member3[j].stdCode, 
					Member3[j].name, Member3[j].majorCode);
			printf("[4]�� Ű��\n");
			for (j = 0; j < i4; j++)
				printf("->[�й�] : %d [�̸�] : %s [�а�] : %s\n", Member4[j].stdCode, 
					Member4[j].name, Member4[j].majorCode);

			break;

		case 2: // �л� ���� ����
			getchar();
			printf("������ �л��� �й� �Է� : ");
			scanf_s("%d", &stdCode);
			remainder1 = stdCode % KEY;

			switch (remainder1) {
			case 0:
				for (j = 0; j < i0; j++) {
					if (Member0[j].stdCode == stdCode) {
						printf("[�й�] : %d [�̸�] : %s [�а�] : %s\n", Member0[j].stdCode, 
							Member0[j].name, Member0[j].majorCode);
						for (; j < i0; j++) {	// �ش� ��ġ���� ���������� �ݺ��ؼ� ���� �����
							Member0[j] = Member0[j + 1];
						}
						i0--;	// �ش� ��ġ�� �� ���� ����
						break;
					}
				}printf("�ش� �л��� ���� ���� ����\n"); break;
			case 1:
				for (j = 0; j < i1; j++) {
					if (Member1[j].stdCode == stdCode) {
						printf("[�й�] : %d [�̸�] : %s [�а�] : %s\n", Member1[j].stdCode, 
							Member1[j].name, Member1[j].majorCode);
						for (; j < i1; j++) {
							Member1[j] = Member1[j + 1];
						}
						i1--;
						break;
					}
				}printf("�ش� �л��� ���� ���� ����\n"); break;
			case 2:
				for (j = 0; j < i2; j++) {
					if (Member2[j].stdCode == stdCode) {
						printf("[�й�] : %d [�̸�] : %s [�а�] : %s\n", Member2[j].stdCode, 
							Member2[j].name, Member2[j].majorCode);
						for (; j < i2; j++) {
							Member2[j] = Member2[j + 1];
						}
						i2--;
						break;
					}
				}printf("�ش� �л��� ���� ���� ����\n"); break;
			case 3:
				for (j = 0; j < i3; j++) {
					if (Member3[j].stdCode == stdCode) {
						printf("[�й�] : %d [�̸�] : %s [�а�] : %s\n", Member3[j].stdCode, 
							Member3[j].name, Member3[j].majorCode);
						for (; j < i3; j++) {
							Member3[j] = Member3[j + 1];
						}
						i3--;
						break;
					}
				}printf("�ش� �л��� ���� ���� ����\n"); break;
			case 4:
				for (j = 0; j < i4; j++) {
					if (Member4[j].stdCode == stdCode) {
						printf("[�й�] : %d [�̸�] : %s [�а�] : %s\n", Member4[j].stdCode, 
							Member4[j].name, Member4[j].majorCode);
						for (; j < i4; j++) {
							Member4[j] = Member4[j + 1];
						}
						i4--;
						break;
					}
				}printf("�ش� �л��� ���� ���� ����\n"); break;
			}

			i--; // �Ѽ��� ����


			// ���� ���� ���� ���
			printf("���� �� ������\n");
			printf("\n");
			printf("[0]�� Ű��\n");
			for (j = 0; j < i0; j++)
				printf("->[�й�] : %d [�̸�] : %s [�а�] : %s\n", Member0[j].stdCode, 
					Member0[j].name, Member0[j].majorCode);
			printf("[1]�� Ű��\n");
			for (j = 0; j < i1; j++)
				printf("->[�й�] : %d [�̸�] : %s [�а�] : %s\n", Member1[j].stdCode, 
					Member1[j].name, Member1[j].majorCode);
			printf("[2]�� Ű��\n");
			for (j = 0; j < i2; j++)
				printf("->[�й�] : %d [�̸�] : %s [�а�] : %s\n", Member2[j].stdCode, 
					Member2[j].name, Member2[j].majorCode);
			printf("[3]�� Ű��\n");
			for (j = 0; j < i3; j++)
				printf("->[�й�] : %d [�̸�] : %s [�а�] : %s\n", Member3[j].stdCode, 
					Member3[j].name, Member3[j].majorCode);
			printf("[4]�� Ű��\n");
			for (j = 0; j < i4; j++)
				printf("->[�й�] : %d [�̸�] : %s [�а�] : %s\n", Member4[j].stdCode, 
					Member4[j].name, Member4[j].majorCode);


			break;

		case 3: // �л� Ž��
			getchar();
			printf("ã�� �л��� �й� �Է� : ");
			scanf_s("%d", &stdCode);
			remainder1 = stdCode % KEY;

			switch (remainder1) {	
			case 0:
				for (j = 0; j < i0; j++) {
					if (Member0[j].stdCode == stdCode) { // ���� ����  ����� �������
						printf("[�й�] : %d [�̸�] : %s [�а�] : %s\n", Member0[j].stdCode, 
							Member0[j].name, Member0[j].majorCode);
						break;
					}			
				}printf("�ش� �л��� ���� ���� ����\n"); break;
			case 1:
				for (j = 0; j < i1; j++) {
					if (Member1[j].stdCode == stdCode) {
						printf("[�й�] : %d [�̸�] : %s [�а�] : %s\n", Member1[j].stdCode, 
							Member1[j].name, Member1[j].majorCode);
						break;
					}
				}printf("�ش� �л��� ���� ���� ����\n"); break;
			case 2:
				for (j = 0; j < i2; j++) {
					if (Member2[j].stdCode == stdCode) {
						printf("[�й�] : %d [�̸�] : %s [�а�] : %s\n", Member2[j].stdCode, 
							Member2[j].name, Member2[j].majorCode);
						break;
					}
				}printf("�ش� �л��� ���� ���� ����\n"); break;
			case 3:
				for (j = 0; j < i3; j++) {
					if (Member3[j].stdCode == stdCode) {
						printf("[�й�] : %d [�̸�] : %s [�а�] : %s\n", Member3[j].stdCode, 
							Member3[j].name, Member3[j].majorCode);
						break;
					}
				}printf("�ش� �л��� ���� ���� ����\n"); break;
			case 4:
				for (j = 0; j < i4; j++) {
					if (Member4[j].stdCode == stdCode) {
						printf("[�й�] : %d [�̸�] : %s [�а�] : %s\n", Member4[j].stdCode, 
							Member4[j].name, Member4[j].majorCode);
						break;
					}	
				}printf("�ش� �л��� ���� ���� ����\n"); break;
			}
			break;


		case 4:
			free(Member); // ���� �޸� �ݳ�
			free(Member0);
			free(Member1);
			free(Member2);
			free(Member3);
			free(Member4); return;
		}


		while (!_kbhit());
		getchar();
		system("cls");	// ȭ�� �ʱ�ȭ
	}

	free(Member); // ���� �޸� �ݳ�
	free(Member0);
	free(Member1);
	free(Member2);
	free(Member3);
	free(Member4);
	return;
}


void logo() {
	printf("=========================================\n");
	printf("==       ��     ��     ��     ��       ==\n");
	printf("==                                     ==\n");
	printf("==  1. �߰�  2. ����  3. �˻�  4. ���� ==\n");
	printf("=========================================\n");
}
