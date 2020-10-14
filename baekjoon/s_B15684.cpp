/*
baekjoon 15684 : ��ٸ� ����
solved by JY
DATE : 2020.10.15
dfs�� �̿�
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#define INF 1e9
#define min(a,b) a>b?b:a

using namespace std;

int n, m, h, a, b, ans = INF;
int array[33][11] = {0,};

bool is_ok() {  // �ڱ� �ڽ��� �Ǵ��� Ȯ��
    for (int i = 1; i <= n; i++) {
        int col = i;
        for (int j = 1; j <= h; j++) {
            if (array[j][col - 1] == 1)  // �������� ����
                --col;
            else if (array[j][col] == 1)  // ���������� ����
                ++col;

            if (j == h && col != i)
                return false;
        }
    }
    return true;
}

void dfs(int r, int num) {
    if (num > 3) return ;

    if (is_ok()) {  // ���� ���� �� �ּڰ� ����
        ans = min (ans, num);
        return ;
    }

    for (int i=r; i<=h; i++)
        for (int j=1; j<n; j++) {   // ���μ�
            if (array[i][j] == 1) continue;     // j�� j+1 ���μ� ���̿� ���� ������ continue
            if (array[i][j-1] == 1) continue;   // j-1�� j ���μ� ���̿� ���� ������ continue
            if (array[i][j+1] == 1) continue;   // j+1�� j+2 ���μ� ���̿� ���� ������ continue

            array[i][j] = 1;    // j�� j+1 ���μ� ���̿� ���� ����
            dfs(i, num + 1);    // dfs
            array[i][j] = 0;    // j�� j+1 ���μ� ���̿� �� ����
        }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> h;

    if (m == 0) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        array[a][b] = 1;    // a��° �ٿ� ���μ� b�� b+1 ���̿� ���� ����
    }

    dfs(1, 0);  // 1�� ° �ٺ��� ����!

    if (ans == INF) cout << -1;
    else cout << ans;

    return 0;
}