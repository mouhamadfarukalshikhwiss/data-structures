/**
* @fail sayi
* @aciklama. adresi stringi cevirme tekleri ve ciftleri ayir liste tersleme adresin son uc hanesini al
* @course ikinci ogretim c gurubu
* @assignment birinci  ödev 
* @datee 10/11/2023 26/11/2023
* @authorr mouhamad faruk alshikh wiss / mouhamad.wiss@ogr.sakarya.edu.tr
*/


#include"sayi.hpp"
#include<iomanip>

basamak* Sayi::ondan_onceki_bulam(int aramak_index){
int hucre=0;
for(basamak* gezmek=ilk;gezmek!=NULL;gezmek=gezmek->sonraki ){

    if (hucre==aramak_index) return gezmek;
    hucre++;
}

return NULL;

}
Sayi::Sayi(int sayi){
    ilk=new basamak(int());
    liste_boyutu=0;
     this->sayi=sayi;
   
}
string Sayi::adresi_stringe_cevir(basamak* gez){
    const void * adres=static_cast<const void*>(gez);
    stringstream st;
    st<<adres;
    string str=st.str();
    return str;
}
string Sayi::adresin_son_hanler(string& adres){
    string str="";
    for(int i=5;i<8;i++){
        str=str+adres[i];
    }
    return str;
}
bool Sayi:: list_bosmu(){
return liste_boyutu==0;
}
int Sayi:: sayi_getir(){
    return sayi;
}
int Sayi::boyut(){
    return liste_boyutu;
}
void Sayi:: ekle(int eklemek){
    araya_eklemek(boyut(),eklemek);
}
void Sayi:: araya_eklemek(int hucre,int eklemek){
    basamak* once=ondan_onceki_bulam(hucre);
 once->sonraki=new basamak(eklemek,once->sonraki);
 liste_boyutu++;
}
void Sayi::yazdir(int kur ){
  
  if (kur==1)
  {
    for (basamak* gez=ilk->sonraki;gez!=NULL;gez=gez->sonraki)
    {
        cout<< right <<setw(5) <<" "<<"********";
    }
    
    
  }
  else if (kur==2)
  {
     for (basamak* gez=ilk->sonraki;gez!=NULL;gez=gez->sonraki)
    {
        cout<<right<<setw(5)<<" "<<"* ";
        string adr=adresi_stringe_cevir(gez);
        string sonadres=adresin_son_hanler(adr);

      cout<<  sonadres;
      cout<<"  *";
    }
  }
  else{

     for (basamak* gez=ilk->sonraki;gez!=NULL;gez=gez->sonraki)
    {
        cout<< right<< setw(5)<<"  "<< "*";
        cout<< right<< setw(2)<<" "<< gez->veri;
        cout<< right<< setw(2)<<"  "<< " *";
    }
  }
  
  
   
}

void Sayi::listyi_tersle(){
    basamak* yerim=ilk->sonraki;
    basamak* once=NULL;
    basamak* sonra=NULL;

    while (yerim!=NULL)
    {
        sonra=yerim->sonraki;
        yerim->sonraki=once;
        once=yerim;
        yerim=sonra;
    }
    ilk->sonraki=once;
    sayiyi_tersle();
}
void Sayi::sayiyi_tersle(){

    int sonuc=0;
     for (basamak* gez=ilk->sonraki;gez!=NULL;gez=gez->sonraki){
        sonuc=sonuc*10+gez->veri;
     }
      sayi=sonuc;
}

int Sayi:: tek_sayilar(){
int sonux=0;
for (basamak* gez=ilk->sonraki;gez!=NULL;gez=gez->sonraki){
    if (gez->veri%2==1)
        sonux++; 
}
return sonux;
}
basamak** Sayi::tek_basamaklari_al(){
int tekbasamaksayi=tek_sayilar();
basamak** tek_basamak=new basamak*[tekbasamaksayi];
int t=0;
for (basamak* gez=ilk->sonraki;gez!=NULL;gez=gez->sonraki)
if (gez->veri%2==1)
{
tek_basamak[t]=gez;
t++;
}
return tek_basamak;

}

basamak** Sayi::cift_basamaklari_al(){
int tekbasamaksayi=tek_sayilar();
int ciftbasamaksayisi=liste_boyutu-tekbasamaksayi;
basamak** cift_basamak=new basamak*[ciftbasamaksayisi];
int t=0;
for (basamak* gez=ilk->sonraki;gez!=NULL;gez=gez->sonraki)
if (gez->veri%2==0)
{
cift_basamak[t]=gez;
t++;
}
return cift_basamak;

}

void Sayi::tek_basamaklar_tasi(){
    basamak** tek=tek_basamaklari_al();
    basamak** cift=cift_basamaklari_al();
    int tekler_sayisi=tek_sayilar();
    int ciftler_sayisi=liste_boyutu-tekler_sayisi;

    basamak* simdi=ilk;
    for (int  i = 0; i <tekler_sayisi; i++)
    {
        simdi->sonraki=tek[i];
        simdi=tek[i];
    }
    for (int  i = 0; i <ciftler_sayisi; i++)
    {
        simdi->sonraki=cift[i];
        simdi=cift[i];
    }

    simdi->sonraki=NULL;
    sayiyi_tersle();
    
    

    
}


void Sayi:: temizlemek(){
    while (!list_bosmu())
    {
        komut_silmek(0);
    }
    
}

void Sayi:: komut_silmek(int hucre){

    basamak* silenen;
    basamak* silenen_once=ondan_onceki_bulam(hucre);
    silenen=silenen_once->sonraki;
    silenen_once->sonraki=silenen_once->sonraki->sonraki;
    liste_boyutu--;
}

Sayi::~Sayi(){
    temizlemek();
    delete ilk;
}
