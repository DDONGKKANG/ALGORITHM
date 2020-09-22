/*
programmers : ¡�˴ٸ� �ǳʱ�
solved by JY
�̺� Ž�� ���
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int check(vector<int>& stones, int mid, int k) {	// mid ��° ģ���� �ǳ� �� �ִ� �� Ȯ��
	int count = 0;
	for (int i = 0; i < stones.size(); i++) {
		if (stones[i] < mid) {	// stones�� mid���� ���� ��� �ǳʶپ�� ��.
			count++;
			if (count == k)		// �ǳʶ� ������ k���� �Ǹ� mid ģ���� �ǳ� �� ����.
				return 0;
		}
		else
			count = 0;			// ���� ���� ������ count �ʱ�ȭ
	}

	return 1;
}

int solution(vector<int> stones, int k) {
	int answer = 0;
	int mini = *min_element(stones.begin(), stones.end());
	int maxi = *max_element(stones.begin(), stones.end());

	while (mini < maxi) {
		int mid = (mini + maxi + 1) / 2;

		if (check(stones, mid, k)) {	// mid�� ������ ���
			mini = mid;
			answer = mid;
		}
		else {	// mid�� �Ұ����� ���
			maxi = mid - 1;
		}
	}

	if (mini == maxi) {	// ��� stones ������ ���, ���� ���� ��(or ū ��)�� �Ǵ� ���..��
		if (check(stones, mini, k))	
			answer = mini;
	}

	return answer;
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// k = 3 > 3
	//vector<int> stones = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 };
	int k = 2;
	
	// k = 6 > 4
	//vector<int> stones = { 1, 1, 1, 1, 2, 4, 5, 3, 2, 1, 4, 2, 5, 1, 1, 1, 1, 1};
	
	// k = 6 > 1
	//vector<int> stones = { 1, 1, 1, 1, 2, 4, 5, 3, 2, 1, 4, 2, 5, 1, 1, 1, 1, 1, 1 };

	// k = 3 > 2
	//vector<int> stones = { 2, 2, 2, 2, 2, 4, 5, 3, 2, 1, 4, 2, 5, 2, 2, 2, 2, 2, 2 };

	vector<int> stones = { 200000000, 200000000, 5, 200000000, 4, 200000000, 5, 200000000 };

	//vector<int> stones = { 2 };

	cout << solution(stones, k) << '\n';

	return 0;
}