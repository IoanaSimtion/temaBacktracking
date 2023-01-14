using namespace std;
#include <iostream>
#pragma once

//sa se genereze toate numerele de n cifre care nu contin 3 cifre pare sau impare alaturate

unsigned s[20], n, nr;

void generarenr() {
	nr = 0;
	for (int i = 0; i < n; i++) {
		nr = nr * 10 + s[i];
	}
	cout << nr << endl;
}

int valid(int k) {
	for (int i = 1; i < n; i++) {
		if ((s[i - 1] % 2 == 0 && s[i] % 2 == 0) && s[i + 1] % 2 == 0) {
			return 0;
		}
		else {
			if ((s[i - 1] % 2 == 1 && s[i] % 2 == 1) && s[i + 1] % 2 == 1) {
				return 0;
			}
		}
	}

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
	for (val = 0; val < 10; val++) {
		if (val == 0 && k == 0) {
			val++;
		}
		else {
			s[k] = val;
			if (valid(k)) {
				//cout << "v" << endl;
				if (solutie(k)) {
					generarenr();
				}
				else {
					back(k + 1);
				}
			}
		}
	}
}


void sol3() {
	cout << "n=";
	cin >> n;
	back(0);
}