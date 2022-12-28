/**
* @file DosyaOku.cpp
* @description Dosya islemleri ve Ana Menunun olusturulmasi
* @course Veri Yapilari 2-A Grubu
* @assignment 1.Odev
* @date 08/11/2022
* @author G201210093 - Mehmet Efe Erbas - efe.erbas@ogr.sakarya.edu.tr
*/

#include "DosyaOku.hpp"
#include "SatirListesiDugum.hpp"
#include "SatirListesi.hpp"
#include "YoneticiListesiDugum.hpp"
#include "YoneticiListesi.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

DosyaOku::DosyaOku()
{
    
    boslukAdet=0;

}

YoneticiListesi* DosyaOku::readFile(std::string fileName)
{

    int sayac = 0;
    int bosAdet = 0;
    int deger;
    double ortalama=0;
    double toplam=0;

    DosyaOku *k=new DosyaOku();

    ifstream dosyaOku;
    YoneticiListesi*ylist=new YoneticiListesi();
    
    dosyaOku.open(fileName);

    if (dosyaOku.is_open())
    {
        while (getline(dosyaOku, character))
        {

            SatirListesi *slist = new SatirListesi();
            istringstream iss(character);
            for (int j = 0; j < character.length(); j++)
            {

                if (isspace(character.at(j)))
                {
                    bosAdet++;
                }
            }

            for (int i = 0; i < bosAdet; i++)
            {

                iss >> deger;
                slist->Ekle(deger);
                toplam+=deger;
            }

            
            ortalama=toplam/bosAdet;
            slist->ort=ortalama;
            ylist->ort=slist->ort;
            ylist->ekle(slist);

            sayac++;
           

            bosAdet = 0;
            toplam=0;

        }
         ylist->dugumSayac=sayac;

    }
    return ylist;
}
int DosyaOku::anaMenu()
{
    
    DosyaOku *f=new DosyaOku();
    f->fileName="veriler.txt";
    YoneticiListesi *ylist= f->readFile(f->fileName);
    
    
    
    int index=0; int yindex=0; int lines=0;
    

    while (true)
    {   
        
        system("cls");
        string secim="";

        ylist->Sirala();

        ylist->yoneticiYazdir(f->fileName,yindex);
        ylist->dugumGetir(lines)->veri->yazdir(index);
        cout<<"-> Selection ('a-d' , 'z-c', 'p' or quit 'q'): ";
        cin>>secim;

        if (secim=="a")
            {
                if (lines < 8)
                    {
                        yindex = 0;
                        index=0;
                        lines=0;
                    }
                    else if (index == 0 && lines == 0)
                    {

                        index = 0;
                        lines = 0;
                    }
                    else
                    {
                        yindex -= 8;
                        lines -= 8;
                    }
            }
        else if (secim=="d")
        {
            if (ylist->dugumSayac - yindex < 8)
            {
                continue;
            }
            else if(ylist->dugumSayac-lines<=8)
            {
                lines = ylist->dugumSayac - 1;
                yindex+=8;
                index=ylist->dugumSayac-yindex-1;
            }
            else
            {
                yindex += 8;
                lines += 8;
            }
        }
        else if (secim=="z")
        {
            if (index == 0 && lines == 0)
            {
                index=0;
                lines=0;
                
            }
            else
            {
                index--;
                lines--;
                if (yindex % 8 == 0)
                {
                    if (index < 0)
                    {
                        yindex -= 8;
                        index = 7;
                    }
                }
            }
        }
        else if (secim=="c")
        {
            if (ylist->dugumSayac - lines <= 1)
            {
                continue;
            }
            else
            {
                index++;
                lines++;
                if (index % 8 == 0)
                {
                    index = 0;
                    yindex += 8; 
                }
            }
        }
        else if(secim=="p")
        {
            ylist->yoneticiCikar(lines);
            if(lines>=ylist->dugumSayac-1)
            {
                cout<<"girdi"<<endl;
                lines--;
                index--;
                if(index<0)
                {
                    yindex-=8;
                    index=7;
                }
            }
        }
        else if (secim=="q")
        {
            return 0;
        }
        

    }
}
