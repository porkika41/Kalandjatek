#include "szoveg.h"

int random() {
	int szam = (rand() % 10) + 1;
	return szam;
}

bool osszeadas() { //ellens�g �ltal�l�s�t d�nti el
	bool sikeres_e;
	int valasz;
	int r1 = random(), r2 = random();
	cout << "Ahhoz, hogy kit�rj adj v�laszt a k�rd�sre.";
	cout << "Mennyi " << r1 << "+" << r2 << "?\n";
	cin >> valasz;
	if (valasz == r1 + r2)
		sikeres_e = true;
	else
		sikeres_e = false;
	return sikeres_e;
}

void var() {// v�rakoz�s a j�t�kosra
	cout << "\nNyomd meg az Entert a tov�bbhalad�shoz!";
	cin.get();
}

void szintlepes(jatekos& a) {//sz�rny legy�z�se ut�n megn�zi zsintet l�pett e a j�t�kos
	if (a.getXP() >= a.getSzukseges_tp()) {
		a.setLvl_plus();
		cout << "\nEl�rted a " << a.getLvl() << "-as/es szintet.";
		a.setXP(0);
	}
	var();
}

void belepes(jatekos& x) {//j�t�kos inicializ�l�sa
	std::cout << "�dv�z�llek!\n" << "A j�t�k elkezd�s�hez add meg a neved!\n";
	string nev;
	getline(cin, nev);
	x.setName(nev);
}

void elso_kuldetes(jatekos& a, vektor<fegyver>& taska, vektor<fegyver> fegyverek, string valasz) {//els� k�ldet�s megkap�sa
	system("cls");
	cout << "Egy erd� sz�l�n �bredsz a fejed pedig hasogat, nem eml�kszel semmire.";
	Sleep(2000);
	cout << "\n" << "..." << "\n";
	Sleep(2000);
	cout << "Valami zajt hallasz az egyik bokorb�l." << "\n" << "Odam�sz megn�zni mit rejt?[igen,nem]" << "\n";
retry:
	cin >> valasz;
	cin.ignore(10000, '\n');
	if (valasz == "igen" || valasz == "nem") {
		if (valasz == "igen") {
			cout << "Ahogy k�zelebb l�psz a bokorhoz egy goblin ugrik ki onnan." << "\n";
			Sleep(2000);
		}
		else {
			cout << "Ahogy tov�bb akasz menni egy goblin integet a bokorb�l. Odam�sz hozz� megn�zni mit akar.";
			Sleep(2000);
		}
	}
	else {
		cout << "Igen vagy nemmel v�laszolj!\n";
		Sleep(2000);
		goto retry;

	}
	fegyver rozsdas_kard = fegyverek.return_elem(0);
	fegyver vas_kard = fegyverek.return_elem(1);
	taska.push_back(vas_kard);
	taska.push_back(rozsdas_kard);
	cout << "Ismeretlen goblin: Szervusz " << a.getName() << "!" << "\nF�nyeskalap�cs Klemnek h�vnak, ez az �n erd�m. Pont j�kor j�ssz, seg�ts�gre lenne sz�ks�gem. M�r napok �ta T�zesh�t� Blobok falj�k fel a gomb�imat. Munk�dat aj�nd�kkal h�l�lom meg.";
	cout << "\nKlem:Itt egy kard j�l fog j�nni. \nMegszerezted a [Rozsd�s kardot]�s a [L�ngol� Ac�l kardot]";
	a.setTerheles(rozsdas_kard.getSuly());
	a.setTerheles(vas_kard.getSuly());
	cout << "\nTerhel�sed: " << a.getTerheles() << "/" << a.getHati();
	var();

}

void fegyver_valaszt(jatekos& a, vektor<fegyver> taska, fegyver& valasztott_fegyver, int& valasz) {// harchoz a fegyver kiv�laszt�sa
retry1:
	cout << "\nV�lassz fegyvert!\n";
	for (int i = 0; i < taska.getSize(); ++i) {
		cout << i + 1 << ".:" << taska.return_elem(i).getName() << " t�pusa: " << taska.return_elem(i).getType() << endl;//fegyverek felsorol�sa a j�t�kos sz�m�ra
	}
	cout << "\n�rd be a fegyver sz�m�t!\n";
	cin >> valasz;
	cin.ignore(10000, '\n');
	if (valasz <= taska.getSize()) {
		valasztott_fegyver = taska.return_elem(valasz - 1);
	}
	else {
		cout << "Nem megfelel� sz�mot adt�l meg.\n";
		Sleep(1500);
		goto retry1;
	}
}

