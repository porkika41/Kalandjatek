#include <iostream>
#include <string>
#ifndef kar_h
#define kar_h
using namespace std;
class jatekos {
private:
	string nev;
	int elet;
	int hatizsak_meret;
	int terheles;
	int szint;
	int tapasztalat;
	int szukseges_tapasztalat;
	int ero;
public:
	jatekos(string nev) :elet{ 100 }, hatizsak_meret{ 100 }, terheles{ 0 }, szint{ 1 }, tapasztalat{ 0 }, szukseges_tapasztalat{ 100 }, ero{ 1 }, nev{ nev }{}
	jatekos() :elet{ 100 }, hatizsak_meret{ 100 }, terheles{ 0 }, szint{ 1 }, tapasztalat{ 0 }, szukseges_tapasztalat{ 100 }, ero{ 1 }, nev{ }{}
	string getName() { return nev; }
	int getHP() { return elet; }
	int getXP() { return tapasztalat; }
	int getHati() { return hatizsak_meret; }
	int getTerheles() { return terheles; }
	int getEro() { return ero; }
	int getSzukseges_tp() { return szukseges_tapasztalat;}
	int getLvl() { return szint; }
	void setHP(int hp) {elet = hp;}
	void setXP(int xp) {tapasztalat = xp;}
	void setName(string name) { nev = name; }
	void setEro(int p) { ero = p; }
	void setTerheles(int t) { terheles += t; }
	void setLvl_plus() { szint += 1; };
	void setHatizsak_m(int meret) { hatizsak_meret = meret; }

};
#endif
