#ifndef __CUSTOMER_H
#define __CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>
#include "car.h"
#include "cursorCon.h"
#include <iomanip>
#include <unistd.h>
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
  vector<Car> my_car_list;
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
  void setName(string name){ this->name = name;}
  void setPhonenum(string name){ this->phone_number = name;}
  void setID(string name){ this->id = name;}
  void setAddress(string name){ this->address = name;}
  bool checkAdmin();
  bool correct_psswd(string id, string psswd);
  void addCart(int carId);
  int getCartCount();
  void addBuyingList(int carId);
  int getCarCount();
  void setMyCarList(Car paid_car);
  vector<Car> getMyCarList() {
    int ii = 0;
    cout << "=======================  MY CAR LIST ♬ =========================="
            "" << endl;
    cout << endl
         << setw(11) << left << "[n]:Brand" << setw(11) << left << "Car Name"
         << setw(11) << left << "Engline" << setw(11) << left << "Type"
         << setw(11) << left << "Color" << endl
         << endl
         << endl;

    for (auto g : this->my_car_list) {
      ii++;
      cout << "[" << ii << "]:" << setw(5) << left << g.getBrand() << setw(11)
           << left << g.getCarName() << setw(11) << left << g.getEngine()
           << setw(11) << left << g.getType() << setw(15) << left
           << g.getColor() << endl
           << endl;
    }
    cout << "================================================================="
         << endl;
    return this->my_car_list;
  }
};

#endif
