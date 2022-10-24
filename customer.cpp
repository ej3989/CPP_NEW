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

void Customer::setMyCarList(Car paid_car){
  this->my_car_list.push_back(paid_car);
}
vector<Car> Customer::getMyCarList(){
	int ii = 0;
	cout << "=======================  MY CAR LIST ♬ =========================="
		"" << endl;
	cout << endl
		<< setw(11) << left << "[n]:Brand" << setw(11) << left << "Car Name"
		<< setw(11) << left << "Engline" << setw(11) << left << "Type"
		<< setw(11) << left << "Color" << endl
		<< endl
		<< endl;

	for (auto g : my_car_list) {
		ii++;
		cout << "[" << ii << "]:" << setw(5) << left << g.getBrand() << setw(11)
			<< left << g.getCarName() << setw(11) << left << g.getEngine()
			<< setw(11) << left << g.getType() << setw(15) << left
			<< g.getColor() << endl
			<< endl;
	}
	cout << "================================================================="
		<< endl;
	return my_car_list;
}



