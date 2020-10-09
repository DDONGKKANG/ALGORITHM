/*
baekjoon 6209 : ���ڸ� �ָ��ٱ� 
solved by JY
DATE : 2020.10.09
�̺� Ž������ Ǯ��
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define ll long long
#define max(a,b) a>b?a:b

using namespace std;

ll d;
int n, m;
vector< ll > dist;

bool check(ll mid) {
    int cnt = 0;
    ll diff = 0;
    for (int i = 0; i < n + 1; i++) {
        diff += dist[i + 1] - dist[i];
        if (diff < mid) {               // ���� �� ������ mid���� ���� ���
            cnt++;                      // ����
            if (cnt > m) return false;  // mid�� ������ �� �� ����.
        } else
            diff = 0;
    }
    return true;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int tmp;

    cin >> d >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        dist.push_back(tmp);
    }
    dist.push_back(0);
    dist.push_back(d);
    sort(dist.begin(), dist.end());

    ll left = 0, right = d, ans = 0;
    while(left < right) {
        ll mid = (left + right + 1) / 2;
        if (check(mid)) {
            ans = left = mid;
        }
        else
            right = mid - 1;
    }

    cout << ans;

	return 0;
}