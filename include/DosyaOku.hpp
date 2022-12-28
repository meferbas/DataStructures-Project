/**
* @file DosyaOku.hpp
* @description Dosya Okuma islemleri icin degiskenler 
* @course Veri Yapilari 2-A Grubu
* @assignment 1.Odev
* @date 08/11/2022
* @author G201210093 - Mehmet Efe Erbas - efe.erbas@ogr.sakarya.edu.tr
*/

#ifndef DosyaOku_hpp
#define DosyaOku_hpp

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "SatirListesiDugum.hpp"
#include "SatirListesi.hpp"
#include "YoneticiListesiDugum.hpp"
#include "YoneticiListesi.hpp"
using namespace std;
class DosyaOku
{
private:
public:
    DosyaOku();
    ~DosyaOku();
    string fileName;
    string character;
    void satirSayi(); 
    int boslukAdet;
    int anaMenu();
    
    
    YoneticiListesi* readFile(string);
    
    //YoneticiListesi *GetFillYoneticiListesi();
};

#endif