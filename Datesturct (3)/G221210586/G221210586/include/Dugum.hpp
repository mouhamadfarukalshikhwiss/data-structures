/**
* @fail dugum
* @aciklama. veri  kismi sayi  tipinden tanima ve dugumden sonraki tanimlama 
* @course ikinci ogretim c gurubu
* @assignment birinci  ödev 
* @datee 10/11/2023 26/11/2023
* @authorr mouhamad faruk alshikh wiss / mouhamad.wiss@ogr.sakarya.edu.tr
*/
#ifndef dugum_hpp
#define dugum_hpp
#include "sayi.hpp"
class Dugum
{
public:
    
    Dugum(Sayi* veri);
    Dugum(Sayi* veri,Dugum* sonraki);
    
    Sayi* veri;
    Dugum* sonraki;

};

#endif