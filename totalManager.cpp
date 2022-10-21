#include "totalManager.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <termio.h>
#include <iomanip>
#include <unistd.h>
#include "cursorCon.h"
void totalManager::loadCar(){


	stockManageCar *add_car ;
	add_car = new stockManageCar("HMC", "Normal", "grandeur","red","sedan/suv",5000,25);
	add_car->saleIncreasing(12);
	carlist.push_back(*add_car);
	add_car = new stockManageCar("KIA", "HEVcar", "staria","black","sedan",4000,30);
	add_car->saleIncreasing(22);
	carlist.push_back(*add_car);
	add_car = new stockManageCar("BENTZ", "EVcar", "E-class","white","sedan",9000,12);
	add_car->saleIncreasing(31);
	carlist.push_back(*add_car);
	add_car = new stockManageCar("KIA", "PBV", "sportage","silver","suv",3500,30);
	add_car->saleIncreasing(9);
	carlist.push_back(*add_car);
	add_car = new stockManageCar("HMC", "Noraml", "G90","red","sedan",8200,2);
	add_car->saleIncreasing(50);
	carlist.push_back(*add_car);


}
void totalManager::loadHuman(){

	Customer *add_custmer;
	add_custmer = new Customer ("kim","010-1111-1111","wer1","12345678",0,"seoul");
	customerData.push_back(*add_custmer);
	add_custmer = new Customer ("Charles","010-3333-1111","der1","12345678",0,"seoul");
	customerData.push_back(*add_custmer);
	add_custmer = new Customer ("Ken","010-4444-1111","wber1","12345678",0,"seoul");
	customerData.push_back(*add_custmer);
	add_custmer = new Customer ("Grec","010-5555-1111","11r31","12345678",0,"pusan");
	customerData.push_back(*add_custmer);
	add_custmer = new Customer ("admin","000-0000-0000","admin","12345678",1,"");
	customerData.push_back(*add_custmer);


}

