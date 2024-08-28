#ifndef ellen
#define ellen
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
class szorny {
private:
	int elet;
	int ero;
	string nev;
	string tipus;
	string gyengeseg;
	
public:
	szorny(int hp, string name, string type, string gyenge, int ero) :elet{ hp }, nev{ name }, tipus{ type }, ero{ ero }, gyengeseg{ gyenge }{}
	szorny() :elet{ 0 }, nev{ " " }, tipus{ " " }, ero{ 0 }, gyengeseg{ " " } {}
	int getHP()  { return elet; }
	string getName() const { return nev; }
	string getType() const { return tipus; }
	string getGyenge()const { return gyengeseg; }
	int getEro() const { return ero; }
	void setHP(int hp) { elet = hp; }

	friend ostream& operator<<(ostream& os, const szorny& x) {
		os << x.elet << ' ' << x.ero << endl;
		os << x.nev << endl;
		os << x.tipus << endl;
		os << x.gyengeseg << endl;
		return os;
	}

	friend istream& operator>>(istream& is, szorny& x) {
		string sor;
		if (!getline(is, sor))
			throw runtime_error("Szörny: Sikertelen olvasás(elet,ero)");
		istringstream intek(sor);
		if (!(intek >> x.elet >> x.ero))
			throw runtime_error("Szörny: nem int van a sorba");
		if (!getline(is, x.nev))
			throw runtime_error("Szörny: sikertelen olvasás (név)");
		if (!getline(is, x.tipus))
			throw runtime_error("Szörny: sikertelen olvasás (tipus)");
		if (!getline(is, x.gyengeseg))
			throw runtime_error("Szörny: sikertelen olvasás (gyengeség)");
		return is;
	}
};

#endif // !ellenseg

