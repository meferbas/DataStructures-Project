/**
* @file YoneticiListesi.cpp
* @description YoneticiListesi Fonksiyonlari
* @course Veri Yapilari 2-A Grubu
* @assignment 1.Odev
* @date 08/11/2022
* @author G201210093 - Mehmet Efe Erbas - efe.erbas@ogr.sakarya.edu.tr
*/

#include "YoneticiListesi.hpp"
#include "YoneticiListesiDugum.hpp"
#include "DosyaOku.hpp"
#include <iostream>
#include <iomanip>
using namespace std;


YoneticiListesi::YoneticiListesi()
{
    ilk = 0;
}
YoneticiListesi::~YoneticiListesi()
{
    YoneticiListesiDugum*gec=ilk;
    while (gec!=0)
    {
        YoneticiListesiDugum*silinecek=gec;
      gec=gec->sonraki;  
      delete silinecek;
    }
    
}

void YoneticiListesi::Sirala()
{
    YoneticiListesiDugum *gec = ilk;
    YoneticiListesiDugum *index = NULL;
    SatirListesi *temp;
    
    
    if (ilk == NULL)
    {
        return;
    }
    else
    {
        int i=0;
        while (i<dugumSayac-1)
        {
      
            int j=0;
            while (j<dugumSayac-i-1)
            {

                if (dugumGetir(j)->veri->ort > dugumGetir(j+1)->veri->ort)
                {
                    temp = dugumGetir(j)->veri;
                    dugumGetir(j)->veri = dugumGetir(j+1)->veri;
                    dugumGetir(j+1)->veri = temp;
                }
                j++;
            }
            i++;
        }
    }
}
void YoneticiListesi::ekle(SatirListesi *veri)
{
    YoneticiListesiDugum *yeniDugum = new YoneticiListesiDugum(veri);


    if (ilk == 0)
    {
        ilk = yeniDugum;
    }
    else
    {
        YoneticiListesiDugum *gec = ilk;
        while (gec->sonraki != 0)
        {
            gec = gec->sonraki;
        } 
        gec->sonraki = yeniDugum;
        yeniDugum->onceki=gec;
    }
}
void YoneticiListesi::cikar(int sira)
{
    YoneticiListesiDugum* sil=dugumGetir(sira); //istedigimiz siradaki dugumun adresini verir
    if(sil)
    {
        YoneticiListesiDugum* silOnceki=sil->onceki;
        YoneticiListesiDugum* silSonraki=sil->sonraki;
        if(silSonraki)
        {
            silOnceki->onceki=silSonraki;
        }
        if(silOnceki)
        {
            silOnceki->sonraki=silSonraki;       
        }
        else
        {
            ilk=silSonraki;
        }
            delete sil;
    }
}

void YoneticiListesi::yoneticiCikar(int index) 
{
    if (index < 0 || index >= dugumSayac) throw "Index out of Range";
    YoneticiListesiDugum *sil;
    if (index == 0) {
        sil = ilk;
        ilk = ilk->sonraki;
        if (ilk != NULL) ilk->onceki = NULL;
    } else {
        YoneticiListesiDugum *prv = dugumGetir(index)->onceki;
        sil = prv->sonraki;
        prv->sonraki = sil->sonraki;
        if (sil->sonraki != NULL)
            sil->sonraki->onceki = prv;
    }
    dugumSayac--;
    delete sil;
}

void SatirListesi::yazdir(){

    SatirListesiDugum* gec=ilk;
    while (gec!=0)
    {
        cout<<gec<<endl<<gec->veri<<endl<<gec->sonraki<<endl;
        cout<<endl;
        gec=gec->sonraki;
    }
    cout<<endl;
    delete gec;
    

   
}
YoneticiListesiDugum *YoneticiListesi::dugumGetir(int sira)
{
    YoneticiListesiDugum*gec=ilk;

    while(gec!=0 && sira>=0)
    {
        if(sira==0)
        return gec;
        gec=gec->sonraki;
        sira--; 
    }
    return 0;
}

