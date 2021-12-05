#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include <cstring>
#include "d:\C++\3termcpp\The Game\classes.h"
#include "d:\C++\3termcpp\The Game\var.h"
#include "d:\C++\3termcpp\The Game\functions.h"
#include "d:\C++\3termcpp\The Game\shop.h"
#include "d:\C++\3termcpp\The Game\myplayer.h"
#include "d:\C++\3termcpp\The Game\adventure.h"

using namespace std;

void menu()
{
	pun = 1; kur[0] = '>'; code = 0;
	do {
		system("cls");
		cout<<"Игрок: "<<p_name;
		printf(" (%d Lvl)\nДеньги: %d$\nОпыт: %d/%d XP\n\n%cПутешествие\n%cМагазин\n%cМой герой\n%cСохранить игру\n%cНастройки\n",
            p_lv, gold, p_xp, lvl[p_lv-1], kur[0], kur[1], kur[2], kur[3], kur[4]);
		code = select_pun(5);
	} while (code==0);
	switch (code) {
	case (1):
		adventure_start();
    break;
	case (2):
	    shop();
	break;
	case (3):
        my_player();
	break;
	case (4):
        save_s();
	break;
	case (5):
        settings();
	break;
	default:
	    menu();
    break;
	}
}

void preparing()
{
	lvl[0] = 100;
	for (int i=1; i<50; i++)
		lvl[i] = lvl[ i-1 ]*2;
	tren_pr[0] = 3;
	for (int i=1; i<100; i++)
		tren_pr[i] = tren_pr[i-1]+3;
	armor.set_param(arm_b[arm_id], att_b[arm_id], hp_b[arm_id], shop_item[arm_id]);
	weapon.set_param(arm_b[att_id], att_b[att_id], hp_b[att_id], shop_item[att_id]);
	amulet.set_param(arm_b[item_id], att_b[item_id], hp_b[item_id], shop_item[item_id]);
}

void loading_game_menu()
{
    pun = 1; kur[0] = '>'; code = 0;
	do {
		system("cls");
		printf("The Game\n\n%cНовая игра\n%cЗагрузить игру\n", kur[0], kur[1]);
		code = select_pun(2);
	} while (code==0);
	if (code==1)
		enter_p_name();
	else
		load_s();
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	loading_game_menu();
	preparing();
	menu();
	return 0;
}