void totalManager::printTop5(){
	auto temp_carlist = carlist;

	sort(temp_carlist.begin(),temp_carlist.end(),[](stockManageCar a, stockManageCar b)->bool{return (a.getSaleQuan()>b.getSaleQuan());});

	cout<<endl<<setw(25)<<left<<"Brand"<<setw(25)<<left<<"Engine"<<setw(25)<<left<<"Car Name"<<setw(25)<<left<<"Color"<<setw(25)<<left<<"Type"<<setw(25)<<left<<"Price"<<setw(25)<<left<<"Sales"<<endl<<endl;
	for(int i=0;i<5 ; i ++){	
		cout<<setw(25)<<left<<temp_carlist[i].getBrand()<<setw(25)<<left<<temp_carlist[i].getEngine()<<setw(25)
			<<left<<temp_carlist[i].getCarName()<<setw(25)<<left<<temp_carlist[i].getColor()<<setw(25)<<left
			<<temp_carlist[i].getType()<<setw(25)<<left<<temp_carlist[i].getPrice()<<setw(25)<<left<<temp_carlist[i].getSaleQuan()<<endl;
	}
	cin.get();
	cin.get();
}
Customer& totalManager::findUser(string name){

	auto it = find_if(customerData.begin(),customerData.end(),[name](Customer a)->bool{ return (a.getName() == name);});
	if(it==customerData.end()){
		cout << "사용자가 없습니다" << endl;
	}

	return *it;

}
void totalManager::buyCarUser(Customer & buyUser){

	//	if(ioctl(0, TCSETAF, &oldtbuf)==-1) {perror("ioctl"); exit(1);}
	int ii = 0;
	vector<stockManageCar> tempcar;
	cout<<endl<<"[ n ]"<<setw(11)<<left<<"Brand"<<setw(11)<<left<<"Engine"<<setw(11)<<left<<"carname"<<setw(11)<<left<<"Color"<<setw(11)<<left<<"Type"<<setw(11)<<left<<"Price"<<setw(11)<<left<<"Quantity"<<endl<<endl;
	for(auto ID: buyUser.getCart()){
		ii++;
		for(auto G: this->getcarlist()){
			if(G.getCarId()==ID)
				cout<<"["<<ii<<"]:"<<setw(11)<<left<<G.getBrand()<<setw(11)<<left<<G.getEngine()<<setw(11)<<left<<G.getCarName()<<setw(11)<<left<<G.getColor()<<setw(11)<<left<<G.getType()<<setw(11)<<left<<G.getSale()<<setw(11)<<left<<G.getQuantity()<<endl<<endl;
			tempcar.push_back(G);
		}
	}
	cout<<endl<<"몇번을 구매하시겠습니까?"<<endl;
	//cout << nowUser.getName() << " " << nowUser.getPhone() << endl;
X:
	int finalNumber;
	char error;
	try{
		cin>>finalNumber;
		if(cin.fail()) throw error;
	}
	catch(char x){
		cout<<"오타발생"<<endl;
		cin.clear();
		cin.ignore();
		goto X;
	}
	buyUser.setMyCarList(tempcar[finalNumber-1]);
	//tempcar[finalNumber-1].quantityDecreasing(-1);
	auto tmp_id = tempcar[finalNumber-1].getCarId();
	int i=0;
	for(auto G: carlist){

		if(G.getCarId()==tmp_id){
			carlist[i].quantityDecreasing(1);
			carlist[i].saleIncreasing(1);
			cout<<carlist[i].getCarName() << "을 구매 하셨습니다." << endl<<endl;
			//cout<<"quan test:" << G.getQuantity() << endl;
			break;
		}
		i++;

	}
	
	buyUser.getMyCarList();
	//cout<<endl<<setw(25)<<left<<"Brand"<<setw(25)<<left<<"Engine"<<setw(25)<<left<<"carname"<<setw(25)<<left<<"Color"<<setw(25)<<left<<"Type"<<setw(25)<<left<<"Price"<<setw(25)<<left<<"Quantity"<<setw(25)<<left<<"slaeQuan"<<endl<<endl;
	//for(auto carTemp: carlist){	
	//	cout<<endl<<setw(25)<<left<<carTemp.getBrand()<<setw(25)<<left<<carTemp.getEngine()<<setw(25)
	//		<<left<<carTemp.getCarName()<<setw(25)<<left<<carTemp.getColor()<<setw(25)<<left<<carTemp.getType()
	//		<<setw(25)<<left<<carTemp.getPrice()<<setw(25)<<left<<carTemp.getQuantity()<<setw(25)<<left<<carTemp.getSaleQuan()<<endl<<endl;
	//}

	//	for(auto temp : buyUser.getMyCarList()){
	//		cout<<"test" <<temp.getBrand()<< endl;
	//	}


	getchar();
	getchar();

}
void totalManager::saveCar(){
	//필요가 없음 ...

}
void totalManager::saveHuman(){

	// 필요가 없음...
}

