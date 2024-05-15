/**
* @fail sayilarlistesi
* @aciklama. tmizleme tersleme en buyuk silme ekleri basa al islemleri
* @course ikinci ogretim c gurubu
* @assignment birinci  ödev 
* @datee 10/11/2023 26/11/2023
* @authorr mouhamad faruk alshikh wiss / mouhamad.wiss@ogr.sakarya.edu.tr
*/


#ifndef Sayilariste_hpp
#define Sayilariste_hpp
#include"Dugum.hpp"
#include<iostream>

class Sayilariste
{
public:

Sayilariste();
bool bosmu();
 int boyut();
void ekle(Sayi*);
void tumu_tersle();
void temizle();
void tekleri_basa_sirala();
void en_buyuk_sil();
friend ostream& operator<<(ostream&,Sayilariste&);
~Sayilariste();
private:
int adres_uzunlugu_getir(Sayi*);
Dugum* ilk;
int liste_boyutu;

};




















#endif