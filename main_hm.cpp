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
#define CR '\012'
using namespace std;

void brouse(int superFlag,totalManager& King,Customer & nowUser,struct termio tbuf,struct termio oldtbufr,vector<stockManageCar> carList);
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
    while(1){
        clear();
        cout<<"===========================================================================";
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        cout<<right<<setw(78)<<"1. 일반 로그인 2. 관리자 로그인 3. 회원가입 :"<<endl;
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        cout<<"===========================================================================";
        cin>>choiceMenu;
        string tempID, tempPW;
        Customer nowUser;
        vector<stockManageCar> carList = King.getList(); //여기에 대입할거 찾아
        char ch;
        string A="";
        switch(choiceMenu){
            case 1 :
            case 2 :
                clear();
                if(ioctl(0, TCSETAF, &oldtbuf)==-1) {perror("ioctl"); exit(1);}
                cout<<endl;
                cout<<"ID : ";
                cin>>tempID;
                nowUser= King.findUser(tempID);
                cout<<"PW : ";
                if(ioctl(0, TCSETAF, &tbuf)==-1) {perror("ioctl"); exit(1);}
                getchar();
                while(1){
                    ch=getchar();
                    if(ch==CR) break; printf("*");A+=ch;}

                tempPW=A;
                if(nowUser.correct_psswd(tempID,tempPW)){
                    clear();
                    if(ioctl(0, TCSETAF, &oldtbuf)==-1) {perror("ioctl"); exit(1);}
                    brouse(nowUser.checkAdmin(),King,nowUser,tbuf,oldtbuf,carList);
                }
                else cout<<"잘못 입력하셨습니다"<<endl;
                if(ioctl(0, TCSETAF, &tbuf)==-1) {perror("ioctl"); exit(1);}
                break;

            case 3 :
                cout<<endl;
                if(ioctl(0, TCSETAF, &tbuf)==-1) {perror("ioctl"); exit(1);}
                King.join();
                if(ioctl(0, TCSETAF, &tbuf)==-1) {perror("ioctl"); exit(1);}
                break;
            default :
                cout<<"잘못 입력하셨습니다"<<endl;
                break;
        
        }
    }
    

}
void brouse(int superFlag,totalManager& King,Customer & nowUser,struct termio tbuf,struct termio oldtbuf,vector<stockManageCar> carList){
    while(1){
        clear();
        if(ioctl(0, TCSETAF, &tbuf)==-1) {perror("ioctl"); exit(1);}
        cout<<"===========================================================================";
        cout<<endl<<endl<<endl<<endl<<endl;
        cout<<setw(30)<<" "<<"1. 구매 가능 리스트"<<endl;
        cout<<setw(30)<<" "<<"2. Top 5"<<endl;
        cout<<setw(30)<<" "<<"3. 장바구니 목록"<<endl;
        cout<<setw(30)<<" "<<"4. 구매차량 AS위치 "<<endl;
        if(nowUser.checkAdmin()){
            cout<<setw(30)<<" "<<"5. 차량 추가"<<endl;
            cout<<setw(30)<<" "<<"6. 재고관리"<<endl;
        }
        else{cout<<endl<<endl;}
        cout<<setw(30)<<" "<<"9. 뒤로가기"<<endl;
        cout<<endl<<endl<<endl<<endl;
   cout<<"===========================================================================";
   int number;
   cin>>number;
   switch(number){
        case 1:
            for(auto G : carList){
                clear();
                cout<<endl;
                cout<<"===========================================================================";
                cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
                cout<<endl<<setw(11)<<left<<"Brand"<<setw(11)<<left<<"Engine"<<setw(11)<<left<<"carname"<<setw(11)<<left<<"Color"<<setw(11)<<left<<"Type"<<setw(11)<<left<<"Price"<<setw(11)<<left<<"Quantity"<<endl<<endl;
                cout<<endl<<setw(11)<<left<<G.getBrand()<<setw(11)<<left<<G.getEngine()<<setw(11)<<left<<G.getCarName()<<setw(11)<<left<<G.getColor()<<setw(11)<<left<<G.getType()<<setw(11)<<left<<G.getSale()<<setw(11)<<left<<G.getQuantity()<<endl<<endl;
                cout<<endl<<endl<<endl<<endl<<endl;
                cout<<"==========================================================================="<<endl;
                M:
                cout<<"장바구니에 넣으시겠습니까?(y/n) : ";
                char purchaseChoice;
                cin>> purchaseChoice;
                switch(purchaseChoice){
                    case 'y':
                    case 'Y':
                        nowUser.addCart(G.getCarId());
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
            //탑리스트 stock 소환하기 필요
           cout<<endl<<setw(30)<<left<<"브랜드"<<setw(30)<<left<<"엔진"<<setw(30)<<left<<"차량이름"<<setw(30)<<left<<"색상"<<setw(30)<<left<<"타입"<<setw(30)<<left<<"가격"<<endl<<endl;
            //stockMangagerCar 리스트 소환하기.
            break;
        case 3:
            //nowUser.addCart(); //카리스트 뷰로 보기
            //구매여부 확인
            break;
        case 4:
            clear();
            if(ioctl(0, TCSETAF, &tbuf)==-1) {perror("ioctl"); exit(1);}
            cout<<"===========================================================================";
            cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
            cout<<right<<setw(45)<<"구매차량의 브랜드를 선택하세요"<<endl;
            cout<<right<<setw(45)<<"1.HKC     2.KIA       3.BENTZ"<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
            cout<<"===========================================================================";
            int choiceBrand;
            cin>>choiceBrand;
            if(ioctl(0, TCSETAF, &oldtbuf)==-1) {perror("ioctl"); exit(1);}
            clear();
            cout<<"===========================================================================";
            cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
            cout<<right<<setw(45)<<"고객의 위치를 입력해주세요"<<endl;
            cout<<right<<setw(45)<<"(ex : 34 28)"<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
            cout<<"==========================================================================="<<endl;
            int xPos,yPos;
            cin>>xPos>>yPos;
            if(ioctl(0, TCSETAF, &tbuf)==-1) {perror("ioctl"); exit(1);}
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
            //재고관리 만들어주세요
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