void totalManager::printCarList() {
  //	for( auto out_data : carlist){
  //		cout << out_data.getBrand() << out_data.getCarId() << endl;
  //	}
  while (1) {
    nclear();
    cout << "=================================================================="
            "==================="
         << endl;
    int ii = 0;
    // cout<<endl<<setw(30)<<left<<"브랜드"<<setw(30)<<left<<"엔진"<<setw(30)<<left<<"차량이름"<<setw(30)<<left<<"색상"<<setw(30)<<left<<"타입"<<setw(30)<<left<<"가격"<<setw(30)<<left<<
    // 	"재고 수량"<<setw(30)<<left<<"판매수량"<<endl<<endl;
    cout << endl
         << setw(11) << left << "[n]:Brand" << setw(11) << left << "Engine"
         << setw(11) << left << "carname" << setw(11) << left << "Color"
         << setw(11) << left << "Type" << setw(11) << left << "Price"
         << setw(11) << left << "Quantity" << setw(11) << left << "slaeQuan"
         << endl
         << endl;

    for (auto carTemp : carlist) {
      ii++;
      cout << "[" << ii << "]:" << setw(11) << left << carTemp.getBrand()
           << setw(11) << left << carTemp.getEngine() << setw(11) << left
           << carTemp.getCarName() << setw(11) << left << carTemp.getColor()
           << setw(11) << left << carTemp.getType() << setw(11) << left
           << carTemp.getPrice() << setw(11) << left << carTemp.getQuantity()
           << setw(11) << left << carTemp.getSaleQuan() << endl
           << endl;
    }
    int choice_num, modi_qty;
    char purchaseChoice;
  M:
    cout << endl << "1) 차량정보를 수정하시겠습니까? [Y/N] >> ";
    cin >> purchaseChoice;

    if (purchaseChoice == 'y' || purchaseChoice == 'Y') {
      cout << "2) 몇번 차량을 수정하시겠습니까? >> ";
      while (1) {
        cin >> choice_num;
        if (choice_num > carlist.size())
          cout << "잘못된 선택입니다! 재선택 >> ";
        else
          break;
      }
      cout << "3) 수량 변경 (증가 : x / 감소 : -x) >> ";
      cin >> modi_qty;
      if (modi_qty > 0) {
        cout << "해당 차량의 수량이 증가됩니다. "
             << carlist[choice_num - 1].getQuantity() << " ▶  "
             << carlist[choice_num - 1].getQuantity() + modi_qty << endl;
        carlist[choice_num - 1].quantityIncreasing(modi_qty);
        sleep(1);
        
      } else if (modi_qty < 0 && ((carlist[choice_num-1].getQuantity() + modi_qty) >= 0)) {
        cout << "해당 차량의 수량이 감소됩니다. "
             << carlist[choice_num - 1].getQuantity() << " ▶  "
             << carlist[choice_num - 1].getQuantity() + modi_qty << endl;
            carlist[choice_num - 1].quantityDecreasing(modi_qty * -1);
        sleep(1);
      }

      else if (modi_qty < 0 && ((carlist[choice_num-1].getQuantity() + modi_qty) < 0)) {
        
        cout << " ERROR! : 수량이 0 보다 작습니다. " <<endl;
        cout << " 수정내용이 초기화 됩니다........ " <<endl;
        sleep(2);
      }

    } else if (purchaseChoice == 'n' || purchaseChoice == 'N')
      goto exit;

    else {
      cout << "잘못 누르셨습니다" << endl;
      goto M;
    }
  }
  exit:
  getchar();

}

