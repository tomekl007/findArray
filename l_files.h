#ifndef L_FILES_H
#define L_FILES_H

class DataSet;

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//funckja ktora otwiera plik do odczytu
void f_otwarcie_pliku_do_odczytu(ifstream &odczyt_pliku);

int f_wyszukiwanie_interpolacyjne(long long k, int N, long long *Z);

#endif
