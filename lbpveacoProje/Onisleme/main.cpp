#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <conio.h>


int main() {



    int eskidegerler[200][300];
    int yeniMatris[204][304];
    int yenidegerler[196][296];
    int yenidegerler4lu[198][298];
    int histogram[256];
    int ushesaplama[7];
    int toplam = 0;
    int toplam2 = 0;
    int lbptoplam = 0;
    using namespace std;

    string dosyaAdi = "resim17";


    ifstream file("..\\..\\resimdegerleri\\"+dosyaAdi+"degerler.txt");
    if(file.is_open())
    {


        for(int i = 0; i < 200; i++)
        {
            for(int j = 0; j < 300; j++)
            {
                file >> eskidegerler[i][j];
            }

        }
        file.close();
    }



    for(int i = 2; i < 198; i++)
    {
        for(int j = 2; j < 298; j++)
        {

            yenidegerler[i-2][j-2] =  fabs(eskidegerler[i+2][j-1] - eskidegerler[i-2][j+1]) + fabs(eskidegerler[i+1][j-2] - eskidegerler[i-1][j+2]) + fabs(eskidegerler[i-1][j-2] - eskidegerler[i+1][j+2]) + fabs(eskidegerler[i-2][j-1] - eskidegerler[i+2][j+1]) + fabs(eskidegerler[i-1][j-1] - eskidegerler[i+1][j+1])  + fabs(eskidegerler[i-1][j] - eskidegerler[i+1][j])  +  fabs(eskidegerler[i-1][j+1] - eskidegerler[i+1][j-1])  + fabs(eskidegerler[i][j+1] - eskidegerler[i][j-1]) ;
        }

    }



//    for(int i = 0; i < 198; i++)
//    {
//        for (int j = 0; j < 298; j++)                    // yenidegerleri ekrana yazdirir
//        {
//            printf("%d\t" , yenidegerler[i][j]);
//        }
//    }


    ofstream myfile ("..\\..\\resimdegerleri\\"+dosyaAdi+"onisleme.txt");
    if (myfile.is_open())
    {

        for(int i = 0; i < 196; i++) {
            for (int j = 0; j < 296; j++) {
                myfile << yenidegerler[i][j] << " ";         // 8'li yenideğerleri  txt'ye yazdırır.
                lbptoplam = lbptoplam + yenidegerler[i][j];
            }
            myfile << "\n";
        }
        myfile.close();
    }
    else cout << "Unable to open file";


















    return 0;






//    for(int i = 0; i < 200; ++i)
//    {
//        for (int j = 0; j < 300; ++j)                    // Eskidegerleri yazdirir
//        {
//            printf("%d\t" , eskidegerler[i][j]);
//        }
//    }



   return 0;



}