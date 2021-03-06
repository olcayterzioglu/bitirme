#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <string>
#include <iomanip>
#include <random>
#include <cstdlib>
#include <ctime>




using namespace std;
int main() {
    vector <double> esikVektoru;
    double toplamFeromon = 0;
    double sayac = 1;
    double kucukadet = 0;
    double buyukadet = 0;
    double kucuktoplam = 0;
    double kucukortalama = 0;
    double buyuktoplam = 0;
    double buyukortalama = 0;

    double epsilon = 0.00001;    //kenar belirleme hata toleransı

    int kenarMatrisi[200][300];
    double feromonMatrisi[200][300];

    // *********************************************
        string dosyaAdi = "resim17";
    //**********************************************


    ifstream file("..\\..\\resimdegerleri\\"+dosyaAdi+"FeromonMatrisi.txt");
    if(file.is_open())
    {


        for(int i = 0; i < 200; i++)                                                        // feromon değerleri diziye atıldı
        {
            for(int j = 0; j < 300; j++)
            {
                file >> feromonMatrisi[i][j];

            }

        }
        file.close();
    }

//    for (int i = 0; i <200 ; i++) {
//        for (int j = 0; j < 300; j++) {
//
//            printf("%f" , feromonMatrisi[i][j]) ;
//
//        }printf("\n *********************************" );
//    }


    esikVektoru.erase(esikVektoru.begin(), esikVektoru.end());

    for (int i = 0; i <200 ; i++) {
        for (int j = 0; j < 300; j++) {

            toplamFeromon = toplamFeromon + feromonMatrisi[i][j];

        }

    }
    printf("\n toplam feromon : %f \n feromon/piksel : %f " , toplamFeromon , toplamFeromon/60000);

    esikVektoru.push_back(toplamFeromon / 60000);
    printf("\n Esik vektoru manual ilk deger : %f " , esikVektoru[0]);



    bool durum = false ;




    while (durum == false)
    {
        for (int i = 0; i < 200 ; i++) {
            for (int j = 0; j < 300; j++) {

                if (feromonMatrisi[i][j] <= esikVektoru[sayac - 1])
                {
                    kucukadet = kucukadet + 1 ;
                    kucuktoplam = kucuktoplam + feromonMatrisi[i][j];
                }
                else
                {
                    buyukadet = buyukadet + 1;
                    buyuktoplam = buyuktoplam + feromonMatrisi[i][j];
                }

            }

        }
        kucukortalama = kucuktoplam / kucukadet ;
        buyukortalama = buyuktoplam / buyukadet ;
        esikVektoru.push_back((kucukortalama+buyukortalama) / 2);

        if(fabs(esikVektoru[sayac] - esikVektoru[sayac - 1]) > epsilon)
        {
            sayac = sayac + 1;
            kucukadet = 0;
            kucuktoplam = 0;
            buyukadet = 0;
            buyuktoplam = 0;
            kucukortalama = 0;
            buyukortalama = 0;
        }
        else
        {
            durum = true ;

        }

    }



    for (int i = 0; i <= sayac; i++) {

        printf("\n %d nolu esik degeri : %f" , i , esikVektoru[i]);

    }

    printf("\n sayac : %f \n esikdegeri : %f" , sayac , esikVektoru[sayac]);


    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 300; j++) {
            if (feromonMatrisi[i][j] >= esikVektoru[sayac] )
            {
                kenarMatrisi[i][j] = 255;
            }
            else
            {
                kenarMatrisi[i][j] = 0;
            }


        }

    }

    ofstream myfile ("..\\..\\resimdegerleri\\"+dosyaAdi+"kenarlar.txt");
    if (myfile.is_open())
    {

        for(int i = 0; i < 200; i++) {
            for (int j = 0; j < 300; j++) {
                myfile << kenarMatrisi[i][j] << " ";
            }
            myfile << "\n";
        }
        myfile.close();
    }
    else cout << "Unable to open file";


//    for (int i = 0; i <200 ; i++) {
//        for (int j = 0; j < 300; j++) {
//
//            printf(" %f",feromonMatrisi[i][j]);
//
//        }
//        printf("\n *****************************************");
//    }




    return 0;
}