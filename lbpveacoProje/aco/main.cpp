#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include "ants.h"

int main() {

    int iterasyon ;
    int karincaSayisi;
    static int karincaAdim = 5 ;
    double enbuyukolasilik = 0 ;
    int enbuyukolasiliksatir = 0 ;
    int enbuyukolasiliksutun = 0 ;

    double ro = 0.1;            //feromon buharlaşma oranı
    double phi = 0.05;          //feromon bozulma katsayısı
    double tau_init = 0.0001 ;  //başlangıç feromon değeri
    double alpha = 1;           //feromon bilgisi ağırlık faktörü
    double beta = 0.1;          //sezgisel bilgi ağırlık faktörü
    double epsilon = 0.00001;   // kenar belirleme hata toleransı

    double lbpdegerleri[200][300];
    double sezgiselmatris[198][298];
    double karincaYonOlasilik[198][298];
    double feromonMatrisi[200][300];
    double toplamlbp;
    using namespace std;

    ifstream file("C:\\Users\\Lenovo\\CLionProjects\\lbpveacoProje\\resimdegerleri\\resim3lbp.txt");
    if(file.is_open())
    {


        for(int i = 0; i < 198; i++)                                                        // lbp değerleri diziye atıldı
        {
            for(int j = 0; j < 298; j++)
            {
                file >> lbpdegerleri[i+1][j+1];
                toplamlbp = toplamlbp + lbpdegerleri[i][j];
            }

        }
        file.close();
    }

    for (int i = 0; i <299 ; i++) {

        lbpdegerleri[0][i] = 0 ;
        lbpdegerleri[199][i] = 0 ;

    }                                               // ek satır sütun eklendi negatif değerlerle uğraşmamak için
    for (int i = 0; i <199 ; i++) {

        lbpdegerleri[i][0] = 0 ;
        lbpdegerleri[i][299] = 0 ;

    }



    for(int i = 0; i < 200; i++)                                                        // sezgisel matris hesaplandı (her piksel icin lbp/toplamlbp)
    {
        for(int j = 0; j < 300; j++)
        {

            sezgiselmatris[i][j] = lbpdegerleri[i][j] / toplamlbp ;
        }

    }

    for(int i = 0; i < 200; i++)                                                        // feromon matrisi başlangıç değerleri atandı
    {
        for(int j = 0; j < 300; j++)
        {

            feromonMatrisi[i][j] = tau_init ;
        }

    }

    for(int i = 0; i < 200; i++)                                                        //olasılık matrisinin ilk hali hesaplandı
    {
        for(int j = 0; j < 300; j++)
        {

            karincaYonOlasilik[i][j] = pow(tau_init , alpha) * pow(sezgiselmatris[i][j] , beta);
            //printf("%f" ,karincaYonOlasilik[i][j]); // olasilik matrisi yazdırır
        }

    }

    ants karinca1(1,1);  // karinca nesnesi oluşturuldu


    for (int k = 0; k < karincaAdim ; k++) {    //bu kısma karınca sayısı döngüsü ve iterasyon sayısıda eklenecek
        for(int i=karinca1.konumsatir - 1 ; i < karinca1.konumsatir +2 ; i++){
            for(int j=karinca1.konumsutun - 1 ; j < karinca1.konumsutun +2 ; j++){
                if(i == karinca1.konumsatir && j == karinca1.konumsutun)
                {
                    continue;
                }
                if(karincaYonOlasilik[i][j] >= enbuyukolasilik )
                {
                    enbuyukolasilik = karincaYonOlasilik[i][j];
                    enbuyukolasiliksatir = i;
                    enbuyukolasiliksutun = j;
                }

            }
        }
        karinca1.konumsatir = enbuyukolasiliksatir ;
        karinca1.konumsutun = enbuyukolasiliksutun ;
        feromonMatrisi[karinca1.konumsatir][karinca1.konumsutun] = ((1 - ro)*karincaYonOlasilik[karinca1.konumsatir][karinca1.konumsutun]) + (ro * sezgiselmatris[karinca1.konumsatir][karinca1.konumsutun]) ;
        karincaYonOlasilik[karinca1.konumsatir][karinca1.konumsutun]= pow(feromonMatrisi[karinca1.konumsatir][karinca1.konumsutun] , alpha ) * pow(sezgiselmatris[karinca1.konumsatir][karinca1.konumsutun] , beta);


    }





   // printf("%d" , toplamlbp);




    return 0;
}