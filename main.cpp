#include "fegyver.h"
#include "Jatekos.h"
#include "targyak.h"
#include "szoveg.h"
#include "dolgok_tarolasa.h"
using namespace std;
int main() {
	try {
		srand((unsigned)time(0));
		setlocale(LC_ALL, "");
		jatekos x;
		string valasz;
		vektor<fegyver> fegyverek;
		vektor<fegyver> taska;
		vektor<szorny> szornyek;
		szorny_betoltes(szornyek);
		fegyver_betoltes(fegyverek);
		belepes(x);
		elso_kuldetes(x, taska, fegyverek, valasz);
		kuldetesek(x, taska, szornyek, valasz,fegyverek);
	}
	catch (const runtime_error& e) {
		cerr << e.what() << endl;
	}
	return 0;
}