#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 12

void prtline(char *linestr, int num);
void shuffle(char tbl[]); //入れ替えのため，shuffle()という関数を使う

int main(void) {

	int tate, yoko;
	char lineStr[] = "+---";
	int boxsize;

	char tatetbl[MAXSIZE] = {1,2,3,4,5,6,7,8,9,10,11,12};
	char yokotbl[MAXSIZE] = {1,2,3,4,5,6,7,8,9,10,11,12};

	while (-1) {  //えいきゅループ
		printf("九九の表の枠数(わくすう)(2～%d)を入力してください 0は終了: ", MAXSIZE);
		scanf("%d",&boxsize);
		if (boxsize == 0) {
			break;//終了
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

//+--- の繰り返しのために作った関数

void prtline(char*lineStr, int num) {
	
	int cnt;

	for (cnt = 0; cnt <= num; cnt++){
		printf("%s", lineStr);
	}
	printf("%c\n", lineStr[0]);
}

//配列の入れ替えのため作った空バケツ

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