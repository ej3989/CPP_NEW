#ifndef __CUSTOMER_H
#define __CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>
#include "car.h"
using namespace std;

class Customer {
private:
  string name;
  string phone_number;
  string id;
  string psswd;
  int admin; // (0:일반 / 1:슈퍼유저)
  string address;
  vector<int> cart;
  vector<int> buying_list;
  int car_count;
  int cart_count;
public:
  Customer(){
    this->name = "";
    this->phone_number = "";
    this->id = "";
    this->psswd = "";
    this->admin = 0;
    this->address = "";
    car_count = 0;
    cart_count = 0;
  }
  vector<int> getCart(){ return this->cart; }
  Customer(string name, string phone_number, string id,
           string psswd, int admin, string address);
  ~Customer();
  string getPhone();
  string getName();
  string getId();
  string getAddress();
  bool checkAdmin();
  bool correct_psswd(string id, string psswd);
  void addCart(int carId);
  int getCartCount();
  void addBuyingList(int carId);
  int getCarCount();
};

#endif