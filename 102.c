#include <stdio.h>

#define BIN	3
#define CASE 6

enum {
	B,
	G,
	C,
	BOTTLE,
};

char cases[CASE][BIN + 1] = {
	"BCG",
	"BGC",
	"CBG",
	"CGB",
	"GBC",
	"GCB",
};

int bottles[BIN][BOTTLE];

int main(void)
{
	//freopen("input.txt", "r", stdin);
	
	while (scanf("%d %d %d %d %d %d %d %d %d",
		&bottles[0][B], &bottles[0][G], &bottles[0][C],
		&bottles[1][B], &bottles[1][G], &bottles[1][C],
		&bottles[2][B], &bottles[2][G], &bottles[2][C]) != EOF) {

		long long min = 987654321;
		long long minc = 1;
		for (int i = 0; i < CASE; i++) {
			char *c = cases[i];

			int move = 0;
			for (int j = 0; j < BIN; j++) {
				if (c[j] == 'B') {
					move += bottles[j][G];
					move += bottles[j][C];
				}
				else if (c[j] == 'G') {
					move += bottles[j][B];
					move += bottles[j][C];
				}
				else if (c[j] == 'C') {
					move += bottles[j][G];
					move += bottles[j][B];
				}
			}

			if (min > move) {
				min = move;
				minc = i;
			}
		}

		printf("%s %lld\n", cases[minc], min);
	}

	return 0;
}
