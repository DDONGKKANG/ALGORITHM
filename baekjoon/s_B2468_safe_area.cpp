/*
���� 2468�� : ���� ����
dfs�� ���� ���� Ȯ��
���Ʈ������ ��� ���� Ȯ�� > ���� ���� �ִ밪 ����
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <set>
#define max(a,b) (a>b?a:b)

using namespace std;
vector<vector<int> > input;
int n;
int dy[4] = { 0, 1, 0, -1 };  // ��, ��, ��, ��
int dx[4] = { -1, 0, 1, 0 };  // 0,  1,  2,  3

int visit[105][105];

int dfs(int x, int y, int c) {
	if (visit[x][y] == 1 || input[x][y] <= c)
		return 0;

	visit[x][y] = 1;

	for (int k = 0; k < 4; k++) {
		if (x + dx[k] < 0 || x + dx[k] >= n || y + dy[k] < 0 || y + dy[k] >= n) {
			continue;
		}
		dfs(x + dx[k], y + dy[k], c);
	}
	return 1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int answer = 1;
	set <int> s;

	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<int> tmp;
		for (int j = 0; j < n; j++) {
			int t;
			cin >> t;
			tmp.push_back(t);
			s.insert(t);
		}
		input.push_back(tmp);
	}




	set <int>::iterator iter;

	for (iter = s.begin(); iter != s.end(); iter++) {
		memset(visit, 0, sizeof(visit));
		int c = *iter;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (input[i][j] > c) {
					if (dfs(i, j, c) == 1) {
						cnt++;
					}
				}
			}
		}
		answer = max(answer, cnt);
	}

	cout << answer;

	return 0;
}