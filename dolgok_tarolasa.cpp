#include "dolgok_tarolasa.h"

void szorny_betoltes(vektor<szorny>& szornyek) {
	szorny blob, kutya;
	ifstream ifs;
	ifs.open("kutya.txt");
	if (ifs.is_open()) {
		ifs >> kutya;
		ifs.close();
	}

	ifs.open("blob.txt");
	if (ifs.is_open()) {
		ifs >> blob;
		ifs.close();
	}

	szornyek.push_back(blob);
	szornyek.push_back(kutya);

}

void fegyver_betoltes(vektor<fegyver>& bag) {
	fegyver rozsdas_kard("Rozsd�s Kard", 15, 4, "v�z"), acel_kard("L�ngol� Ac�l kard", 20, 8, "t�z");
	bag.push_back(rozsdas_kard);
	bag.push_back(acel_kard);
}