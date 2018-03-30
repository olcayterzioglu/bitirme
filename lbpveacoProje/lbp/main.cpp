#include <iostream>
#include <fstream>
#include <math.h>

int main() {

    int eskidegerler[200][300];
    int yenidegerler[198][298];
    int yenidegerler4lu[198][298];
    int histogram[256];
    int ushesaplama[7];
    int toplam = 0;
    int toplam2 = 0;
    int lbptoplam = 0;
    using namespace std;

    ifstream file("C:\\Users\\Lenovo\\CLionProjects\\lbpveacoProje\\resimdegerleri\\resim3degerler.txt");
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

    for(int i = 1; i < 199; i++)
    {
        for(int j = 1; j < 299; j++)
        {
            toplam = 0 ;
            toplam2 = 0 ;
            if(eskidegerler[i][j-1] >= eskidegerler[i][j] )
            {
                toplam = toplam + 1 ;
                toplam2 = toplam2 +1 ;
            }
            else
            {
                toplam = toplam + 0 ;
                toplam2 = toplam2 + 0 ;
            }
            if(eskidegerler[i+1][j-1] >= eskidegerler[i][j] )
            {
                toplam = toplam + 2 ;
            }
            else
            {
                toplam = toplam + 0 ;
            }
            if(eskidegerler[i+1][j] >= eskidegerler[i][j] )
            {
                toplam = toplam + 4 ;
                toplam2 = toplam2 + 2 ;
            }
            else
            {
                toplam = toplam + 0 ;
                toplam2 = toplam2 + 0 ;
            }
            if(eskidegerler[i+1][j+1] >= eskidegerler[i][j] )
            {
                toplam = toplam + 8  ;
            }
            else
            {
                toplam = toplam + 0 ;
            }
            if(eskidegerler[i][j+1] >= eskidegerler[i][j] )
            {
                toplam = toplam + 16 ;
                toplam2 = toplam2 + 4 ;
            }
            else
            {
                toplam = toplam + 0 ;
                toplam2 = toplam2 + 0 ;
            }
            if(eskidegerler[i-1][j+1] >= eskidegerler[i][j] )
            {
                toplam = toplam + 32 ;
            }
            else
            {
                toplam = toplam + 0 ;
            }
            if(eskidegerler[i-1][j] >= eskidegerler[i][j] )
            {
                toplam = toplam + 64 ;
                toplam2 = toplam2 + 8 ;
            }
            else
            {
                toplam = toplam + 0 ;
                toplam2 = toplam2 + 0 ;
            }
            if(eskidegerler[i-1][j-1] >= eskidegerler[i][j] )
            {
                toplam = toplam + 128 ;
            }
            else
            {
                toplam = toplam + 0 ;
            }

            yenidegerler[i-1][j-1] = toplam;
            yenidegerler4lu[i-1][j-1] = toplam2;
            histogram[toplam] += 1;


        }

    }

//    for(int i = 0; i < 200; i++)
//    {
//        for (int j = 0; j < 300; j++)                    // eskidegerleri ekrana yazdirir
//        {
//            printf("%i\t" , eskidegerler[i][j]);
//        }
//
//    }

    for(int i = 0; i < 198; i++)
    {
        for (int j = 0; j < 298; j++)                    // yenidegerleri ekrana yazdirir
        {
            printf("%d\t" , yenidegerler[i][j]);
        }
    }


    ofstream myfile ("C:\\Users\\Lenovo\\CLionProjects\\lbpveacoProje\\resimdegerleri\\resim3lbp.txt");
    if (myfile.is_open())
    {

        for(int i = 0; i < 198; i++) {
            for (int j = 0; j < 298; j++) {
                myfile << yenidegerler[i][j] << " ";         // 8'li yenideğerleri  txt'ye yazdırır.
                lbptoplam = lbptoplam + yenidegerler[i][j];
            }
            myfile << "\n";
        }
        myfile.close();
    }
    else cout << "Unable to open file";


    ofstream myfile2 ("C:\\Users\\Lenovo\\CLionProjects\\lbpveacoProje\\resimdegerleri\\resim3lbp4lu.txt");
    if (myfile2.is_open())
    {

        for(int i = 0; i < 198; i++) {
            for (int j = 0; j < 298; j++) {
                myfile2 << yenidegerler4lu[i][j] << " ";         // 4'lu yenideğerleri  txt'ye yazdırır.
            }
            myfile2 << "\n";
        }
        myfile2.close();
    }
    else cout << "Unable to open file";

//    ofstream myfile("C:\\denemedegerler.txt");
//    if (myfile.is_open())
//    {
//
//        for(int i = 0; i < 200; i++) {
//            for (int j = 0; j < 300; j++)
//            {
//                myfile << eskidegerler[i][j] << " ";                //eski degerleri txt'ye yazdırır
//            }
//            myfile << "\n";
//        }
//        myfile.close();
//    }
//    else cout << "Unable to open file";












    printf("%d" , lbptoplam);
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