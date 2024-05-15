/**
* @fail sayilarlistesi
* @aciklama. tmizleme tersleme en buyuk silme ekleri basa al islemleri
* @course ikinci ogretim c gurubu
* @assignment birinci  ödev 
* @datee 10/11/2023 26/11/2023
* @authorr mouhamad faruk alshikh wiss / mouhamad.wiss@ogr.sakarya.edu.tr
*/
#include"Sayilaristesi.hpp"
#include"Dugum.hpp"



Sayilariste::Sayilariste(){
    ilk=new Dugum(new Sayi(int()));
    liste_boyutu=0;
}
 bool Sayilariste::bosmu(){
   return liste_boyutu==0;
    
    
}

int Sayilariste::adres_uzunlugu_getir(Sayi* gec){
const void * adres=static_cast<const void*>(gec);
stringstream st;
st<<adres;
string str=st.str();
return str.length();
}

 int Sayilariste:: boyut(){
    liste_boyutu++;
    return liste_boyutu;
 }
 void Sayilariste::ekle(Sayi* eklemek){
Dugum* gez=ilk;
for( ;gez->sonraki!=NULL;gez=gez->sonraki)
{

}
gez->sonraki=new Dugum(eklemek,NULL);
liste_boyutu++;
}
ostream  &operator<<(ostream& os,Sayilariste& sag ){
    int hucre=0;
    for (Dugum* gec=sag.ilk->sonraki;gec!=NULL;gec=gec->sonraki, hucre++)
    {

        os<<"##############";
        gec->veri->yazdir(1);
        os<<endl;
        int uzunluk=sag.adres_uzunlugu_getir(gec->veri);
        int kal=9 - uzunluk;
        os<<"#";
        os<<right<<setw(2)<< " ";
        os<<gec->veri;
        os<<right<<setw(2 + kal)<<"#";
        gec->veri->yazdir(2);
        os<<endl;
        os<<"#";
        os<<"------------";
        os<<"#";
        gec->veri->yazdir(1);
        os<<endl;
        os<<"#";
        os<<right<<setw(12)<<gec->veri->sayi_getir();
        os<<"#";
         gec->veri->yazdir(9);
        os<<endl;
        os<<"##############";
        gec->veri->yazdir(1);

        os<<endl<<endl;//a=sayilarin arasinda bosluk kalmak ici

        
    }
    return os;
    


}
void Sayilariste::tumu_tersle(){

for (Dugum* gec=ilk->sonraki;gec!=NULL;gec=gec->sonraki)
{
    gec->veri->listyi_tersle();
}
}
void Sayilariste::tekleri_basa_sirala()
{
for (Dugum* gez=ilk->sonraki;gez!=NULL;gez=gez->sonraki)
{
    gez->veri->tek_basamaklar_tasi();
}
}
void Sayilariste:: en_buyuk_sil(){
    if(bosmu()){
        return;
    }
  
    
   
   
    int hucre=0;
    int j=0;
    int enbuyuk_sayi=-1;
for (Dugum* gec=ilk->sonraki;gec!=NULL;gec=gec->sonraki){

    if(gec->veri->sayi_getir() > enbuyuk_sayi){
        hucre=j;
        enbuyuk_sayi=gec->veri->sayi_getir();
    }
    j++;
}
Dugum* en_buyukten_once;
j=0;
for (Dugum* gec=ilk;gec->sonraki!=NULL;gec=gec->sonraki)
{
    if (j==hucre)
    {
        en_buyukten_once=gec;
        break;
    }
    j++;
    
}
Dugum* gecici=en_buyukten_once->sonraki;
en_buyukten_once->sonraki=en_buyukten_once->sonraki->sonraki;
delete gecici;
liste_boyutu--;


}


void Sayilariste::temizle(){
while (!bosmu())
{
    en_buyuk_sil();
}

}

Sayilariste::~Sayilariste(){
temizle();
delete ilk;

}

