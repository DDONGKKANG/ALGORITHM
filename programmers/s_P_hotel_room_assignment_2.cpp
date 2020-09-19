#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#define ll long long

using namespace std;

ll find(map < ll, ll > &rooms, ll v) {
	if (rooms.count(v) == 0) {	// ���� �����
		return v;
	}
	return rooms[v] = find(rooms, rooms[v] + 1);
}

vector<ll> solution(ll k, vector<ll> room_number) {
	vector<ll> answer;
	map < ll, ll > rooms;

	for (int i = 0; i < room_number.size(); i++) {
		if (rooms.count(room_number[i]) != 0) {		// ������ ����
			ll num = find(rooms, room_number[i]);	// ���� �� ã��
			rooms.insert(make_pair(num, num));
			answer.push_back(num);
		}
		else {	// ���� �����
			rooms.insert(make_pair(room_number[i], room_number[i]));
			answer.push_back(room_number[i]);
		}
	}
	return answer;
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll k = 10;
	vector<ll> room_number = { 1,3,4,1,3,1 };

	vector <ll> ans;
	ans = solution(k, room_number);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}