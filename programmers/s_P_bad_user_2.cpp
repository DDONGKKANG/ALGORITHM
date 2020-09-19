// īī�� �ؼ� ���� Ǯ����.
// ���߿� �ٽ� Ǯ���
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int b_size;
int u_size;

int cmp(string a, string b) {	// ���� ���̵����� Ȯ��
	if (a.size() != b.size())
		return 0;

	for (int i = 0; i < a.size(); i++) {
		if (b.at(i) == '*')
			continue;
		if (a.at(i) == b.at(i))
			continue;
		else
			return 0;
	}
	return 1;
}

int solution(vector<string> user_id, vector<string> banned_id) {
	int answer = 0;
	u_size = user_id.size();
	b_size = banned_id.size();

	vector<int> ind;	// user_id���� b_size ������ŭ �̱� ���� ����
	for (int i = 0; i < u_size - b_size; i++) {
		ind.push_back(0);
	}
	for (int i = 0; i < b_size; i++) {
		ind.push_back(1);
	}

	do {
		vector<string> cho;	// Ȯ���� user_id ���� ����
		for (int i = 0; i < u_size; i++) {
			if (ind[i] == 1)
				cho.push_back(user_id[i]);
		}
		sort(banned_id.begin(), banned_id.end());

		do {
			int i = 0;
			for (i = 0; i < cho.size(); i++) {
				if (cmp(cho[i], banned_id[i]) == 1) {	// ���� ���̵��
						continue;	// ���� ���̵� ���� ���̵����� Ȯ��
				}
				break;	// ���� ���̵� �ƴ� > ���� �������� ����
			}
			if (i == cho.size()) {	// cho�� ���� ���̵��� �����̸� 
				answer++;		// ++�ϰ� ���� ���� Ȯ���� ���� break;
				break;
			}
		} while (next_permutation(banned_id.begin(), banned_id.end()));
	} while (next_permutation(ind.begin(), ind.end()));

	return answer;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// 2
	vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
	vector<string> banned_id = { "fr*d*", "abc1**" };

	// 2
	//vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
	//vector<string> banned_id = { "*rodo", "*rodo", "******" };

	// 3
	//vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
	//vector<string> banned_id = { "fr*d*", "*rodo", "******", "******" };

	// 1
	//vector<string> user_id = { "frodo", "fradi", "frodi", "froda", "frldi", "aaaaaa" };
	//vector<string> banned_id = { "fr*d*", "fr*d*", "fr*d*", "fro**", "fro**" };

	cout << solution(user_id, banned_id) << '\n';

	return 0;
}