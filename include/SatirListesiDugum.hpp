/**
* @file SatirListesiDugum.hpp
* @description SatirListesi Dugum adresleri icin gerekli degiskenler
* @course Veri Yapilari 2-A Grubu
* @assignment 1.Odev
* @date 08/11/2022
* @author G201210093 - Mehmet Efe Erbas - efe.erbas@ogr.sakarya.edu.tr
*/

#ifndef SatirListesiDugum_hpp
#define SatirListesiDugum_hpp

#include <iostream>
using namespace std;
class SatirListesiDugum
{
public:

SatirListesiDugum(int veri);
~SatirListesiDugum();    
int veri;   
SatirListesiDugum *sonraki;  
SatirListesiDugum *onceki;
    
   
};

#endif