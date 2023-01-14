using namespace std;
#include <iostream>
#pragma once

unsigned s[20], n, p1, p2;

void tipar() {
	for (int i = 0; i < n; i++) {
		if (s[i] == 0) {
			cout << '(';
		}
		else {
			cout << ')';
		}
	}
	cout << ' ';
}

int valid(int k) {
	p1 = 0;
	p2 = 0;
	for (int i = 0; i < k; i++) {
		if (s[i] == 0) {
			p1++;
		}
		else {
			p2++;
		}
	}
	if (p1 > p2 || p2 > n / 2) {
		return 0;
	}
	return 1;
}

int solutie(int k) {
	if (k == n - 1) {
		return 1;
	}
	else {
		return 0;
	}
}

void back(int k) {
	int i;
	for (i = 0; i <= 1; i++) {
		s[k] = i;
		if (valid(k)) {
			if (solutie(k)) {
				tipar();
			}
			else {
				back(k + 1);
			}
		}
	}
}

void sol20() {
	cout << "n=";
	cin >> n;
	back(0);
}