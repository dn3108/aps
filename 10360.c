#include <stdio.h>

#define diff(a,b)	(((a) > (b)) ? (a) - (b) : (b) - (a))

int T;
int d;
int n;
int rat[1025][1025];
int killed[1025][1025];

void solve(void)
{
	for (int i = 0; i <= 1024; i++) {
		for (int j = 0; j <= 1024; j++) {
			int sx, ex, sy, ey;
			if (i - d < 0)
				sx = 0;
			else
				sx = i - d;

			if (j - d < 0)
				sy = 0;
			else
				sy = j - d;

			if (i + d > 1024)
				ex = 1024;
			else
				ex = i + d;

			if (j + d > 1024)
				ey = 1024;
			else
				ey = j + d;

			for (int x = sx; x <= ex; x++) {
				for (int y = sy; y <= ey; y++) {
					killed[i][j] += rat[x][y];
				}
			}
		}
	}

	int max = -1;
	int a = 0, b = 0;
	for (int i = 0; i <= 1024; i++) {
		for (int j = 0; j <= 1024; j++) {
			if (killed[i][j] > max) {
				max = killed[i][j];
				a = i; b = j;
			}
		}
	}

	printf("%d %d %d\n", a, b, max);
}

int main(void)
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &d);
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				rat[i][j] = 0;
				killed[i][j] = 0;
			}
		}

		for (int i = 0; i < n; i++) {
			int x, y, rats;
			scanf("%d %d %d", &x, &y, &rats);
			rat[x][y] = rats;
		}

		solve();
	}

	return 0;
}
