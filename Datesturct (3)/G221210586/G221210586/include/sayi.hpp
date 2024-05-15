#ifndef sayi_hpp
/**
* @fail sayi
* @aciklama. adresi stringi cevirme tekleri ve ciftleri ayir liste tersleme adresin son uc hanesini al
* @course ikinci ogretim c gurubu
* @assignment birinci  ödev 
* @datee 10/11/2023 26/11/2023
* @authorr mouhamad faruk alshikh wiss / mouhamad.wiss@ogr.sakarya.edu.tr
*/
#define sayi_hpp
#include "basamak.hpp"
#include<iomanip>
#include<sstream>
class Sayi
{

public:
Sayi(int);
basamak** tek_basamaklari_al();
basamak** cift_basamaklari_al();
int sayi_getir();
bool list_bosmu();
int boyut();
void ekle(int eklemek);
void araya_eklemek(int hucre ,int eklemek);
void komut_silmek(int hucre);
void temizlemek();
void yazdir(int);
void sayiyi_tersle();
int tek_sayilar();
void listyi_tersle();
void tek_basamaklar_tasi();
private:
basamak*ilk;
basamak* ondan_onceki_bulam(int hucre);
string adresi_stringe_cevir(basamak*);
string adresin_son_hanler(string&);
int sayi;
int liste;
int liste_boyutu;
~Sayi();
};



















#endif