#include "szoveg.h"

int random() {
	int szam = (rand() % 10) + 1;
	return szam;
}

bool osszeadas() { //ellenség éltalálását dönti el
	bool sikeres_e;
	int valasz;
	int r1 = random(), r2 = random();
	cout << "Ahhoz, hogy kitérj adj választ a kérdésre.";
	cout << "Mennyi " << r1 << "+" << r2 << "?\n";
	cin >> valasz;
	if (valasz == r1 + r2)
		sikeres_e = true;
	else
		sikeres_e = false;
	return sikeres_e;
}

void var() {// várakozás a játékosra
	cout << "\nNyomd meg az Entert a továbbhaladáshoz!";
	cin.get();
}

void szintlepes(jatekos& a) {//szörny legyõzése után megnézi zsintet lépett e a játékos
	if (a.getXP() >= a.getSzukseges_tp()) {
		a.setLvl_plus();
		cout << "\nElérted a " << a.getLvl() << "-as/es szintet.";
		a.setXP(0);
	}
	var();
}

void belepes(jatekos& x) {//játékos inicializálása
	std::cout << "Üdvözöllek!\n" << "A játék elkezdéséhez add meg a neved!\n";
	string nev;
	getline(cin, nev);
	x.setName(nev);
}

void elso_kuldetes(jatekos& a, vektor<fegyver>& taska, vektor<fegyver> fegyverek, string valasz) {//elsõ küldetés megkapása
	system("cls");
	cout << "Egy erdõ szélén ébredsz a fejed pedig hasogat, nem emlékszel semmire.";
	Sleep(2000);
	cout << "\n" << "..." << "\n";
	Sleep(2000);
	cout << "Valami zajt hallasz az egyik bokorból." << "\n" << "Odamész megnézni mit rejt?[igen,nem]" << "\n";
retry:
	cin >> valasz;
	cin.ignore(10000, '\n');
	if (valasz == "igen" || valasz == "nem") {
		if (valasz == "igen") {
			cout << "Ahogy közelebb lépsz a bokorhoz egy goblin ugrik ki onnan." << "\n";
			Sleep(2000);
		}
		else {
			cout << "Ahogy tovább akasz menni egy goblin integet a bokorból. Odamész hozzá megnézni mit akar.";
			Sleep(2000);
		}
	}
	else {
		cout << "Igen vagy nemmel válaszolj!\n";
		Sleep(2000);
		goto retry;

	}
	fegyver rozsdas_kard = fegyverek.return_elem(0);
	fegyver vas_kard = fegyverek.return_elem(1);
	taska.push_back(vas_kard);
	taska.push_back(rozsdas_kard);
	cout << "Ismeretlen goblin: Szervusz " << a.getName() << "!" << "\nFényeskalapács Klemnek hívnak, ez az én erdõm. Pont jókor jössz, segítségre lenne szükségem. Már napok óta Tûzeshátú Blobok falják fel a gombáimat. Munkádat ajándékkal hálálom meg.";
	cout << "\nKlem:Itt egy kard jól fog jönni. \nMegszerezted a [Rozsdás kardot]és a [Lángoló Acél kardot]";
	a.setTerheles(rozsdas_kard.getSuly());
	a.setTerheles(vas_kard.getSuly());
	cout << "\nTerhelésed: " << a.getTerheles() << "/" << a.getHati();
	var();

}

void fegyver_valaszt(jatekos& a, vektor<fegyver> taska, fegyver& valasztott_fegyver, int& valasz) {// harchoz a fegyver kiválasztása
retry1:
	cout << "\nVálassz fegyvert!\n";
	for (int i = 0; i < taska.getSize(); ++i) {
		cout << i + 1 << ".:" << taska.return_elem(i).getName() << " típusa: " << taska.return_elem(i).getType() << endl;//fegyverek felsorolása a játékos számára
	}
	cout << "\nÍrd be a fegyver számát!\n";
	cin >> valasz;
	cin.ignore(10000, '\n');
	if (valasz <= taska.getSize()) {
		valasztott_fegyver = taska.return_elem(valasz - 1);
	}
	else {
		cout << "Nem megfelelõ számot adtál meg.\n";
		Sleep(1500);
		goto retry1;
	}
}

