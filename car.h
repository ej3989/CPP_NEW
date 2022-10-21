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
            asLocation.push_back(make_pair(68,48));
            asLocation.push_back(make_pair(71,97));
            asLocation.push_back(make_pair(53,67));
            asLocation.push_back(make_pair(55,10));
            asLocation.push_back(make_pair(49,33));
            asLocation.push_back(make_pair(91,67));
            asLocation.push_back(make_pair(3,65));
            asLocation.push_back(make_pair(29,25));
            asLocation.push_back(make_pair(83,84));
            asLocation.push_back(make_pair(37,84));
        }
        else if(brand == "KIA"||brand=="kia"||brand =="기아"){
            asLocation.push_back(make_pair(66,87));
            asLocation.push_back(make_pair(62,14));
            asLocation.push_back(make_pair(35,96));
            asLocation.push_back(make_pair(67,66));
            asLocation.push_back(make_pair(83,95));
            asLocation.push_back(make_pair(62,50));
            asLocation.push_back(make_pair(76,53));
            asLocation.push_back(make_pair(34,48));
        }
        else if(brand == "BENTZ"||brand=="bentz"||brand=="벤츠"){
            asLocation.push_back(make_pair(78,24));
            asLocation.push_back(make_pair(81,48));
            asLocation.push_back(make_pair(26,42));
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
