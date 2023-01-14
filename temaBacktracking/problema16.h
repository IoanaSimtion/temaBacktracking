using namespace std;
#include <iostream>
#pragma once

//sa se genereze toate permutarile vectorului A (n nr intregi)
//conditie: cel mai mic si cel mai mare nr sa ramana pe poz initiale

unsigned A[20], n, s[20], pMin = 0, minim = INT_MAX, pMax = 0, maxim = 0;

void pozMin() {
	for (int i = 0; i < n; i++) {
		if (A[i] < minim) {
			minim = A[i];
			pMin = i;
		}
	}
}

void pozMax() {
	for (int i = 0; i < n; i++) {
		if (A[i] > maxim) {
			maxim = A[i];
			pMax = i;
		}
	}
}

void tipar() {
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << s[i] << ' ';
	}
}

int valid(int k) {
	//cout << "s[pmin]=" << s[pMin] << endl;
	if (s[pMin] != minim) {
		return 0;
	}
	if (s[pMax] != maxim) {
		return 0;
	}
	for (int i = 0; i < k; i++) {
		if (s[k] == s[i]) {
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
	unsigned val;
	for (int val = 0; val < n; val++) {
		s[k] = A[val];
		if (valid(k)) {
			cout << "V" << endl;
			if (solutie(k)) {
				tipar();
			}
			else {
				back(k + 1);
			}
		}
	}
}

void sol16() {
	cout << "n=";
	cin >> n;
	cout << "Introduceti elementele vectorului: ";
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	pozMin();
	pozMax();
	back(0);
}