void totalManager::printHuman(){
  string checker;
while (1) {
  N:
    nclear();
    cout << "=================================================================="
            "========="
         << endl;
    int ii = 0;
    cout << endl
         << setw(11) << left << "[n]:Name" << setw(20) << left << "Phone Number" << setw(11) << left << "ID" << setw(11) << left << "ADDRESS" << endl;
        
    for (auto CustomerTemp : customerData) {
      ii++;
      cout << "[" << ii << "]:" << setw(11) << left << CustomerTemp.getName() << setw(15) << left << CustomerTemp.getPhone() << setw(11) << left << CustomerTemp.getId() << setw(11) << left << CustomerTemp.getAddress()
           << endl;
    }
    int choice_num, modi_qty;
    char purchaseChoice;
  M:
    cout << endl << "1) 고객정보를 수정하시겠습니까? [Y/N] >> ";
    cin >> purchaseChoice;

    if (purchaseChoice == 'y' || purchaseChoice == 'Y') {
      cout << "2) 몇번 사람을 수정하시겠습니까? >> ";
      while (1) {
        cin >> choice_num;
        if (choice_num > customerData.size())
          cout << "잘못된 선택입니다! 재선택 >> ";
        else
          break;
      }
      cout << "3) 무엇을 수정하시겠습니까?" << endl;
      cout << "    Name -------------> 1 " << endl;
      cout << "    Phone Number -----> 2 " << endl;
      cout << "    ID ---------------> 3 " << endl;
      cout << "    Address ----------> 4 " << endl;
      cout << "    Account Delete ---> 5" << endl;
      cout << endl;
      cout << "    Cancle All -------> 0 " << endl;
      cout << "    Input Option -----> ";
      cin >> modi_qty;
      if (modi_qty == 1) {
        string new_;
        cout << "해당 고객의 이름이 변경됩니다. " << endl;
        cout << "New Name >> ";
        cin >> new_;
        cout << "성공적으로 변경되었습니다. ! " << customerData[choice_num-1].getName() << " ▶  " << new_ << endl;
        customerData[choice_num-1].setName(new_);        
        cout << endl;
        sleep(2);
      } 
      else if (modi_qty == 2){
        string new_;
        cout << "해당 고객의 전화번호가 변경됩니다. " << endl;
        cout << "New Phone number >> ";
        cin >> new_;
        cout << "성공적으로 변경되었습니다. ! " << customerData[choice_num-1].getPhone() << " ▶  " << new_ << endl;
        customerData[choice_num-1].setPhonenum(new_);        
        sleep(1);
      }
      else if (modi_qty == 3){
        string new_;
        cout << "해당 고객의 ID 변경됩니다. " << endl;
        cout << "New ID >> ";
        cin >> new_;
        cout << "성공적으로 변경되었습니다. ! " << customerData[choice_num-1].getId() << " ▶  " << new_ << endl;
        customerData[choice_num-1].setID(new_);        
        sleep(1);
      }
      else if (modi_qty == 4){
        string new_;
        cout << "해당 고객의 Address가 변경됩니다. " << endl;
        cout << "New Address >> ";
        cin >> new_;
        cout << "성공적으로 변경되었습니다. ! " << customerData[choice_num-1].getAddress() << " ▶  " << new_ << endl;
        customerData[choice_num-1].setAddress(new_);        
        sleep(1);
      }
      else if (modi_qty == 5){
        if(customerData[choice_num-1].getName() == "admin")
        {
          cout << "관리자 계정은 삭제할수 없습니다." << endl;
          cout << "수정 정보는 초기화 됩니다......" << endl;
          sleep (3);
          goto N;
        } else
        {
          cout << "정말로 삭제하시겠습니까? (되돌릴수 없습니다.) [Y/N] >> ";
          cin >> checker;
          if (checker == "y" || checker == "Y")
          {
            cout << "성공적으로 삭제되었습니다. ! " << endl;
            customerData.erase(customerData.begin() + choice_num - 1);
            sleep(2);
          }

          else
          {
            cout << "수정사항이 취소됩니다. " << endl;
            sleep(2);
            goto N;
          }
        }
      }
      else if (modi_qty == 0){
         goto exit;
      }
      }
      else if (purchaseChoice == 'N' || purchaseChoice == 'n'){
        goto exit;
      }
}
  exit:
  getchar();
}

void totalManager::join(){
	string name, phone_number,id,passwd,address;
	int admin(0);

	getchar();
	cout << "name : " ; 
	getline(cin, name,'\n');

	cout << "Phone number : ";
	getline(cin, phone_number,'\n');

	cout << "ID : ";
	getline(cin, id ,'\n'); //id 입력 후 동일 한 것이 있으면 실패 후 재 설정 함수 필요 

	cout << "passwd : ";
	getline(cin,passwd,'\n'); //passwd ** 로 입력....

	cout << "address : ";
	getline(cin, address,'\n');

	cout << " 생성 계정 타입 user: 0 , admin : 1 " << endl;
	int usertype;
	cin >> usertype ;
	if( usertype == 1){
		while(true){
			string admin_passwd;
			cout << "비빌 번호 입력 하세요(exit) " ;
			getline(cin, admin_passwd,'\n');

			if(admin_passwd == "mobis1234"){
				admin = 1;
				break;
			}else if(admin_passwd == "exit")
				break;

		}

	}


	Customer addcustomer(name, phone_number,id,passwd,admin,address);

	customerData.push_back(addcustomer);

}
void totalManager::addCarList(){
	string brand , engine, carName, color,type;
	int price,quantity;

	getchar();
	cout << "Brand(KIA/HYUNDAI/BENTZ) : " ;
	getline(cin, brand,'\n');

	cout << "ENGINE(Normal/HEV/EV) : " ;
	getline(cin,engine ,'\n');

	cout << "Carname : " ;
	getline(cin, carName,'\n');

	cout << "color(Black/White/Red/Silver) : " ;
	getline(cin, color,'\n');

	cout << "Type(SUV/Sedan): " ;
	getline(cin, type,'\n');

	cout << "Price : " ;
	cin >> price ;

	cout << "Qunatity : " ;
	cin >> quantity ;

	stockManageCar add_car(brand,engine,carName,color,type,price,quantity,0);

	carlist.push_back(add_car);



}



