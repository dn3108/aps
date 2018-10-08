#include <stdio.h>

int n;

int sqrt(int n, int a)
{
	int ret = 1;

	while (a--) {
		ret *= n;
	}

	return ret;
}

int main(void)
{
	//freopen("input.txt", "r", stdin);

	int a, b;
	while (scanf("%d", &n) != EOF) {
		int div = sqrt(10, n / 2);
		for (int i = 0; i < sqrt(10, n); i++) {
			a = i / div;
			b = i % div;

			if ((a + b) * (a + b) == i) {
				if (n == 2)
					printf("%02d\n", i);
				else if (n == 4)
					printf("%04d\n", i);
				else if (n == 6)
					printf("%06d\n", i);
				else if (n == 8)
					printf("%08d\n", i);
			}
		}
	}

	return 0;
}
