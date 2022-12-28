/**
* @file SatirListesiDugum.cpp
* @description SatirListesi Dugumlerde gezebilmek icin gerekli islemler
* @course Veri Yapilari 2-A Grubu
* @assignment 1.Odev
* @date 08/11/2022
* @author G201210093 - Mehmet Efe Erbas - efe.erbas@ogr.sakarya.edu.tr
*/
#include "SatirListesiDugum.hpp"
#include <iostream>
SatirListesiDugum::SatirListesiDugum(int veri)
{
    this->veri=veri;
    onceki=sonraki=0;
}
SatirListesiDugum::~SatirListesiDugum()
{
   //cout<<this<<":adresindeki dugum Silindi"<<endl;
}