/*
baekjoon 1931 : ȸ�ǽǹ���
solved by JY
*/
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

pair <int, int> p[100001];

/*
�Ʒ�ó�� ����ü�� �ؼ� sort �Ҷ�
sort (a, a+n); �׳� �ϸ� ��

struct ti {
	int st;
	int et;

	bool operator<(ti a) const {
		if (et == a.et)
			return st < a.st;
		return et < a.et;
	}
};
*/


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >>  p[i].second >> p[i].first;
	}

	int a = 0, b = 1;
	int check = 1;

	sort(p, p + n);

	while (1) {
		if (p[a].first <= p[b].second) {
			check++;
			a = b;
		}
		b++;

		if (b == n)
			break;
	}

	cout << check;

	return 0;
}