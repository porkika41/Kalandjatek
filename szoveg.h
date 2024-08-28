#include <iostream>
#include <locale>
#include <Windows.h>
#include <string>
#include <time.h>
#include "Jatekos.h"
#include "dolgok_tarolasa.h"
#ifndef h
#define h

int random();
bool osszeadas(); //ellens�g �ltal�l�s�t d�nti el
void var();// v�rakoz�s a j�t�kosra
void szintlepes(jatekos& a);//sz�rny legy�z�se ut�n megn�zi zsintet l�pett e a j�t�kos
void belepes(jatekos& x);//j�t�kos inicializ�l�sa
void elso_kuldetes(jatekos& a, vektor<fegyver>& taska, vektor<fegyver> fegyverek, string valasz);//els� k�ldet�s megkap�sa
void fegyver_valaszt(jatekos& a, vektor<fegyver> taska, fegyver& valasztott_fegyver, int& valasz);// harchoz a fegyver kiv�laszt�sa
void kuldetesek(jatekos& a, vektor<fegyver> taska, vektor<szorny> szorny_t, string& valasz, vektor<fegyver> fegyverek);// t�bbi kuldet�s �s harcok

#endif 
