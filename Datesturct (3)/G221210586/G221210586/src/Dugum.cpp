/**
* @fail dugum
* @aciklama. veri  kismi sayi  tipinden tanima ve dugumden sonraki tanimlama 
* @course ikinci ogretim c gurubu
* @assignment birinci  ödev 
* @datee 10/11/2023 26/11/2023
* @authorr mouhamad faruk alshikh wiss / mouhamad.wiss@ogr.sakarya.edu.tr
*/
#include "Dugum.hpp"



 Dugum::Dugum(Sayi* veri){
    this->veri=veri;
    this->sonraki=NULL;
 }
 Dugum::Dugum(Sayi* veri,Dugum* sonraki){
    this->veri=veri;
    this->sonraki=sonraki;
 }
    