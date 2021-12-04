#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include <cstring>
#include "d:\C++\3termcpp\The Game\var.h"
#include "d:\C++\3termcpp\The Game\functions.h"

using namespace std;


void game_menu()
{
    pun = 1; kur[0] = '>'; code = 0;
	do {
		system("cls");
		printf("The Game\n\n%cНовая игра\n%cЗагрузить игру\n", kur[0], kur[1]);
		code = select_pun(2);
	} while (code==0);
	if (code==1)
		//enter_p_name();
		printf("Новая игра");
	else
		//load_s();
		printf("Загрузить");
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	game_menu();
	return 0;
}
