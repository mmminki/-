// 11403 ���ã��

// �׷��� G �� ��� ����(i, j)�� ���ؼ� i���� j�� ���� ���̰� ����� ��ΰ� �ִ��� ���ϴ� ���α׷�

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAXNUM 100

using namespace std;

int visited[MAXNUM];
int path[MAXNUM][MAXNUM];
int graph[MAXNUM][MAXNUM];
int n;

queue<int> q;
void bfs(int start);

int main() {
	memset(path, 0, sizeof(path));
	memset(graph, 0, sizeof(path));
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}
	for (int k = 0; k < n; k++) {
		bfs(k);
	}
	for ( int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << path[i][j] << " ";
		}
		cout << "\n";
	}
}


void bfs(int start) {
	q.push(start);
	memset(visited, 0, sizeof(visited));
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for(int i = 0; i<n; i++){
			if (visited[i] != 1 &&  graph[v][i] == 1) {
				visited[i] = 1;
				q.push(i);
				path[start][i] = 1;
			}
		}
	}
}