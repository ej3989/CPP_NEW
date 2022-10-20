#include "car.h"
#include "customerCar.h"
#include <vector>
#include <iostream>
#include <queue>

using namespace std;//수정용
void BFS(int x, int y,int(*visit)[100], int(*check)[100], int (*map)[100],vector<pair<int,int>> asPosition);
void customerCar::findAs(int x, int y){

    vector<pair<int,int>> checkAs= getAspostion(); //AS 센터 정보 
    int visit[100][100]={0,}; //visit 초기화
    int check[100][100]={0,}; //check 초기화(거리 계산용)
    int map[100][100]={0,}; // 0으로 기본 맵 초기화
    srand(time(NULL));
    for(int i=0;i<4000;i++){ //임의 랜덤으로 지도 상황 변경(1일시 교통불가)
        int newX=rand()%100;
        int newY=rand()%100;
        int flag =1;
        for(auto X : checkAs){ //혹시라도 교통불가가 센터와 겹치지 않도록 설정
            if(X.first==newX&&X.second==newY){ 
                flag =0; break;
            }
        }
        if(flag==1) map[newX][newY] = 1;
    }

    BFS(x,y,visit,check,map,checkAs);
}


void BFS(int x, int y,int(*visit)[100], int(*check)[100], int (*map)[100],vector<pair<int,int>> asPosition){
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    visit[x][y]=1;
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nX = x+dx[i]; //상하좌우 확인
            int nY = y+dy[i]; //상하좌우 상황 확인
            if(0<=nX && nX<100 &&0<=nY && nY<100){
                if(map[nX][nY]==0 && visit[nX][nY]==0){ //map 통과 가능시, visit없을시
                    check[nX][nY]=check[x][y]+1;
                    visit[nX][nY]=1;
                    q.push(make_pair(nX,nY));
                }
            }
        }
    }
    int MinLong = 100000; //임의 최대치
    int MinX = asPosition[0].first;
    int MinY = asPosition[0].second;
    for(auto G : asPosition){
        if(MinLong>check[G.first][G.second]&&check[G.first][G.second]!=0) {
            MinLong = check[G.first][G.second];
            MinX = G.first;
            MinY = G.second;
            }
    }
    if(MinLong ==100000) cout<<"기상악화로 아무곳도 갈수 없습니다"<<endl;
    //전부 도착 못할 시 기준 가정
    else {cout<<"("<<MinX<<","<<MinY<<") 로 가시면 총 "<<MinLong<<"km 걸립니다. "<<endl;
    int a;
    cout<<"1을 누르시면 주행모드로 전환됩니다. :";
    cin>>a;
    switch(a){
        case 1:
            break;
        default:
        cout<<"좋은하루되세요"<<endl;
    }
    }
}