//
// Created by Lenovo on 27.3.2018.
//

#include "ants.h"

ants::ants(){
    konumSatir = ' ';
    konumSutun = ' ';
}


ants::ants(int x , int y){
    konumSatir = x;
    konumSutun = y;
}

ants::~ants(){

}

int ants::getKonumSatir() const {
    return konumSatir;
}

int ants::getKonumSutun() const {
    return konumSutun;
}

void ants::setKonumSatir(int x) {
    konumSatir = x;
}

void ants::setKonumSutun(int y) {
    konumSutun = y;
}




