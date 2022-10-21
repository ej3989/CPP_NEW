#include <iostream>
#include <vector>
#include <string>
#include "stockmanagecar.h"
#include "totalManager.h"
#include "car.h"
#include "customerCar.h"
#include <iomanip>
#include <cstring>
#include <termio.h>
#include "cursorCon.h"
#include <unistd.h>
#define CR '\012'
using namespace std;

void brouse(int superFlag,totalManager& King,Customer * nowUser,struct termio tbuf,struct termio oldtbufr,vector<stockManageCar> carList);
int main(){
    totalManager King;
    King.loadCar();
    King.loadHuman();
    struct termio tbuf, oldtbuf;
    if(ioctl(0, TCGETA, &tbuf) == -1) { // 현재터미널모드
        perror("ioctl");    exit(1);
    }
    oldtbuf=tbuf;
    tbuf.c_lflag &= ~ECHO;
    tbuf.c_lflag&=~ICANON;
    tbuf.c_cc[VMIN] =1;
    tbuf.c_cc[VTIME]=0;
    if(ioctl(0, TCSETAF, &tbuf)==-1) {
        perror("ioctl"); exit(1);
    }
    cout<<"===========================================================================";
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<right<<setw(80)<<"홈페이지 접속을 원하시면 아무 키나 누르세요"<<endl;
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"===========================================================================";
    getchar();
    int choiceMenu;
    if(ioctl(0, TCSETAF, &oldtbuf)==-1) {perror("ioctl"); exit(1);}
    while(1){
        if(ioctl(0, TCSETAF, &tbuf)==-1) {perror("ioctl"); exit(1);}
        nclear();
        cout<<"===========================================================================";
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        cout<<right<<setw(78)<<"1. 일반 로그인 2. 관리자 로그인 3. 회원가입 4. 종료 :"<<endl;
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        cout<<"===========================================================================";
        char m;
        try{
        cin>>choiceMenu;
            if(cin.fail()) throw m;
        }
        catch(char x){
            cout<<"예외발생"<<endl;
            cin.clear();
            cin.ignore();
            continue;
        }
        if(ioctl(0, TCSETAF, &oldtbuf)==-1) {perror("ioctl"); exit(1);}
        string tempID, tempPW;
       Customer* nowUser;
        //vector<stockManageCar> carList = King.getcarlist(); //리스트 대입
        char ch;
        string A="";
        switch(choiceMenu){
            case 1 :
            case 2 :
                nclear();
                cout<<"===========================================================================";
                cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
                cout<<"                             ID : "<<endl;
                cout<<"                             PW : "<<endl;
                cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
                cout<<"===========================================================================";
                if(ioctl(0, TCSETAF, &oldtbuf)==-1) {perror("ioctl"); exit(1);}
                gotoxy(9,35);
                cin>>tempID;
                nowUser= King.findUser(tempID);
				if(nowUser == 0){
					break;
				}
				//cout <<"poinrt now user test"<< nowUser->getName() << endl;
                gotoxy(10,35);
                if(ioctl(0, TCSETAF, &tbuf)==-1) {perror("ioctl"); exit(1);}
                getchar();
                while(1){
                    ch=getchar();
                    if(ch==CR) break; printf("*");A+=ch;}

                tempPW=A;
                if(ioctl(0, TCSETAF, &oldtbuf)==-1) {perror("ioctl"); exit(1);}
                if(nowUser->correct_psswd(tempID,tempPW)){
                    nclear();
                    brouse(nowUser->checkAdmin(),King,nowUser,tbuf,oldtbuf,King.getcarlist());
                }
                else cout<<"잘못 입력하셨습니다"<<endl;
                break;

            case 3 :
                cout<<endl;
                if(ioctl(0, TCSETAF, &oldtbuf)==-1) {perror("ioctl"); exit(1);}
                King.join();
                break;
            case 4:
                cout<<endl;
                exit(0);
            default :
                cout<<"잘못 입력하셨습니다"<<endl;
                break;
        
        }
    }
    

}
void brouse(int superFlag,totalManager& King,Customer * nowUser,struct termio tbuf,struct termio oldtbuf,vector<stockManageCar> carList){
    while(1){
        nclear();
        if(ioctl(0, TCSETAF, &tbuf)==-1) {perror("ioctl"); exit(1);}
        cout<<"===========================================================================";
        cout<<endl<<endl<<endl<<endl<<endl;
        cout<<setw(30)<<" "<<"1. 구매 가능 리스트"<<endl;
        cout<<setw(30)<<" "<<"2. Top 5"<<endl;
        cout<<setw(30)<<" "<<"3. 장바구니 목록"<<endl;
        cout<<setw(30)<<" "<<"4. 구매차량 AS위치 "<<endl;
        if(nowUser->checkAdmin()){
            cout<<setw(30)<<" "<<"5. 차량 추가"<<endl;
            cout<<setw(30)<<" "<<"6. 재고관리"<<endl;
        }
        else{cout<<endl<<endl;}
        cout<<setw(30)<<" "<<"9. 뒤로가기"<<endl;
        cout<<endl<<endl<<endl<<endl<<endl;
   cout<<"===========================================================================";
   int number;
   char m;
   try{
   cin>>number;
   if(cin.fail()) throw m;
        }
        catch(char x){
            cout<<"예외발생"<<endl;
            cin.clear();
            cin.ignore();
            continue;
        }
   if(ioctl(0, TCSETAF, &oldtbuf)==-1) {perror("ioctl"); exit(1);}
   int ii=0;
   switch(number){
        case 1:
            for(auto G : King.getcarlist()){
                nclear();
                cout<<endl;
                cout<<"===========================================================================";
                cout<<endl<<endl<<endl<<endl;
                cout<<endl<<setw(11)<<left<<"Brand"<<setw(11)<<left<<"Engine"<<setw(11)<<left<<"carname"<<setw(11)<<left<<"Color"<<setw(11)<<left<<"Type"<<setw(11)<<left<<"Quantity"<<setw(11)<<left<<"Quantity"<<endl<<endl;
                cout<<endl<<setw(11)<<left<<G.getBrand()<<setw(11)<<left<<G.getEngine()<<setw(11)<<left<<G.getCarName()<<setw(11)<<left<<G.getColor()<<setw(11)<<left<<G.getType()<<setw(11)<<left<<G.getSale()<<setw(11)<<left<<G.getQuantity()<<endl<<endl;
                cout<<endl<<endl<<endl<<endl<<endl<<endl;
                cout<<"==========================================================================="<<endl;
                M:
                gotoxy(14,1);
                cout<<"장바구니에 넣으시겠습니까?(y/n) : ";
                char purchaseChoice;
                cin>> purchaseChoice;
                switch(purchaseChoice){
                    case 'y':
                    case 'Y':
                        nowUser->addCart(G.getCarId());
                        cout<<"장바구니에 넣으셨습니다"<<endl;
                        break;
                    case 'N':
                    case 'n':
                    break;
                    default :
                        cout<<"잘못 누르셨습니다"<<endl;
                        goto M;
                }

            }
            cout<<endl;
            
            break;
        case 2:
            nclear();

            King.printTop5();

            break;
        case 3:
      nclear();
			while(King.buyCarUser(*nowUser));
                        
            //장바구니 리스트 확인
            // 몇번 구매하시겠습니다. 
            //카아이디 포문 찾고, 거기 퀀티티 감소시키는거
            //nowUser.addCart(); //카리스트 뷰로 보기
            //구매여부 확인
            break;
        case 4:
            nclear();
            if(ioctl(0, TCSETAF, &tbuf)==-1) {perror("ioctl"); exit(1);}
            cout<<"===========================================================================";
            cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
            cout<<right<<setw(44)<<"Choose your Brand"<<endl;
            cout<<right<<setw(46)<<"1.HKC  2.KIA  3.BENTZ"<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
            cout<<"===========================================================================";
            int choiceBrand;
            ZZ:
            try{
            cin>>choiceBrand;
            if(cin.fail()) throw "숫자를 입력해주세요";
            }
            catch(const char* negative){
            cout<<negative<<endl;
            cin.clear();
            cin.ignore();
            goto ZZ;
            }
            if(ioctl(0, TCSETAF, &oldtbuf)==-1) {perror("ioctl"); exit(1);}
            XX:
            nclear();
            cout<<"===========================================================================";
            cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
            cout<<right<<setw(52)<<"Enter the customer's location"<<endl;
            cout<<right<<setw(52)<<"(MAX : 29 69)"<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
            cout<<"==========================================================================="<<endl;
            gotoxy(11,35);
            int xPos,yPos;
            try{
            cin>>xPos>>yPos;
            if(cin.fail()) {gotoxy(15,35);throw "숫자를 입력해주세요";}
            }
            catch(const char* negative){
            cout<<negative<<endl;
            cin.clear();
            cin.ignore();
            goto XX;
            }
            if(xPos>30 || yPos>70){cout<<"잘못입력하셨습니다"<<endl; goto XX;}
            nclear();
            if(choiceBrand==1){
                customerCar A("HYUNDAI");
                A.findAs(xPos,yPos);
            }
            else if(choiceBrand==2){
                customerCar A("KIA");
                A.findAs(xPos,yPos);
            }
            else if(choiceBrand==3){
                customerCar A("BENTZ");
                A.findAs(xPos,yPos);
            }
            else{ cout<<"잘못고르셨습니다"<<endl;}
            break;
        case 5:
            cout<<endl;
            King.addCarList();
            break;
        case 6:

            King.printCarList();

            break;
        case 9:
            if(ioctl(0, TCSETAF, &oldtbuf)==-1) {perror("ioctl"); exit(1);}
            return;
        default:
            cout<<endl;
            cout<<"잘못 누르셨습니다"<<endl;
            break;
        }
    if(ioctl(0, TCSETAF, &oldtbuf)==-1) {perror("ioctl"); exit(1);}
    }
}
