#include <iostream>
#include <string>
#include <vector>
#include "customer.h"
#include "car.h"
using namespace std;

Customer::Customer(string name = "", string phone_number = "", string id = "",
                   string psswd = "", int admin = 0, string address = "") {
  this->name = name;
  this->phone_number = phone_number;
  this->id = id;
  this->psswd = psswd;
  this->admin = admin;
  this->address = address;
  car_count = 0;
  cart_count = 0;
  
};
Customer::~Customer() {}
string Customer::getPhone() { return this->phone_number; }
string Customer::getName() { return this->name; }
string Customer::getId() { return this->id; }
string Customer::getAddress() { return this->address; }

bool Customer::checkAdmin() {
  if (this->admin == 0) //일반유저
    return false;
  else
    return true;
}

bool Customer::correct_psswd(string id, string psswd) {
  if (this->psswd == psswd) //일반유저
    return true;
  else
    return false;
}


void Customer::addBuyingList(int carId) {
  this->buying_list.push_back(carId);
  car_count++;
}

void Customer::addCart(int carId){
  this->cart.push_back(carId);
}

int Customer::getCarCount() { return car_count; }
