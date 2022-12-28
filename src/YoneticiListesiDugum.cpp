/**
* @file main.cpp
* @description YoneticiListesi Dugum islemleri
* @course Veri Yapilari 2-A Grubu
* @assignment 1.Odev
* @date 08/11/2022
* @author G201210093 - Mehmet Efe Erbas - efe.erbas@ogr.sakarya.edu.tr
*/
#include "YoneticiListesiDugum.hpp"
#include <iostream>
using namespace std;

YoneticiListesiDugum::YoneticiListesiDugum(SatirListesi *veri)
{
    this->veri = veri;
    onceki = sonraki = 0;

}

YoneticiListesiDugum::~YoneticiListesiDugum()
{
    cout<<this<<": adresindeki dugum silindi"<<endl;    
}