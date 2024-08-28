#ifndef taroas_h
#define tarolas_h

template <typename T>
class vektor {
private:
	T* x;
	int n;
public:
	vektor() :x{ nullptr }, n{ 0 } {}
	~vektor() { delete[]x; }
	vektor(const vektor& v) :x{ nullptr } {
		*this = v;
	}
	void push_back(T uj) {
		T* temp = new T[n + 1];
		for (int i = 0; i < n; i++)
			temp[i] = x[i];
		temp[n] = uj;
		n++;
		delete[]x;
		x = temp;
	}

	void pop(int melyik) {
		T* temp = new T[n - 1];
		for (int i = 0; i < n - 1; ++i) {
			if (i == melyik) ++i;
			else {
				temp[i] = x[i];
				n--;
				T ki = x[n];
				delete[]x;
			}
		}
	}
	T return_elem(int melyik) {return x[melyik]; }
	void csere(int hol, T mire) {
		x[hol] = mire;
	}
	int getSize() { return n; }
};

#endif
