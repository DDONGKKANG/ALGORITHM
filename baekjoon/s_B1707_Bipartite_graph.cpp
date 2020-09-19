#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int bfs(vector<vector<int>> input, int group[], int v) {
	queue <int> q;
	q.push(v);
	group[v] = 1;

	while (!q.empty()) {
		int f = q.front();
		q.pop();

		for (int i = 0; i < input[f].size(); i++) {
			if (group[f] == group[input[f][i]])	// ����� ������ �׷��� ���� ���
				return 0;
			else if (group[input[f][i]] == group[f] % 2 + 1)	// ����� ������ �׷��� �ٸ� ���
				continue;

			// ����� ������ �׷��� ���� ��� queue�� �߰� �� �׷� ����
			q.push(input[f][i]);
			group[input[f][i]] = group[f] % 2 + 1;
		}
	}
	return 1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int k;
	cin >> k;

	while (k--) {
		int v, e;
		int tv, te;
		int ans = 0;

		cin >> v >> e;

		vector<vector<int>> input(v+1, vector<int>());
		int group[20002] = { 0, };

		for (int i = 0; i < e; i++) {
			cin >> tv >> te;
			input[tv].push_back(te);
			input[te].push_back(tv);
		}
		
		for (int i = 1; i <= v; i++) {
			if (group[i] == 0) {
				ans = bfs(input, group, i);

				if (ans == 0) {
					cout << "NO" << '\n';
					break;
				}
			}
		}

		if (ans == 1) {
			cout << "YES" << '\n';
		}
	}

	return 0;
}