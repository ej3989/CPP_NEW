#ifndef _CAR_H
#define _CAR_H
#include <string>
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

class Car{
    string brand;
    string engine;
    string carName;
    string color;
    string type;
    int price;
    int carId;
    vector<pair<int,int>> asLocation;
public:
    Car(string brand="", string engine="", string carName="", 
    string color="",string type="", int price=0){
        this->brand = brand;
        this->engine = engine;
        this->carName = carName;
        this->color = color;
        this->type =type;
        this->price = price;
        carId = rand()%100000000;
        if(brand == "HMC"||brand =="hmc"||brand=="hyundai"||brand =="HYUNDAI"){
            asLocation.push_back(make_pair(2,38));
            asLocation.push_back(make_pair(15,56));
            asLocation.push_back(make_pair(29,5));
            asLocation.push_back(make_pair(7,3));
            asLocation.push_back(make_pair(1,66));
            asLocation.push_back(make_pair(7,48));
            asLocation.push_back(make_pair(12,40));
        }
        else if(brand == "KIA"||brand=="kia"||brand =="기아"){
            asLocation.push_back(make_pair(13,51));
            asLocation.push_back(make_pair(10,23));
            asLocation.push_back(make_pair(21,69));
            asLocation.push_back(make_pair(13,42));
            asLocation.push_back(make_pair(7,4));

        }
        else if(brand == "BENTZ"||brand=="bentz"||brand=="벤츠"){
            asLocation.push_back(make_pair(15,56));
            asLocation.push_back(make_pair(4,7));

        }//
    }
    string getBrand(){return brand;}
    string getEngine(){return engine;}
    string getCarName(){return carName;}
    string getColor(){return color;}
    string getType(){return type;}
    int getPrice(){return price;}
    int getCarId(){return carId;}
    vector<pair<int,int>>& getAspostion(){return asLocation;}
};
#endif
