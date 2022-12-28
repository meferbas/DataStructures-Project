/**
* @file SatirListesi.cpp
* @description SatirListesi fonksiyonlari
* @course Veri Yapilari 2-A Grubu
* @assignment 1.Odev
* @date 08/11/2022
* @author G201210093 - Mehmet Efe Erbas - efe.erbas@ogr.sakarya.edu.tr
*/

#include "SatirListesi.hpp"
#include "YoneticiListesi.hpp"
#include "YoneticiListesiDugum.hpp"
#include "DosyaOku.hpp"
#include <iomanip>
using namespace std;


SatirListesi::SatirListesi()
{
    ilk=0;
}
SatirListesi::~SatirListesi()
{
    SatirListesiDugum* gec=ilk;
    while(gec!=0)
    {
        SatirListesiDugum* silinecek=gec;
        gec=gec->sonraki;
        delete silinecek;
    }
}
int SatirListesi::ilkGetir()
{
    if(ilk!=0)
        return ilk->veri;
    throw std::out_of_range("Liste::ilkGetir(): Liste Bos Hatasi");
}

void SatirListesi::cikar(int sira)
{
 SatirListesiDugum* sil=dugumGetir(sira);
 if(sil)
 {
    SatirListesiDugum* silOnceki=sil->onceki;
    SatirListesiDugum* silSonraki=sil->sonraki;

    if(silSonraki)
    {
        silSonraki->onceki=silOnceki;
    }
    if(silOnceki)
    {
        silOnceki->sonraki=silSonraki;
    }
    else
    {
        ilk=silSonraki;
        delete sil;

    }
 }
}
void SatirListesi::Ekle(int veri)
{
    SatirListesiDugum* yeniDugum=new SatirListesiDugum(veri);
    if(ilk==0)
    {
        ilk=yeniDugum;
        
    }
    else
    {
        SatirListesiDugum* gec=ilk;
        while(gec->sonraki!=0)
        {
            gec=gec->sonraki;
        }


        gec->sonraki=yeniDugum;
        yeniDugum->onceki=gec;
    }
}
SatirListesiDugum* SatirListesi::dugumGetir(int sira)
{

    SatirListesiDugum* gec=ilk;
    while(gec!=0 && sira>=0)
    {
       
            if(sira==0)
                return gec;
            gec=gec->sonraki;
        
        sira--;
    }
    return 0;
}

void SatirListesi::yazdir(int deger)
{
    SatirListesiDugum *gec = ilk;

    while (gec != 0)
    {
        cout << endl;
        cout << setw(13 * deger) << "";
        cout << ""<< "^^^^^^^^^^^" << endl;

        cout << setw(13 * deger) << "";
        cout << ""<< "-----------";

        cout << endl;

        cout << setw(13 * deger) << "";
        cout << "|" << setw(9) << gec << "|" << setw(2) << " ";

        cout << endl;

        cout << setw(13 * deger) << "";
        cout << ""<< "-----------";

        cout << endl;

        cout << setw(13 * deger) << "";
        cout << "|" << setw(9) << gec->veri << "|" << setw(2) << " ";

        cout << endl;

        cout << setw(13 * deger) << "";
        cout << "" << "-----------";

        cout << endl;

        cout << setw(13 * deger) << "";
        cout << "|" << setw(9) << gec->sonraki << "|" << setw(2) << " ";

        cout << endl;

        cout << setw(13 * deger) << "";
        cout << "" << "-----------";

        cout << endl;

        gec = gec->sonraki;
    }

    cout << endl;
}
