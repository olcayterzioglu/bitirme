#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <string>
#include <iomanip>
#include <random>
#include "ants.h"
#include <cstdlib>
#include <ctime>



void karincaOlustur(vector<ants>&);
//void karincaYazdir(vector<ants>&);
using namespace std;
int karincaSayisi = 244;
int main() {
    srand(static_cast<int>(time(0)));
    vector <ants> karincalar;


    int iterasyon = 2 ;
    int karincaAdim = 100 ;

    double enbuyukolasilik = 0 ;
    int enbuyukolasiliksatir = 0 ;
    int enbuyukolasiliksutun = 0 ;
    vector <int> gidilensatir;
    vector <int> gidilensutun;



//    vector<vector<double>> feromonMatrisi(200, vector<double>(300));



    double ro = 0.1;            //feromon buharlaşma oranı
    double phi = 0.05;          //feromon bozulma katsayısı
    double tau_init = 0.0001 ;  //başlangıç feromon değeri
    double alpha = 1;           //feromon bilgisi ağırlık faktörü
    double beta = 0.1;          //sezgisel bilgi ağırlık faktörü
    double lamda = 1100;        //sezgisel matris katsayısı

    double lbpdegerleri[200][300];
    double sezgiselmatris[200][300];
    double karincaYonOlasilik[200][300];
    double feromonMatrisi[200][300];
    double toplamlbp = 0;


    ifstream file("C:\\Users\\Lenovo\\CLionProjects\\lbpveacoProje\\resimdegerleri\\resim1lbp.txt");
    if(file.is_open())
    {


        for(int i = 0; i < 198; i++)                                                        // lbp değerleri diziye atıldı
        {
            for(int j = 0; j < 298; j++)
            {
                file >> lbpdegerleri[i+1][j+1];
                toplamlbp = toplamlbp + lbpdegerleri[i+1][j+1];
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

            sezgiselmatris[i][j] = ( lbpdegerleri[i][j] / toplamlbp ) * lamda ;


        }
    }

//    for(int i = 0; i < 200; i++)                                                        // en kucuk ve en buyuk sezgiseli bulur
//    {
//        for(int j = 0; j < 300; j++)
//        {
//
//           if(sezgiselmatris[i][j] < enkucuksezgisel && sezgiselmatris[i][j] > 0)
//           {
//               enkucuksezgisel = sezgiselmatris[i][j];
//           }
//           if(sezgiselmatris[i][j] > enbuyuksezgisel)
//           {
//               enbuyuksezgisel = sezgiselmatris[i][j];
//           }
//
//
//        }
//    }


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


            karincaYonOlasilik[i][j] = pow(feromonMatrisi[i][j] , alpha) * pow(sezgiselmatris[i][j] , beta);
            //printf("%f" ,karincaYonOlasilik[i][j]); // olasilik matrisi yazdırır
        }

    }



    for (int n = 0; n < iterasyon ; n++) {
        karincaOlustur(karincalar);
//        karincaYazdir(karincalar);
//        printf("\n--------------------------------------------------\n");
        for (int m = 0; m <karincaSayisi ; m++) {
            gidilensatir.erase(gidilensatir.begin(), gidilensatir.end());  //yenisatır
            gidilensutun.erase(gidilensutun.begin(), gidilensutun.end());    //yenisatır

            gidilensatir.push_back(karincalar[m].getKonumSatir()); //
            gidilensutun.push_back(karincalar[m].getKonumSutun());



            for (int k = 0; k < karincaAdim; k++) {
                for (int i = (karincalar[m].getKonumSatir()) - 1; i < (karincalar[m].getKonumSatir()) + 2; i++) {
                    for (int j = (karincalar[m].getKonumSutun()) - 1; j < (karincalar[m].getKonumSutun()) + 2; j++) {

                        if(i < 0 || j < 0)
                        {
                            continue;
                        }
                        else if(i == karincalar[m].getKonumSatir() && j == karincalar[m].getKonumSutun()) {
                            continue;
                        }
                        else
                        {
                            for (unsigned z = 0; z < gidilensatir.size(); z++) {

                                if (i == gidilensatir[z] && j == gidilensutun[z]) {    //yenisatır
                                    // printf("\n  Gidilmeye calisilan yer %d %d \n" , i , j); //gidilmeye çalışılıpta gidilemeyen yeri  yazdırır
                                    goto cnt;
                                }
                            }

                        }


                        if (karincaYonOlasilik[i][j] >= enbuyukolasilik) {
                            enbuyukolasilik = karincaYonOlasilik[i][j];
                            enbuyukolasiliksatir = i;
                            enbuyukolasiliksutun = j;
                        }




                    }
                    cnt:; //yenisatır
                }
                karincalar[m].setKonumSatir(enbuyukolasiliksatir);
                karincalar[m].setKonumSutun(enbuyukolasiliksutun);



                feromonMatrisi[karincalar[m].getKonumSatir()][karincalar[m].getKonumSutun()] = ((1 - ro) * feromonMatrisi[karincalar[m].getKonumSatir()][karincalar[m].getKonumSutun()]) + (ro * sezgiselmatris[karincalar[m].getKonumSatir()][karincalar[m].getKonumSutun()]);
                karincaYonOlasilik[karincalar[m].getKonumSatir()][karincalar[m].getKonumSutun()] = pow(feromonMatrisi[karincalar[m].getKonumSatir()][karincalar[m].getKonumSutun()], alpha) * pow(sezgiselmatris[karincalar[m].getKonumSatir()][karincalar[m].getKonumSutun()], beta);


                enbuyukolasilik = 0;
                gidilensatir.push_back(enbuyukolasiliksatir); //
                gidilensutun.push_back(enbuyukolasiliksutun); //


//                printf("%d nolu karinca   %d %d adresine gitti (local feromon guncellemesi yapildi.)\n", m, karincalar[m].getKonumSatir(), karincalar[m].getKonumSutun());


            }
            //printf("\n--------------------------------------------------\n");

        }
//        printf("Feromon matrisi global olarak guncellendi\n" );
//        printf("\n--------------------------------------------------\n");
        for (int l = 0; l < 200; l++) {
            for (int i = 0; i < 300; i++) {

                feromonMatrisi[l][i] = ((1 - phi) * feromonMatrisi[l][i]) + (phi * tau_init);
//                printf("%f " , feromonMatrisi[l][i]  );


                }
//            printf("\n###########\n");
        }

        karincalar.erase(karincalar.begin(), karincalar.end());



    }

    // ****************************************************************************************************************** //