void kuldetesek(jatekos& a, vektor<fegyver> taska, vektor<szorny> szorny_t, string& valasz, vektor<fegyver> fegyverek) {// többi kuldetés és harcok
	fegyver valasztott_fegyver;
	int r_szam;
	int fegyver_sorszam;
	system("cls");
	Sleep(1000);
	cout << "Elidulsz befele az erdõ közepére. Nem jutsz messzire mire megpillantasz egy blobot aki éppen gombával tömi magát. Rákiabálsz mire õ elindul feléd.\n";
	cout << "\nKészülj a harcra a Blob már támadásra kész.";
	var();
	cout << "\nTipp: Minden ellenségnek megvan a maga tulajdonsága. Egyes tulajdonságok ellen erõsebb vagy, ha jol választod meg a fegyvered. Minden harc elött megtudod milyen tipusú ellenséggel harcolsz és ez alapján választhatod meg a fegyvert. Harc közben elõfordulhat, hogy könnyebb kérdésekre kell választ adj.\n";
	var();
	cout << "\nBlob tulajdonságai:\n" << "életereje: " << szorny_t.return_elem(0).getHP() << "\ntípusa: " << szorny_t.return_elem(0).getType() << endl;
	fegyver_valaszt(a, taska, valasztott_fegyver, fegyver_sorszam);//fegyver kiválasztása
	if (valasztott_fegyver.getType() == szorny_t.return_elem(0).getGyenge()) {//ha jó fegyvert választunk erösebbek vagyunk ellene
		valasztott_fegyver.setEro(valasztott_fegyver.getEro() + 2);
	}
	vektor<fegyver> taska2;
	fegyver rozsdas_kard("Rozsdás Kard", 15, 4, "víz");
	fegyver vas_kard("Lángoló Acél kard", 20, 15, "tûz");
	taska2.push_back(vas_kard);
	taska2.push_back(rozsdas_kard);
	cout << "A blob már csak egy kardcsapásnyira van. Rásuhintasz egyet? [igen,nem]\n";
	cin >> valasz;
	cin.ignore(10000, '\n');
	if (valasz == "igen") {
		szorny temp;
		cout << "\nTalált az elsõ ütésed. A blob élete csökkent.";
		temp = szorny_t.return_elem(0);
		temp.setHP(temp.getHP() - (valasztott_fegyver.getEro() + a.getEro()));
		szorny_t.csere(0, temp);
		cout << "\n Blob életereje:" << szorny_t.return_elem(0).getHP();
		cout << "\nA Blob már támad is. Megpróbálsz kitérni?[igen,nem]\n";
		cin >> valasz;
		cin.ignore(10000, '\n');
		if (valasz == "igen") {
			if (osszeadas() == true)//összeadásos feladat kiírása sikeres 
				cout << "Sikerült kitérj.";
			else {
				cout << "\nRossz válasz. A blob megütött.";
				a.setHP(a.getHP() - szorny_t.return_elem(0).getEro());
				cout << "\nÉleterõd csökkent: " << a.getHP() << "-ra/re.";

			}
		}
	}
	else if (valasz == "nem") {
		cout << "\nA Blob támadásba lendült. Nem tudtál kitérni az ütése elöl.";
		Sleep(2000);
		a.setHP(a.getHP() - szorny_t.return_elem(0).getEro());
		cout << "\nÉleteröd csökkent:" << a.getHP() << "-ra/re.";
		Sleep(2000);
		cout << "\nMire észhez kapsz a blob már újra támad.";
		cout << "\nMegpróbálsz kitérni?[igen,nem]\n";
	retry2:
		cin >> valasz;
		cin.ignore(10000, '\n');
		if (valasz == "igen" || valasz == "nem") {
			if (valasz == "igen") {
				cout << "\nEz csak a szerencsén múlik. Ha 5 alatti számot sorsol a gép akkor kitértél.";
				Sleep(3000);
				r_szam = random();
				if (r_szam < 5) {
					cout << "\nSikerült kitérj. A számod: " << r_szam;
					Sleep(2000);
				}
				else {
					cout << "\nSajnos nem tudtál kitérni. A számod: " << r_szam;
					a.setHP(a.getHP() - szorny_t.return_elem(0).getEro());
					cout << "\nÉleterõd csökkent:" << a.getHP() << "-ra/re.";
					Sleep(2000);
				}
			}
			else {
				a.setHP(a.getHP() - szorny_t.return_elem(0).getEro());
				cout << "\nÉleterõd csökkent:" << a.getHP() << "-ra/re.";
				Sleep(2000);
			}
		}
		else {
			cout << "Igennel vagy nemmel válaszolj!";
			Sleep(2000);
			goto retry2;
		}
	}
	while (szorny_t.return_elem(0).getHP() > 0) {
		cout << "\n\nTe következel. Rásuhintasz a Blobra. A találatod csak a szerencsétõl függ. (Ha a szám <8 akkor eltalálod)";
		Sleep(3500);
		r_szam = random();
		if (r_szam < 8) {
			cout << "\nEltaláltad. A számod: " << r_szam;
			szorny temp;
			temp = szorny_t.return_elem(0);
			temp.setHP(temp.getHP() - (valasztott_fegyver.getEro() + a.getEro()));
			szorny_t.csere(0, temp);
			if (szorny_t.return_elem(0).getHP() <= 0) {//szörny halála
				cout << "\nGratulálok! Sikeresen legyõzted a Blobot!";
				Sleep(1500);
				cout << "Szereztél 100 tapasztalatpontot.";
				a.setXP(100);
				szintlepes(a);
				break;
			}
			cout << "\nA Blob életereje csökkent " << szorny_t.return_elem(0).getHP() << "-ra/re.";
			Sleep(2000);
		}
		else {
			cout << "\nSajnos nem találtad el. A számod: " << r_szam;
			Sleep(2000);
		}
		cout << "\nA Blob támad.Megpróbálsz kitérni?[igen, nem]\n";
	retry3:
		cin >> valasz;
		cin.ignore(10000, '\n');
		if (valasz == "igen" || valasz == "nem") {
			if (valasz == "igen") {
				cout << "\nEz csak a szerencsén múlik. Ha 5 alatti számot sorsol a gép akkor kitértél.";
				Sleep(1500);
				r_szam = random();
				if (r_szam < 5) {
					cout << "\nSikerült kitérj. A számod: " << r_szam;
					Sleep(1500);
				}
				else {
					cout << "\nSajnos nem tudtál kitérni. A számod: " << r_szam;
					a.setHP(a.getHP() - szorny_t.return_elem(0).getEro());
					cout << "\nÉleterõd csökkent:" << a.getHP() << "-ra/re.";
					Sleep(2000);
				}
			}
			else {
				cout << "\nA Blob megütött";
				cout << "\nÉleterõd csökkent:" << a.getHP() << "-ra/re.";
				Sleep(2000);
			}
		}
		else {
			cout << "Igennel vagy nemmel válaszolj!";
			Sleep(2000);
			goto retry3;
		}
	}
	cout << "\nAmint a Blob a földre zuhant a messzeségbe megjelenik Klem.\n";
	a.setHatizsak_m(a.getHP());//életerõ csökkenésével csökken a hátizsák mérete
	Sleep(2500);
	cout << "\nKlem: Nagyon köszönöm a segítséged. Tessék itt van a megígért ajándék.";
	Sleep(2000);
	cout << "\nSzereztél 1 [Életerõ italt] ";
	cout << "\nMegittad az életerõ italt. Kaptál +10 életerõt.";
	a.setHP(a.getHP() + 10);
	var();

	if (a.getHP() > 100) {
		a.setHP(100);
	}
	if (a.getTerheles() > a.getHati()) {
		cout << "\nNem fér el több dolog a táskádba. Dobd el az egyik tárgyad.";
		fegyver_valaszt(a, taska, valasztott_fegyver, fegyver_sorszam);
		taska.pop(fegyver_sorszam - 1);
	}
	cout << "\n";
	//2.kuldetes
	cout << "\nTovább indulsz az erdõ közepe felé és a fák fölött kibukkan egy kastély tornya. Elindulsz felé, de ahogy közeledsz sikitozást hallasz. Odamész?[igen,nem]\n ";
	Sleep(2000);
	fegyver valasztott_fegyver_2;
retry4:
	cin >> valasz;
	cin.ignore(10000, '\n');
	if (valasz == "igen" || valasz == "nem") {
		if (valasz == "igen") {
			cout << "\nEgyre közelebb érsz és megpillantasz egy háromfejû kutya. Valamit nagyon õriz...";
			Sleep(2000);
			cout << "\nHogy megtudd mi az le kell gyõzd.";
			Sleep(1500);
			cout << "\nKészen állsz a harcra?";
			var();
			cout << "\nA kutya adatai:\n" << "élete: " << szorny_t.return_elem(1).getHP() << "\ntipusa: " << szorny_t.return_elem(1).getType();//szörny adatainak kiírása

			fegyver_valaszt(a, taska2, valasztott_fegyver_2, fegyver_sorszam);
			if (valasztott_fegyver_2.getType() == szorny_t.return_elem(0).getGyenge()) {//ha jó fegyvert választunk erösebbek vagyunk ellene
				valasztott_fegyver_2.setEro(valasztott_fegyver_2.getEro() + 2);
			}
			szorny temp = szorny_t.return_elem(1);
			while (temp.getHP() > 0) {
				cout << "\nRásuhintasz a kutyára.";
				if (osszeadas() == true) {//sikeres támadás
					temp.setHP(temp.getHP() - valasztott_fegyver_2.getEro());
					cout << "\nEltaláltad a kutyát. Életereje csökkent." << temp.getHP() << "-ra/re.";
					if (temp.getHP() <= 0) {//játék vége gyõztél
						cout << "\nGratulálok legyõzted a kutyát. Amint odalépsz a kutya holttestéhez észreveszed a kincset amit örzött.";
						Sleep(2000);
						cout << "\nEgy arany kulcs az. Vajon mire lehet jó?";
						Sleep(3000);
						cout << "\nOdaérsz a kastélyhoz és egy nagy díszes kapu fogad, elhagytottnak tûnik. Belepróbálod a kulcsot a kapuba ami szerencsédre pont azt nyitja.";
						Sleep(3000);
						cout << "\nBelépsz a kastélyba ahol egy papiruszt találsz amin ez áll: ";
						Sleep(3000);
						cout << "\nCsak az tud belépni ebbe a kastélyba aki méltó rá és képes megszerezni a kulcsot.\n Ettöl a pillanattól kezdve ez a kastély a tiéd.";
						Sleep(3000);
						cout << "\nEzután berendeszkedtél a kastélyba, mindent visszaállítottál a régi pompájába és boldogan éltél amég meg nem haltál.";

					}
				}
				else {//sikertelen támadás
					cout << "\nHelytelen válasz. Nem találtad el a kutyát.";
				}
			}
		}
		else if (valasz == "nem") {
			cout << "\nTovább indultál. Már bandukolsz egy ideje, de a fáradtságodat felülmúlja az éhség.";
			Sleep(2000);
			cout << "\nMegpillantasz egy bokornyi piros bogyot. Neki is esel, de nem sok örömöd lesz belõle.";
			Sleep(2000);
			cout << "\nNem sokkal a lakoma után már az élettelen tested az út szélén hever.";
			Sleep(2000);
			cout << "\nMeghaltál a játéknak vége. Elért szinted: " << a.getLvl();
		}
	}
	else {
		cout << "Igennel vagy nemmel valaszolj.\n";
		goto retry4;
	}
}
