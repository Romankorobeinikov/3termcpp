#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include <cstring>
#include <stdio.h>

using namespace std;
void delay (int ms)
{
	int c = clock() + ms;
	while (clock() < c);
}
int main(){
int userInput = 0;
int now = time(0);
int later = 0;
int elapsed = 0;
int i = 0 , ans1 = 0, ans = 0;

cout << "Enter number" <<endl;

do {

    if(_kbhit()) {
        userInput=getch();
        if(47<userInput && userInput<59){
        ans1 = ans*10 + (userInput-48);
        ans = ans1;
        }
        if(userInput == 8){
        ans1 = ans/10;
        ans = ans1;
        }
        if(userInput==45){
            ans1 = -1*ans;
            ans = ans1;
        }
        system("cls");
        cout <<userInput<<" "<<ans << " ";
    }

} while (userInput != 13 );



    system("cls");
    cout << "To"<<ans;


}
