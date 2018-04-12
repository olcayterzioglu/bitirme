//
// Created by Lenovo on 27.3.2018.
//

#ifndef ACO_ANTS_H
#define ACO_ANTS_H

#include <iostream>
#include <string>

using namespace std;
class ants {

public:
    ants();//Default constructor

    ants(int , int);//Overload Constructor

    ~ants(); // Destructor

    //Accessor fucntions
    int getKonumSatir() const;
    int getKonumSutun() const;

    //Mutator functions

    void setKonumSatir(int);
    void setKonumSutun(int);






private:

    int konumSatir;
    int konumSutun;


};


#endif //ACO_ANTS_H