YoneticiListesi* YoneticiListesi::yoneticiYazdir(string fileName, int keeper)
{
    if (dugumSayac-keeper>=8)
    {
        if (keeper == 0)
        {
            cout << "--ilk--" << setw(96) << "--sonraki-->" << endl;

            for (int i = keeper; i < keeper + 8; i++)
            {
                cout << setw(11) << dugumGetir(i) << setw(2) << "";
            }
            cout << endl;
            cout << " ";
            for (int i = keeper; i < keeper + 8; i++)
            {
                cout << "-----------" << setw(2) << "";
            }
            cout << endl;
            cout << " ";
            for (int i = keeper; i < keeper + 8; i++)
            {
                cout << "|" << setw(9) << dugumGetir(i)->onceki << "|" << setw(2) << " ";
            }
            cout << endl;
            cout << " ";
            for (int i = keeper; i < keeper + 8; i++)
            {
                cout << "-----------" << setw(2) << "";
            }
            cout << endl;
            cout << " ";
            for (int i = keeper; i < keeper + 8; i++)
            {
                cout << "|" << setw(9) << dugumGetir(i)->veri->ort << "|" << setw(2) << " ";
            }
            cout << endl;
            cout << " ";
            for (int i = keeper; i < keeper + 8; i++)
            {
                cout << "-----------" << setw(2) << "";
            }
            cout << endl;
            cout << " ";
            for (int i = keeper; i < keeper + 8; i++)
            {
                cout << "|" << setw(9) << dugumGetir(i)->sonraki
                    << "|" << setw(2) << " ";
            }
            cout << endl;
            cout << " ";
            for (int i = keeper; i < keeper + 8; i++)
            {
                cout << "-----------" << setw(2) << "";
            }
            cout << endl;
            cout << " ";
        }
        else if (keeper >= 8)
        {
            cout << "<--onceki--" << setw(91) << "--sonraki-->" << endl;

            for (int i = keeper; i < keeper + 8; i++)
            {
                cout << setw(11) << dugumGetir(i) << setw(2) << "";
            }
            cout << endl;
            cout << " ";
            for (int i = keeper; i < keeper + 8; i++)
            {
                cout << "-----------" << setw(2) << "";
            }
            cout << endl;
            cout << " ";
            for (int i = keeper; i < keeper + 8; i++)
            {
                cout << "|" << setw(9) << dugumGetir(i)->onceki << "|" << setw(2) << " ";
            }
            cout << endl;
            cout << " ";
            for (int i = keeper; i < keeper + 8; i++)
            {
                cout << "-----------" << setw(2) << "";
            }
            cout << endl;
            cout << " ";
            for (int i = keeper; i < keeper + 8; i++)
            {
                cout << "|" << setw(9) << dugumGetir(i)->veri->ort << "|" << setw(2) << " ";
            }
            cout << endl;
            cout << " ";
            for (int i = keeper; i < keeper + 8; i++)
            {
                cout << "-----------" << setw(2) << "";
            }
            cout << endl;
            cout << " ";
            for (int i = keeper; i < keeper + 8; i++)
            {
                cout << "|" << setw(9) << dugumGetir(i)->sonraki
                    << "|" << setw(2) << " ";
            }
            cout << endl;
            cout << " ";
            for (int i = keeper; i < keeper + 8; i++)
            {
                cout << "-----------" << setw(2) << "";
            }
            cout << endl;
            cout << " ";
        }
    }
    else
    {
        cout << "<--onceki--" << setw(25) << "--son--" << endl;

            for (int i = keeper; i < dugumSayac; i++)
            {
                cout << setw(11) << dugumGetir(i) << setw(2) << "";
            }
            cout << endl;
            cout << " ";
            for (int i = keeper; i < dugumSayac; i++)
            {
                cout << "-----------" << setw(2) << "";
            }
            cout << endl;
            cout << " ";
            for (int i = keeper; i < dugumSayac; i++)
            {
                cout << "|" << setw(9) << dugumGetir(i)->onceki << "|" << setw(2) << " ";
            }
            cout << endl;
            cout << " ";
            for (int i = keeper; i < dugumSayac; i++)
            {
                cout << "-----------" << setw(2) << "";
            }
            cout << endl;
            cout << " ";
            for (int i = keeper; i < dugumSayac; i++)
            {
                cout << "|" << setw(9) << dugumGetir(i)->veri->ort << "|" << setw(2) << " ";
            }
            cout << endl;
            cout << " ";
            for (int i = keeper; i < dugumSayac; i++)
            {
                cout << "-----------" << setw(2) << "";
            }
            cout << endl;
            cout << " ";
            for (int i = keeper; i < dugumSayac; i++)
            {
                cout << "|" << setw(9) << dugumGetir(i)->sonraki
                    << "|" << setw(2) << " ";
            }
            cout << endl;
            cout << " ";
            for (int i = keeper; i < dugumSayac; i++)
            {
                cout << "-----------" << setw(2) << "";
            }
            cout << endl;
            cout << " ";

    }
    
      
}

void YoneticiListesi::yazdir(){
    cout << setw(15) << "dugum adresi" << setw(15) << "veri" << setw(15) << "onceki" << setw(15) << "sonraki" << endl;
    YoneticiListesiDugum *gec = ilk; // ilk düğümü verir
    // cout<<"tested avg : "<<gec->veri->average<<endl;

    while (gec != 0)
    {
    
         
    
        cout << setw(15) << gec<< setw(15) << gec->veri->ort<< setw(15) << gec->onceki << setw(15) << gec->sonraki << endl;

        gec = gec->sonraki;
    }
    cout << "-----------------------" << endl;

    cout << endl;
    delete gec;

   
}

