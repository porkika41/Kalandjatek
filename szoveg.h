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
bool osszeadas(); //ellenség éltalálását dönti el
void var();// várakozás a játékosra
void szintlepes(jatekos& a);//szörny legyõzése után megnézi zsintet lépett e a játékos
void belepes(jatekos& x);//játékos inicializálása
void elso_kuldetes(jatekos& a, vektor<fegyver>& taska, vektor<fegyver> fegyverek, string valasz);//elsõ küldetés megkapása
void fegyver_valaszt(jatekos& a, vektor<fegyver> taska, fegyver& valasztott_fegyver, int& valasz);// harchoz a fegyver kiválasztása
void kuldetesek(jatekos& a, vektor<fegyver> taska, vektor<szorny> szorny_t, string& valasz, vektor<fegyver> fegyverek);// többi kuldetés és harcok

#endif 
