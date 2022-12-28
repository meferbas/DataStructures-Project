/**
* @file SatirListesi.hpp
* @description SatirListesi degiskenleri
* @course Veri Yapilari 2-A Grubu
* @assignment 1.Odev
* @date 08/11/2022
* @author G201210093 - Mehmet Efe Erbas - efe.erbas@ogr.sakarya.edu.tr
*/

#ifndef SatirListesi_hpp
#define SatirListesi_hpp
#include "SatirListesiDugum.hpp"

#include<iostream>
#include<iomanip>
using namespace std;
class SatirListesi
{
public:
    SatirListesi();
    ~SatirListesi();
    void Ekle(int veri);
    void yazdir();
    void cikar(int sira);
    int ilkGetir();
    double ort=0;
    friend ostream& operator<<(ostream& os, SatirListesi& liste);
    SatirListesiDugum* dugumGetir(int sira);
    void cizgiYazdir(int adet);
    void yazdir(int deger);

private:
    SatirListesiDugum *ilk;
  

};

#endif
