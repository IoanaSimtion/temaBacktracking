using namespace std;
#include <iostream>
#pragma once

//sa se scrie toate sirurile de n nr prime alese din cele m nr
//(primele m numere prime de cel putin 2 cifre)

unsigned s[20], n, m, nrPrime[50], nrPrim=11;

bool ePrim(int nr) {
	for (int i = 2; i < nr / 2; i++) {
		if (nr % i == 0) {
			return 0;
		}
	}
	return 1;
}

void generareNrPrime() {
	int x = 0;
	while (x < m) {
		if (ePrim(nrPrim)) {
			nrPrime[x] = nrPrim;
			x++;
		}
		nrPrim += 2;		
	}
}

void tipar() {
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << s[i] << ' ';
	}
}

int valid(int k) {
	for (int i = 0; i < k; i++) {
		if (s[k] == s[i]) {
			return 0;
		}
	}
	return 1;
}

int solutie(int k) {
	if (k == (n - 1)) {
		return 1;
	}
	else {
		return 0;
	}
}

void back(int k) {
	unsigned val;
	for (val = 0; val < m; val++) {
		s[k] = nrPrime[val];
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

void sol5() {
	cout << "n=";
	cin >> n;
	cout << "m=";
	cin >> m;
	generareNrPrime();
	
	/*for (int i = 0; i < m; i++) {
		cout << nrPrime[i] << endl;
	}*/

	back(0);
}