#include <iostream>
#include <string>
#ifndef targy_h
#define targy_h
using namespace std;

class targyak {
private:
	string nev;
	int suly;
public:
	targyak(string nev, int suly) :nev{ nev }, suly{ suly }{}
	targyak() :nev{ " " }, suly{ 0 }{}
	string getName()const { return nev; }
	int getSuly()const { return suly; }
	void setName(string Nev) { nev = Nev; }
	void setSuly(int s) { suly = s; }
};


#endif // !targyak

