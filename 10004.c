#include <stdio.h>

int n, l;
int G[200][200];
bool V[200];
int C[200];

bool dfs(int u, int c)
{
	V[u] = true;
	C[u] = c;

	for (int v=0; v<n; v++) {
		if (G[u][v]) {
			if (V[v]) {
				if (c == C[v])
					return false;
			}
			else {
				return dfs(v, !c);
			}
		}
	}

	return true;
}

int main(void)
{
	//freopen("input.txt", "r", stdin);
	while (scanf("%d", &n) && n != 0) {
		scanf("%d", &l);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				G[i][j] = 0;
			}
			V[i] = false;
			C[i] = -1;
		}

		for (int i = 0; i < l; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			G[a][b] = 1;
			G[b][a] = 1;
		}

		if (dfs(0, 0))
			printf("BICOLORABLE.\n");
		else
			printf("NOT BICOLORABLE.\n");
	}

	return 0;
}
