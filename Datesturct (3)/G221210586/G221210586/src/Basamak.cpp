/**
* @fail basamak
* @aciklama. veri  basamaklari verisi ve sonrakini tanimla
* @course ikinci ogretim c gurubu
* @assignment birinci  ödev 
* @datee 10/11/2023 26/11/2023
* @authorr mouhamad faruk alshikh wiss / mouhamad.wiss@ogr.sakarya.edu.tr
*/

#include"basamak.hpp"

basamak::basamak(int veri,basamak*sonraki){
    this->veri=veri;
    this->sonraki=sonraki;
}
basamak::basamak(int veri){

    this->veri=veri;
    this->sonraki=nullptr;
}