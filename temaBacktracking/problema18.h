using namespace std;
#include <iostream>
#include <math.h>
#pragma once

//sa se determine toate modurile de asezare a n dame pe tabla de sah 
//ai sa nu se atace reciproc

unsigned n, m, s[50];

void tipar() {
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i] == j) {
				cout << "d ";
			}
			else {
				cout << "- ";
			}
		}
		cout << endl;
	}
	
}

int valid(int k) {
	for (int i = 0; i < k; i++) {
		int dif = s[k] - s[i];
		if (s[k] == s[i] || (abs(dif) == (k - i))) {
			return 0;
		}
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
	for (i = 0; i < n; i++) {
		s[k] = i;
		if (valid(k)) {
			if (solutie (k)) {
				tipar();
			}
			else {
				back(k + 1);
			}
		}
	}
}

void sol18() {
	cout << "n=";
	cin >> n;
	cout << "m=";
	cin >> m;
	back(0);
}