#ifndef _TOTALMANAGER_H
#define _TOTALMANAGER_H
#include <iostream>
#include <vector>
#include <fstream>
#include "stockmanagecar.h" 
#include "customer.h"
using namespace std;

////
class totalManager {
	vector<stockManageCar> carlist;
	vector<Customer> customerData;
	//소환 함수 부탁드립니다. 
public:
	void loadCar();
	void loadHuman();
	void join();
	void addCarList();
	void saveCar();
	void saveHuman();
	void printCarList();
	void printHuman();
	void printTop5();
	vector<stockManageCar> getcarlist(){return carlist;};
	vector<Customer> getCustomerlist(){return customerData;};
	Customer* findUser(string name);
	bool buyCarUser(Customer & buyUser);
};

#endif
