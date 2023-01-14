using namespace std;
#include <iostream>
#pragma once

//sa se scrie toate numerele a caror scriere in baza 10 foloseste numai
//cifre din sirul primelor m cifre distincte ale lui n (cele mai mici)
//numerele nu vor contine mai mult de m cifre

unsigned s[20], n, m, cifre[20], dim = 0, nr;

void vectorCifre() {
	int x;
	x = n;
	while (x) {
		cifre[dim] = x % 10;
		x /= 10;
		dim++;
	}
}

void sortVector() {
	bool flag = 1;
	do {
		flag = 1;
		for (int i = 0; i < dim - 1; i++) {
			if (cifre[i] > cifre[i + 1]) {
				swap(cifre[i], cifre[i + 1]);
				flag = 0;
			}
		}
	} while (flag == 0);
}

void eliminareElement(int poz) {
	for (int i = poz; i < dim - 1; i++) {
		cifre[i] = cifre[i + 1];
	}
	dim--;
}

void eliminareDubluri() {
	for (int i = 0; i < dim - 1; i++) {
		if (cifre[i] == cifre[i + 1]) {
			eliminareElement(i);
			i--;
		}
	}
}

void tipar(int k) {
	nr = 0;
	for (int i = 0; i <= k; i++) {
		nr = nr * 10 + s[i];
	}
	cout << nr << ' ';
}


int solutie(int k) {
	if (k <= m) {
		return 1;
	}
	else {
		return 0;
	}
}

void back(int k) {
	unsigned val;
	for (val = 0; val < m; val++) {
		s[k] = cifre[val];
		if (solutie(k)) {
			tipar(k);
		}
		else {
			back(k + 1);
		}
		
	}
}


void sol7() {
	cout << "n=";
	cin >> n;
	cout << "m=";
	cin >> m;
	vectorCifre();
	sortVector();
	eliminareDubluri();

	/*for (int i = 0; i < dim; i++) {
		cout << cifre[i] << ' ';
	}*/

	back(0);
}