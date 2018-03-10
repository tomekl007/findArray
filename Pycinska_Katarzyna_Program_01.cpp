#include <iostream>
#include <string>
#include <fstream>
#include "l_files.h"

using namespace std;

int main() {
    ifstream odczyt_pliku;
    ofstream zapis_pliku;

    f_otwarcie_pliku_do_odczytu(odczyt_pliku);
    return 0;
}