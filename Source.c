#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 12

void prtline(char *linestr, int num);
void shuffle(char tbl[]); //����ւ��̂��߁Cshuffle()�Ƃ����֐����g��

int main(void) {

	int tate, yoko;
	char lineStr[] = "+---";
	int boxsize;

	char tatetbl[MAXSIZE] = {1,2,3,4,5,6,7,8,9,10,11,12};
	char yokotbl[MAXSIZE] = {1,2,3,4,5,6,7,8,9,10,11,12};

	while (-1) {  //�������ニ�[�v
		printf("���̕\�̘g��(�킭����)(2�`%d)����͂��Ă������� 0�͏I��: ", MAXSIZE);
		scanf("%d",&boxsize);
		if (boxsize == 0) {
			break;//�I��
		}

		if ( !(boxsize >= 2 && boxsize <= MAXSIZE))  //Not equal
			continue;

		shuffle(yokotbl);
		shuffle(tatetbl);

		prtline(lineStr, boxsize);
		//printf("+---+---+---+---+---+---+---+---+---+---+\n");
		printf("|   ");
		for (yoko = 0; yoko < boxsize; yoko++) {
			printf("|%3d", yokotbl[yoko]);
		}

		printf("|\n");
		//printf("+---+---+---+---+---+---+---+---+---+---+\n");

		prtline(lineStr, boxsize);
		for (tate = 0; tate < boxsize; tate++) {
			printf("|%3d", tatetbl[tate]);

			for (yoko = 0; yoko < boxsize; yoko++) {
				printf("|%3d", tatetbl[tate] * yokotbl[yoko]);
			}

			printf("|\n");
			prtline(lineStr, boxsize);
			//printf("+---+---+---+---+---+---+---+---+---+---+\n");
		}
	}//End while
	return 0;
}

//+--- �̌J��Ԃ��̂��߂ɍ�����֐�

void prtline(char*lineStr, int num) {
	
	int cnt;

	for (cnt = 0; cnt <= num; cnt++){
		printf("%s", lineStr);
	}
	printf("%c\n", lineStr[0]);
}

//�z��̓���ւ��̂��ߍ������o�P�c

void shuffle(char tbl[]) { 
	int cnt;
	int temp;
	int randble;

	for (cnt = 0; cnt < MAXSIZE; cnt++) {
		randble = rand() % MAXSIZE;
		temp = tbl[randble];
		tbl[randble] = tbl[cnt];
		tbl[cnt] = temp;
	}
}