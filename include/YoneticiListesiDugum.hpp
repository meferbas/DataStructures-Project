/**
* @file YoneticiListesiDugum.hpp
* @description YoneticiListesi Dugum islemleri icin gereken kodlarin olusturulmasi
* @course Veri Yapilari 2-A Grubu
* @assignment 1.Odev
* @date 08/11/2022
* @author G201210093 - Mehmet Efe Erbas - efe.erbas@ogr.sakarya.edu.tr
*/

#ifndef YoneticiListesiDugum_hpp
#define YoneticiListesiDugum_hpp
#include"SatirListesi.hpp"

#include <iostream>
using namespace std;
class YoneticiListesiDugum
{
public:
    SatirListesi *veri;
    YoneticiListesiDugum(SatirListesi *veri);
    ~YoneticiListesiDugum(); 
    YoneticiListesiDugum * sonraki;
    YoneticiListesiDugum * onceki;
  
};

#endif