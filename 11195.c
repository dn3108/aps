#include <stdio.h>

int tc;
int n;
char table[16][17];
int res;
bool ld[32], rd[32], row[32];

void queen(int c)
{
	if (c == n) {
		res++;
		return;
	}

	for (int r = 0; r < n; r++) {
		if (table[r][c] != '*' && !row[r] && !ld[r - c + n - 1] && !rd[r + c]) {
			ld[r - c + n - 1] = rd[r + c] = row[r] = true;
			queen(c + 1);
			ld[r - c + n - 1] = rd[r + c] = row[r] = false;
		}
	}
}

int main(void)
{
	//freopen("input.txt", "r", stdin);
	
	while (scanf("%d", &n) && n != 0) {
		for (int i = 0; i < n; i++) {
			scanf("%s", table[i]);
			ld[i] = rd[i] = row[i] = false;
		}
		res = 0;
		queen(0);
		printf("Case %d: %d\n", ++tc, res);
	}

	return 0;
}
