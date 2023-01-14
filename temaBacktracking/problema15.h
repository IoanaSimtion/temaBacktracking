using namespace std;
#include <iostream>
#pragma once

/*fie vectorul A ce contine n nr intregi
doua elemente formeaza o "pereche in dezordine" daca sunt indeplinite simultan conditiile:
i<j, unde 1<=i<n si 1<j<=n
a[i]>a[j]
sa se generezxe toate sirurile care contin acelasi numar de perechi in dezordine ca al vectorului initial
*/

unsigned s[20], A[20], n, nrP = 0;

void nrPerechiDezordineA() {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (A[i] > A[j]) {
				nrP++;
			}
		}
	}
}

int ctPerechiDezordineA() {
	int ctP = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (s[i] > s[j]) {
				ctP++;
			}
		}
	}
	return ctP;
}

void tipar() {
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << s[i] << ' ';
	}
}

int valid(int k) {
	bool flag = 0;
	for (int i = 0; i < k; i++) {
		if (s[k] == s[i]) {
			return 0;
		}
	}
	for (int i = 0; i < n; i++) {
		if (s[i] != A[i]) {
			flag = 1;
		}
	}
	if (flag == 0) {
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
	unsigned val;
	for (val = 0; val < n; val++) {
		s[k] = A[val];
		if (valid(k)) {
			if (solutie(k)) {
				if (ctPerechiDezordineA() == nrP) {
					tipar();
				}
			}
			else {
				back(k + 1);
			}
		}
	}
}

void sol15() {
	cout << "n=";
	cin >> n;
	cout << "Introduceti elementele vectorului: ";
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	nrPerechiDezordineA();
	back(0);
}