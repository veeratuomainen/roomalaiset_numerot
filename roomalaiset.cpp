#include <iostream>
using namespace std;

int muutaDesimaaliksi(string rooma) {
	int tulos = 0;
	int pituus;
	pituus = rooma.size();
	
	for (int i = 0; i < pituus; i++) {
		switch (rooma[i]) {
			case 'I':
				tulos += 1;
				break;
			case 'V':
				tulos += 5;
				break;
			case 'X':
				tulos += 10;
				break;
			case 'L':
				tulos += 50;
				break;
			case 'C':
				tulos += 100;
				break;
			case 'D':
				tulos += 500;
				break;
			case 'M':
				tulos += 1000;
				break;
		}
	}
	
	for (int i = 1; i < pituus; i++) {
		if ((rooma[i] == 'V' || rooma[i] == 'X') && rooma[i - 1] == 'I') {
			tulos -= 1 + 1;
		}
		if ((rooma[i] == 'L' || rooma[i] == 'C') && rooma[i - 1] == 'X') {
			tulos -= 10 + 10;
		}
		if ((rooma[i] == 'D' || rooma[i] == 'M') && rooma[i - 1] == 'C') {
			tulos -= 100 + 100;
		}
	}
	
	return tulos;
}

int main() {
	string roomalainen;
	int desimaali;
	
	cout << "Roomalainen luku, jonka desimaaliarvon haluat tietää? ";
	cin >> roomalainen;
	
	desimaali = muutaDesimaaliksi(roomalainen);
	
	cout << "Desimaalimuodossa roomalainen luku " << roomalainen << " on " << desimaali << endl;
	
	return 0;
}