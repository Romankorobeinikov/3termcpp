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

using namespace std;

void menu()
{
	pun = 1; kur[0] = '>'; code = 0;
	do {
		system("cls");
		cout<<"�����: "<<p_name;
		printf(" (%d Lvl)\n������: %d$\n����: %d/%d XP\n\n%c�����������\n%c�������\n%c��� �����\n%c��������� ����\n", p_lv, gold, p_xp, lvl[p_lv-1], kur[0], kur[1], kur[2], kur[3]);
		code = select_pun(4);
	} while (code==0);
	switch (code) {
	case (1):
		//adventure_start();
		cout<<"1";
    break;
	case (2):
	    //shop();
	    cout<<"2";
	break;
	case (3):
        //my_player();
        cout<<"3";
	break;
	case (4):
        //save_s(true);
        cout<<"4";
	break;
	default:
	    menu();
    break;
	}
    menu();
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
		printf("The Game\n\n%c����� ����\n%c��������� ����\n", kur[0], kur[1]);
		code = select_pun(2);
	} while (code==0);
	if (code==1)
		enter_p_name();
	else
		//load_s();
		printf("���������");
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
