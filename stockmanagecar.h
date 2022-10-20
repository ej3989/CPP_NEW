#ifndef _STOCKMANAGECAR_H
#define _STOCKMANAGECAR_H
#include <string>
#include <iostream>
#include "car.h"
using namespace std;

class stockManageCar: public Car{
    int quantity;
    int saleQuan;
public:
    stockManageCar(string brand="", string engine="", string carName="", 
    string color="",string type="", int price=0, int quantity=10, int saleQuan=0):Car(brand,engine,carName,color,type,price){
        this->quantity = quantity;
        this->saleQuan = saleQuan;
    }
    //기존 quantity는 10대로 고정.
    int getQuantity(){return quantity;}
    void quantityIncreasing(int number);
    void quantityDecreasing(int number);
    void saleIncreasing(int number);
    void saleDecreasing(int number);
    int getSale();
    int getSaleQuan(){return saleQuan;}
};
#endif
