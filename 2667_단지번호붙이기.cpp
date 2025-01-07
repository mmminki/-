// ������ȣ���̱�
// �����¿� ����� ����Ʈ���� ������ �̷�
// ������ ����Ʈ ���� ���� �������� �������� ������ ����Ʈ ���� ���

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool visited[26][26];
int map[26][26];

int xpos[4] = { 0, -1, 1, 0 };
int ypos[4] = { -1, 0, 0, 1 };

vector <int> APT_num;

void dfs(int x, int y, int count);

int main() {
	int N;
	cin >> N;

	int count = 0;				// ���� ��
	string temp;

	for (int i = 1; i <= N; i++) {
		cin >> temp;
		for (int j = 1; j <= N; j++) {
			map[i][j] = stoi(temp.substr(j-1, 1));
		}
	}
	/*for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}*/
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 1 && visited[i][j] == false) {
				APT_num.push_back(0);
				dfs(i, j, count);
				count++;
			}
		}
	}

	sort(APT_num.begin(), APT_num.end());
	cout << count << "\n";
	for (int i = 0; i < count; i++) {
		cout << APT_num[i] << "\n";
	}
}

void dfs(int x, int y,int c) {			// �ñ��Ѱ� map[x][y] = 0���� �ٲٸ� �ȵǴ°�? visited�迭 ���� �Ⱦ���
	visited[x][y] = true;
	APT_num[c]++;
	for (int k = 0; k < 4; k++) {
		int xx = x + xpos[k];
		int yy = y + ypos[k];
		if (xx <= 0 || yy <= 0 || xx > 25 || yy > 25) {
			continue;
		}
		if (map[xx][yy] == 1 && visited[xx][yy] == false) {
			dfs(xx, yy, c);
		}
	}

}