#define _MACRO_H
// x,y 좌표로 커서 이동
#define gotoxy(x,y) printf("[%d;%dH", y, x)
// 화면에 입력 문자 echo
#define setecho()   system("stty echo")
// 화면에 입력 문자 noecho
#define setnoecho() system("stty -echo")
// 한글자씩 입력
#define setraw()    system("stty raw");
// 한 문장씩 입력(개행문자 올때까지)
#define resetraw()  system("stty -raw -istrip sane")
// 화면 지우기
#define clear()     system("clear")