#include <stdio.h>

int T, N;
int G[100][100];
bool visit[100];
bool in_graph[100];

void dfs(int u)
{
	visit[u] = true;

	for (int v = 0; v < N; v++) {
		if (G[u][v] == 1 && !visit[v]) {
			dfs(v);
		}
	}
}

int main(void)
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	
	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			visit[i] = false;
			in_graph[i] = true;
			for (int j = 0; j < N; j++) {
				scanf("%d", &G[i][j]);
			}
		}

		printf("Case %d:\n", t);
		printf("+");
		for (int j = 0; j < N + (N - 1); j++) {
			printf("-");
		}
		printf("+\n");

		dfs(0);
		for (int i = 0; i < N; i++) {
			if (!visit[i]) {
				in_graph[i] = false;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visit[j] = false;
				if (G[i][j] == 1)
					G[i][j] = 2;
			}

			dfs(0);
			printf("|");
			for (int j = 0; j < N; j++) {
				char yn = 'N';

				if (in_graph[j]) {
					if (i == j)
						yn = 'Y';
					else if (!visit[j]) {
						yn = 'Y';
					}
				}

				printf("%c|", yn);
			}
			printf("\n");
			printf("+");
			for (int j = 0; j < N + (N - 1); j++) {
				printf("-");
			}
			printf("+\n");

			for (int j = 0; j < N; j++) {
				if (G[i][j] == 2)
					G[i][j] = 1;
			}
		}
	}

	return 0;
}
