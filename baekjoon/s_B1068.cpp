/*
baekjoon 1068 : Ʈ��
solved by JY
dfs ���
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n = 0, r = 0, answer = 0;
vector<int> root;
vector<int> tree[52];

void dfs(int parent) {
	if (parent == r)
		return ;

	if (tree[parent].empty()) {	// �ڽ��� ������ ++
		answer++;
		return ;
	}

	for (int i = 0; i < tree[parent].size(); i++) {
		if (tree[parent].size() == 1 && tree[parent][i] == r) {
			answer++;	// �ڽ��� �ϳ��ε� �װ� ���� ���� ++
			return ;
		}
		else
			dfs(tree[parent][i]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int tmp;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp == -1)
			root.push_back(i);
		else
			tree[tmp].push_back(i);	// �θ� �ڽ� ��� �߰�
	}
	cin >> r;

	for (int i = 0; i < root.size(); i++) {
		dfs(root[i]);
	}

	cout << answer;

	return 0;
}