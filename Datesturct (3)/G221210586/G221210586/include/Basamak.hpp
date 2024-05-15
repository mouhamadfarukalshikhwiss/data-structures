/**
* @fail basamak
* @aciklama. veri  basamaklari verisi ve sonrakini tanimla
* @course ikinci ogretim c gurubu
* @assignment birinci  ödev 
* @datee 10/11/2023 26/11/2023
* @authorr mouhamad faruk alshikh wiss / mouhamad.wiss@ogr.sakarya.edu.tr
*/
#ifndef basamak_hpp
#define basamak_hpp
#include<iostream>
using namespace std;
class basamak{


public:
int veri;
basamak* sonraki;
basamak(int veri,basamak* sonraki);
basamak(int veri);






};


















#endif