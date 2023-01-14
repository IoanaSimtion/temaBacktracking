using namespace std;
#include <iostream>
#pragma once

//sa se afiseze toate submultimile de suma S formate din cifrele lui n

unsigned s[20], n, S, cifre[20], dim = 0, suma;

void vectorCifre() {
	int m;
	m = n;
	while (m) {
		cifre[dim] = m % 10;
		m /= 10;
		dim++;
	}
}

void tipar(int k) {
	cout << endl;
	for (int i = 0; i <= k; i++) {
		cout << s[i] << ' ';
	}
}

int valid(int k) {
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
	suma = 0;
	for (int i = 0; i <= k; i++) {
		suma += s[i];
	}
	if (suma > S) {
		return 0;
	}
	return 1;
}


int solutie(int k) {
	if (suma == S) {
		return 1;
	}
	else {
		return 0;
	}
	if (k > 1 && k < dim) {
		return 1;
	}
	else {
		return 0;
	}
}

void back(int k) {
	unsigned val;
	for (val = 0; val < dim; val++) {
		s[k] = cifre[val];
		if (valid(k)) {
			if (solutie(k)) {
				tipar(k);
			}
			else {
				back(k + 1);
			}
		}
	}
}

void sol8() {
	cout << "n=";
	cin >> n;
	cout << "S=";
	cin >> S;
	vectorCifre();
	back(0);
}