#include "targyak.h"
#ifndef fegyverek_h
#define fegyverek_h
class fegyver :public targyak {
private:
	int ero;
	string tipus;
public:
	fegyver(string nev,int suly,int ero,string tipus) :targyak(nev,suly),ero{ero},tipus{tipus}{}
	fegyver() :targyak("", 0), ero{ 0 }, tipus{ 0 }{}
	string getType() { return tipus; }
	int getEro() { return ero; }
	void setEro(int Ero) { ero = Ero; }
	fegyver operator=(const fegyver& f) {	
		ero = f.ero;
		tipus = f.tipus;
		setName(f.getName());
		setSuly(f.getSuly());
		return *this;
	}
};
#endif 