//    for (int l = 0; l < 200; l++) {
//        for (int i = 0; i < 300; i++) {
//
//
//                printf("%.30f " , feromonMatrisi[l][i]  );
//
//
//        }
//            printf("\n###########\n");
//    }


    ofstream myfile ("C:\\Users\\Lenovo\\CLionProjects\\lbpveacoProje\\resimdegerleri\\resim1FeromonMatrisi.txt");
    if (myfile.is_open())
    {

        for(int i = 0; i < 200; i++) {
            for (int j = 0; j < 300; j++) {
                myfile << feromonMatrisi[i][j] << " ";
            }
            myfile << "\n";
        }
        myfile.close();
    }
    else cout << "Unable to open file";


//    printf("en kucuk sezgisel : %.30f" , enkucuksezgisel);
//
//    double denemeformulu = 0;
//    double denemeformulu2 = 0;
//    denemeformulu = ((1-ro) * tau_init) + (ro * enkucuksezgisel * 1100);
//    denemeformulu2 = ((1-ro) * tau_init) + (ro * enbuyuksezgisel * 1100);

//    printf("\n kucuk deger : %.30f \n buyuk deger  : %.30f" , denemeformulu , denemeformulu2);

    return 0;
}

void karincaOlustur(vector<ants>& yeniKarincalar){

    for (int i = 0; i < karincaSayisi  ; i++) {
        ants yeniKarinca(rand() % 199 + 1, rand() % 299 + 1);
        yeniKarincalar.push_back(yeniKarinca);
    }
}

void karincaYazdir(vector<ants>& yeniKarincalar){
    unsigned int size = yeniKarincalar.size();
    for (unsigned int i = 0; i < size  ; i++) {
        printf("Karinca baslangic satiri : %d sutunu : %d\n" , yeniKarincalar[i].getKonumSatir() , yeniKarincalar[i].getKonumSutun());

    }
}