#include "car.h"
#include "stockmanagecar.h"
#include <iostream>
#include <vector>
#include <ctime>

void stockManageCar::quantityIncreasing(int number){
    quantity+=number; //number를 통한 재고 상승
}
void stockManageCar::quantityDecreasing(int number){
    quantity-=number; //재고 하락
}
int stockManageCar::getSale(){
    int price = getPrice();
    srand(time(NULL));
    int randGauge = rand()%20+1;
    return price*(80+randGauge)/100;
}
void stockManageCar::saleIncreasing(int number){
    saleQuan+=number; //number를 통한 재고 상승
}
void stockManageCar::saleDecreasing(int number){
    saleQuan-=number; //재고 하락
}