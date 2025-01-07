#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool visited[201][201];	// A�� B ���� �뷮 ����Ƽ��
int storage[3];			// ������� �뷮
bool answer[201];		// A�� 0�� �� C�� �뷮 �����ϴ� ���� �迭

static int sender[] = { 0,0,1,1,2,2 };
static int receiver[] = { 1,2,0,2,0,1 };

void bfs();

int main() {
	cin >> storage[0] >> storage[1] >> storage[2];

	bfs();

	for (int i = 0; i < 201; i++) {
		if (answer[i] == true) {
			cout << i << " ";
		}
	}
}

void bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	visited[0][0] = true;
	answer[storage[2]] = true;

	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();
		int a = temp.first;
		int b = temp.second;
		int c = storage[2] - a - b;			//c�� ���緮�� C�� �ִ� �뷮 - ���� a �� - ���� b ��

		for (int i = 0; i < 6; i++) {
			int next[3] = { a,b,c };
			next[receiver[i]] += next[sender[i]];
			next[sender[i]] = 0;

			if (next[receiver[i]] > storage[receiver[i]]) {
				//int over_water = next[receiver[i]] - storage[receiver[i]];
				//next[receiver[i]] -= over_water;
				//next[sender[i]] = over_water;
				next[sender[i]] = next[receiver[i]] - storage[receiver[i]];
				next[receiver[i]] = storage[receiver[i]];
			}

			if (visited[next[0]][next[1]] == false) {
				visited[next[0]][next[1]] = true;
				q.push(make_pair(next[0], next[1]));

				if (next[0] == 0) {
					answer[next[2]] = true;
				}
			}
		}

	}
}