void kuldetesek(jatekos& a, vektor<fegyver> taska, vektor<szorny> szorny_t, string& valasz, vektor<fegyver> fegyverek) {// t�bbi kuldet�s �s harcok
	fegyver valasztott_fegyver;
	int r_szam;
	int fegyver_sorszam;
	system("cls");
	Sleep(1000);
	cout << "Elidulsz befele az erd� k�zep�re. Nem jutsz messzire mire megpillantasz egy blobot aki �ppen gomb�val t�mi mag�t. R�kiab�lsz mire � elindul fel�d.\n";
	cout << "\nK�sz�lj a harcra a Blob m�r t�mad�sra k�sz.";
	var();
	cout << "\nTipp: Minden ellens�gnek megvan a maga tulajdons�ga. Egyes tulajdons�gok ellen er�sebb vagy, ha jol v�lasztod meg a fegyvered. Minden harc el�tt megtudod milyen tipus� ellens�ggel harcolsz �s ez alapj�n v�laszthatod meg a fegyvert. Harc k�zben el�fordulhat, hogy k�nnyebb k�rd�sekre kell v�laszt adj.\n";
	var();
	cout << "\nBlob tulajdons�gai:\n" << "�letereje: " << szorny_t.return_elem(0).getHP() << "\nt�pusa: " << szorny_t.return_elem(0).getType() << endl;
	fegyver_valaszt(a, taska, valasztott_fegyver, fegyver_sorszam);//fegyver kiv�laszt�sa
	if (valasztott_fegyver.getType() == szorny_t.return_elem(0).getGyenge()) {//ha j� fegyvert v�lasztunk er�sebbek vagyunk ellene
		valasztott_fegyver.setEro(valasztott_fegyver.getEro() + 2);
	}
	vektor<fegyver> taska2;
	fegyver rozsdas_kard("Rozsd�s Kard", 15, 4, "v�z");
	fegyver vas_kard("L�ngol� Ac�l kard", 20, 15, "t�z");
	taska2.push_back(vas_kard);
	taska2.push_back(rozsdas_kard);
	cout << "A blob m�r csak egy kardcsap�snyira van. R�suhintasz egyet? [igen,nem]\n";
	cin >> valasz;
	cin.ignore(10000, '\n');
	if (valasz == "igen") {
		szorny temp;
		cout << "\nTal�lt az els� �t�sed. A blob �lete cs�kkent.";
		temp = szorny_t.return_elem(0);
		temp.setHP(temp.getHP() - (valasztott_fegyver.getEro() + a.getEro()));
		szorny_t.csere(0, temp);
		cout << "\n Blob �letereje:" << szorny_t.return_elem(0).getHP();
		cout << "\nA Blob m�r t�mad is. Megpr�b�lsz kit�rni?[igen,nem]\n";
		cin >> valasz;
		cin.ignore(10000, '\n');
		if (valasz == "igen") {
			if (osszeadas() == true)//�sszead�sos feladat ki�r�sa sikeres 
				cout << "Siker�lt kit�rj.";
			else {
				cout << "\nRossz v�lasz. A blob meg�t�tt.";
				a.setHP(a.getHP() - szorny_t.return_elem(0).getEro());
				cout << "\n�leter�d cs�kkent: " << a.getHP() << "-ra/re.";

			}
		}
	}
	else if (valasz == "nem") {
		cout << "\nA Blob t�mad�sba lend�lt. Nem tudt�l kit�rni az �t�se el�l.";
		Sleep(2000);
		a.setHP(a.getHP() - szorny_t.return_elem(0).getEro());
		cout << "\n�leter�d cs�kkent:" << a.getHP() << "-ra/re.";
		Sleep(2000);
		cout << "\nMire �szhez kapsz a blob m�r �jra t�mad.";
		cout << "\nMegpr�b�lsz kit�rni?[igen,nem]\n";
	retry2:
		cin >> valasz;
		cin.ignore(10000, '\n');
		if (valasz == "igen" || valasz == "nem") {
			if (valasz == "igen") {
				cout << "\nEz csak a szerencs�n m�lik. Ha 5 alatti sz�mot sorsol a g�p akkor kit�rt�l.";
				Sleep(3000);
				r_szam = random();
				if (r_szam < 5) {
					cout << "\nSiker�lt kit�rj. A sz�mod: " << r_szam;
					Sleep(2000);
				}
				else {
					cout << "\nSajnos nem tudt�l kit�rni. A sz�mod: " << r_szam;
					a.setHP(a.getHP() - szorny_t.return_elem(0).getEro());
					cout << "\n�leter�d cs�kkent:" << a.getHP() << "-ra/re.";
					Sleep(2000);
				}
			}
			else {
				a.setHP(a.getHP() - szorny_t.return_elem(0).getEro());
				cout << "\n�leter�d cs�kkent:" << a.getHP() << "-ra/re.";
				Sleep(2000);
			}
		}
		else {
			cout << "Igennel vagy nemmel v�laszolj!";
			Sleep(2000);
			goto retry2;
		}
	}
	while (szorny_t.return_elem(0).getHP() > 0) {
		cout << "\n\nTe k�vetkezel. R�suhintasz a Blobra. A tal�latod csak a szerencs�t�l f�gg. (Ha a sz�m <8 akkor eltal�lod)";
		Sleep(3500);
		r_szam = random();
		if (r_szam < 8) {
			cout << "\nEltal�ltad. A sz�mod: " << r_szam;
			szorny temp;
			temp = szorny_t.return_elem(0);
			temp.setHP(temp.getHP() - (valasztott_fegyver.getEro() + a.getEro()));
			szorny_t.csere(0, temp);
			if (szorny_t.return_elem(0).getHP() <= 0) {//sz�rny hal�la
				cout << "\nGratul�lok! Sikeresen legy�zted a Blobot!";
				Sleep(1500);
				cout << "Szerezt�l 100 tapasztalatpontot.";
				a.setXP(100);
				szintlepes(a);
				break;
			}
			cout << "\nA Blob �letereje cs�kkent " << szorny_t.return_elem(0).getHP() << "-ra/re.";
			Sleep(2000);
		}
		else {
			cout << "\nSajnos nem tal�ltad el. A sz�mod: " << r_szam;
			Sleep(2000);
		}
		cout << "\nA Blob t�mad.Megpr�b�lsz kit�rni?[igen, nem]\n";
	retry3:
		cin >> valasz;
		cin.ignore(10000, '\n');
		if (valasz == "igen" || valasz == "nem") {
			if (valasz == "igen") {
				cout << "\nEz csak a szerencs�n m�lik. Ha 5 alatti sz�mot sorsol a g�p akkor kit�rt�l.";
				Sleep(1500);
				r_szam = random();
				if (r_szam < 5) {
					cout << "\nSiker�lt kit�rj. A sz�mod: " << r_szam;
					Sleep(1500);
				}
				else {
					cout << "\nSajnos nem tudt�l kit�rni. A sz�mod: " << r_szam;
					a.setHP(a.getHP() - szorny_t.return_elem(0).getEro());
					cout << "\n�leter�d cs�kkent:" << a.getHP() << "-ra/re.";
					Sleep(2000);
				}
			}
			else {
				cout << "\nA Blob meg�t�tt";
				cout << "\n�leter�d cs�kkent:" << a.getHP() << "-ra/re.";
				Sleep(2000);
			}
		}
		else {
			cout << "Igennel vagy nemmel v�laszolj!";
			Sleep(2000);
			goto retry3;
		}
	}
	cout << "\nAmint a Blob a f�ldre zuhant a messzes�gbe megjelenik Klem.\n";
	a.setHatizsak_m(a.getHP());//�leter� cs�kken�s�vel cs�kken a h�tizs�k m�rete
	Sleep(2500);
	cout << "\nKlem: Nagyon k�sz�n�m a seg�ts�ged. Tess�k itt van a meg�g�rt aj�nd�k.";
	Sleep(2000);
	cout << "\nSzerezt�l 1 [�leter� italt] ";
	cout << "\nMegittad az �leter� italt. Kapt�l +10 �leter�t.";
	a.setHP(a.getHP() + 10);
	var();

	if (a.getHP() > 100) {
		a.setHP(100);
	}
	if (a.getTerheles() > a.getHati()) {
		cout << "\nNem f�r el t�bb dolog a t�sk�dba. Dobd el az egyik t�rgyad.";
		fegyver_valaszt(a, taska, valasztott_fegyver, fegyver_sorszam);
		taska.pop(fegyver_sorszam - 1);
	}
	cout << "\n";
	//2.kuldetes
	cout << "\nTov�bb indulsz az erd� k�zepe fel� �s a f�k f�l�tt kibukkan egy kast�ly tornya. Elindulsz fel�, de ahogy k�zeledsz sikitoz�st hallasz. Odam�sz?[igen,nem]\n ";
	Sleep(2000);
	fegyver valasztott_fegyver_2;
retry4:
	cin >> valasz;
	cin.ignore(10000, '\n');
	if (valasz == "igen" || valasz == "nem") {
		if (valasz == "igen") {
			cout << "\nEgyre k�zelebb �rsz �s megpillantasz egy h�romfej� kutya. Valamit nagyon �riz...";
			Sleep(2000);
			cout << "\nHogy megtudd mi az le kell gy�zd.";
			Sleep(1500);
			cout << "\nK�szen �llsz a harcra?";
			var();
			cout << "\nA kutya adatai:\n" << "�lete: " << szorny_t.return_elem(1).getHP() << "\ntipusa: " << szorny_t.return_elem(1).getType();//sz�rny adatainak ki�r�sa

			fegyver_valaszt(a, taska2, valasztott_fegyver_2, fegyver_sorszam);
			if (valasztott_fegyver_2.getType() == szorny_t.return_elem(0).getGyenge()) {//ha j� fegyvert v�lasztunk er�sebbek vagyunk ellene
				valasztott_fegyver_2.setEro(valasztott_fegyver_2.getEro() + 2);
			}
			szorny temp = szorny_t.return_elem(1);
			while (temp.getHP() > 0) {
				cout << "\nR�suhintasz a kuty�ra.";
				if (osszeadas() == true) {//sikeres t�mad�s
					temp.setHP(temp.getHP() - valasztott_fegyver_2.getEro());
					cout << "\nEltal�ltad a kuty�t. �letereje cs�kkent." << temp.getHP() << "-ra/re.";
					if (temp.getHP() <= 0) {//j�t�k v�ge gy�zt�l
						cout << "\nGratul�lok legy�zted a kuty�t. Amint odal�psz a kutya holttest�hez �szreveszed a kincset amit �rz�tt.";
						Sleep(2000);
						cout << "\nEgy arany kulcs az. Vajon mire lehet j�?";
						Sleep(3000);
						cout << "\nOda�rsz a kast�lyhoz �s egy nagy d�szes kapu fogad, elhagytottnak t�nik. Belepr�b�lod a kulcsot a kapuba ami szerencs�dre pont azt nyitja.";
						Sleep(3000);
						cout << "\nBel�psz a kast�lyba ahol egy papiruszt tal�lsz amin ez �ll: ";
						Sleep(3000);
						cout << "\nCsak az tud bel�pni ebbe a kast�lyba aki m�lt� r� �s k�pes megszerezni a kulcsot.\n Ett�l a pillanatt�l kezdve ez a kast�ly a ti�d.";
						Sleep(3000);
						cout << "\nEzut�n berendeszkedt�l a kast�lyba, mindent vissza�ll�tott�l a r�gi pomp�j�ba �s boldogan �lt�l am�g meg nem halt�l.";

					}
				}
				else {//sikertelen t�mad�s
					cout << "\nHelytelen v�lasz. Nem tal�ltad el a kuty�t.";
				}
			}
		}
		else if (valasz == "nem") {
			cout << "\nTov�bb indult�l. M�r bandukolsz egy ideje, de a f�radts�godat fel�lm�lja az �hs�g.";
			Sleep(2000);
			cout << "\nMegpillantasz egy bokornyi piros bogyot. Neki is esel, de nem sok �r�m�d lesz bel�le.";
			Sleep(2000);
			cout << "\nNem sokkal a lakoma ut�n m�r az �lettelen tested az �t sz�l�n hever.";
			Sleep(2000);
			cout << "\nMeghalt�l a j�t�knak v�ge. El�rt szinted: " << a.getLvl();
		}
	}
	else {
		cout << "Igennel vagy nemmel valaszolj.\n";
		goto retry4;
	}
}
