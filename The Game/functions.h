using namespace std;

void menu();

int select_pun(int maxi)
{
	btn = getch();
	switch (btn) {
	case (72): //('w' || 'W' || 72):
		if (pun==1) {
			kur[0] = ' ';
			pun = maxi;
			kur[maxi-1] = '>';
			return 0;
		} else {
			kur[pun-1] = ' ';
			kur[pun-2] = '>';
			pun--;
			return 0;
		}
	break;
	case (80): //('s' || 'S' || 80):
		if (pun==maxi) {
			kur[maxi-1] = ' ';
			pun = 1;
			kur[0] = '>';
			return 0;
		} else {
			kur[pun-1] = ' ';
			kur[pun] = '>';
			pun++;
			return 0;
		}
	break;
	case (13):
		kur[pun-1] = ' ';
		return pun;
	break;
	default:
		return 0;
	}
}

void enter_p_name()
{
	system("cls");
	printf("Введите ваш ник: ");
	cin>>::p_name;
}

void delay (int ms)
{
	int c = clock() + ms;
	while (clock() < c);
}

void save_s()
{
    system("cls");
    printf("Сохранение...\n");
	ofstream save;
	save.open("save.gws");
	save<<p_name<<endl<<gold<<endl<<p_at<<endl<<p_hp<<endl<<p_ar<<endl<<p_lv<<endl<<p_xp<<endl<<lvl_loc
	<<endl<<tren<<endl<<victory<<endl<<enemy<<endl<<enemy_cof<<endl<<loc_score<<endl<<all_gold<<endl
	<<bodies<<endl<<ydar<<endl<<promah<<endl<<proid<<endl<<win<<endl<<lose<<endl<<death<<endl
	<<att_id<<endl<<arm_id<<endl<<item_id<<endl<<arena_lock<<endl<<info;
	save.close();
    delay(1000);
    printf("Успешно сохранено!\n");
    system("pause");
    menu();
}

void load_s()
{
	ifstream load;
	load.open ("save.gws");
	if (load) {
		system("cls");
		printf("Загрузка...");
		load>>p_name>>gold>>p_at>>p_hp>>p_ar>>p_lv>>p_xp>>lvl_loc>>tren>>victory>>enemy>>enemy_cof>>loc_score>>all_gold>>bodies>>
		ydar>>promah>>proid>>win>>lose>>death>>att_id>>arm_id>>item_id>>arena_lock>>info;
		load.close();
		delay(1000);
	} else {
		system("cls");
		printf("Файл сохранения не найден!");
		delay(1000);
		enter_p_name();
	}
}
