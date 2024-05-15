#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include"Basamak.hpp"
#include"sayi.hpp"
#include"Dugum.hpp"
#include"Sayilaristesi.hpp"
using namespace std;
string dosyadan_oku(string);
string* sayilari_bolme(string,string);
int sayilarin_parcalari_getir(string ,string);
int* sayilayri_basamaklara_ayir(string );


int main()
{
string satir_oku=dosyadan_oku("sayilar.txt");
int sayilarin_sayisi=sayilarin_parcalari_getir(satir_oku," ");
string* parcalar=sayilari_bolme(satir_oku," ");
Sayilariste* sayilistesi=new Sayilariste();
Sayi* tur;
for (int i = 0; i < sayilarin_sayisi; i++)
{
    string sayi=parcalar[i];
 int*basamaklar=sayilayri_basamaklara_ayir(sayi);
 tur=new Sayi(stoi(sayi));

 
for (int j = 0; j <sayi.length(); j++){
 tur->ekle(basamaklar[j]);

}
sayilistesi->ekle(tur);
}
int sec=0;
bool devam=true;

while (devam&& !sayilistesi->bosmu()) 
{
   
    cout<<*sayilistesi<<endl;
cout<<"-----MENU-----"<<endl;
cout<<"1.Tek Basamaklari Basa Al..."<<endl;
cout<<"2.Basamaklari Tersle..."<<endl;
cout<<"3.En Buyuk Cikar..."<<endl;
cout<<"4.Cikis..."<<endl;
cin>>sec;
 if(sayilistesi->bosmu())
    break;

switch (sec)
{
case 1:
sayilistesi->tekleri_basa_sirala();
    break;
case 2:
sayilistesi->tumu_tersle();

break;
case 3:
sayilistesi->en_buyuk_sil();
break;
case 4:
return false;
break;
default:
cout<<"HATALI SECIM!!"<<endl;
return false;
    break;
}




}
delete sayilistesi;
delete parcalar;
cout<<endl<<endl<<endl;
cout<<"Program sonlandirilmistir..."<<endl;
















return 0;
}
















































string dosyadan_oku(string dosya_adi){
    ifstream sayilar_dosya(dosya_adi);
    string satir_oku;
    getline(sayilar_dosya,satir_oku);

    return satir_oku;
}

string* sayilari_bolme(string satir,string karakter){

    int pos_karakter=0;
    string parcala;
    int sayilari_parcala=sayilarin_parcalari_getir(satir,karakter);
string* parcalar=new string[sayilari_parcala];
int p=0;
while ((pos_karakter=satir.find(karakter)) !=std::string::npos )//while ((pos_karakter = satir.fin(karakter)) != std::string::npos)

{
    parcalar[p]=satir.substr(0,pos_karakter);//parcalar[p] = str.substr(0, pos_karakter);

    satir.erase(0,pos_karakter+karakter.length());
    p++;
}
parcalar[p]=satir;//son sayiyi getirmek icin
return parcalar;


}
int sayilarin_parcalari_getir(string satir,string karakter){
int sonucu=0;
    for(char kr : satir){
    if (kr ==' ')
        sonucu++;
    }
    sonucu++;//her zaman sayilarin sayisi bosluklardan bir fazla
return sonucu;
}
int* sayilayri_basamaklara_ayir(string sayi){
    int*basamaklar=new int[sayi.length()];
    int rakam=stoi(sayi);
    int j=0;
    while (rakam!=0)
    {
        int basamak=rakam%10;
        rakam=rakam/10;
        basamaklar[j]=basamak;
        j++;

    }
    
    int* cevir=new int[sayi.length()];
    for (int i = 0; i <sayi.length(); i++)
    {
        cevir[i]=basamaklar[sayi.length()-i-1];
    }
    return cevir;
    
    
}




