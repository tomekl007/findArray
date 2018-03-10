#ifndef L_FILES_H
#define L_FILES_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//funckja ktora otwiera plik do odczytu
void f_otwarcie_pliku_do_odczytu(ifstream & odczyt_pliku);

//funckja wyswietlajaca tablice
long long *f_otworz_tab(unsigned short int rozmiar);

int f_wyszukiwanie_interpolacyjne(long long wartosc_szukana, int Ip, int Ik, long long *tab);

#endif
