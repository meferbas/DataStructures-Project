/**
* @file YoneticiListesi.hpp
* @description YoneticiListesi fonksiyonlarin olusturulmasi
* @course Veri Yapilari 2-A Grubu
* @assignment 1.Odev
* @date 08/11/2022
* @author G201210093 - Mehmet Efe Erbas - efe.erbas@ogr.sakarya.edu.tr
*/
#ifndef YoneticiListesi_hpp
#define YoneticiListesi_hpp

#include "YoneticiListesiDugum.hpp"
#include<exception>
#include <iostream>
#include <iomanip>
using namespace std;

class YoneticiListesi
{
public:
    YoneticiListesi();
    ~YoneticiListesi();
    void ekle(SatirListesi *veri);
    void Sirala();
    void yoneticiCikar(int index);
    void yazdir();
    void cikar(int sira);
    YoneticiListesi* yoneticiYazdir(string fileName,int keeper);
    int dugumSayac;
    int ilkGetir();
    double ort=0;
    //friend ostream &operator<<(ostream &os, YoneticiListesi &Liste);
    YoneticiListesiDugum *dugumGetir(int sira);

private:
    YoneticiListesiDugum *ilk;
    
};

#endif