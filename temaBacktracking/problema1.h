using namespace std;
#include <iostream>
#pragma once

//sa se genereze toate sirurile de lungime m formate din
//divizori ai unui numar natural x, in ordine crescatoare 

unsigned s[20], m, x;

void tipar() {
	cout << endl;
	for (int i = 0; i < m; i++) {
		cout << s[i] << ' ';
	}
}

int valid(int k) {
	if (x % s[k] != 0) {
		return 0;
	}
	for (int i = 0; i < k; i++) {
		if (s[k] == s[i]) {
			return 0;
		}
	}
	for (int i = 0; i < k; i++) {
		if (s[i] > s[i + 1]) {
			return 0;
		}
	}
	return 1;
}

int solutie(int k) {
	if (k == m - 1) {
		return 1;
	}
	else {
		return 0;
	}
}

void back(int k) {
	unsigned val;
	for (val = 1; val <= x; val++) {
		s[k] = val;
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


void sol1() {
	cout << "x=";
	cin >> x;
	cout << "m=";
	cin >> m;
	back(0);
}