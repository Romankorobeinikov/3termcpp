using namespace std;

void menu();

void vvod()
{
    if (indicator==1){
        cout<<ans;
    } else if (indicator==-1){
        cout<<"-";
    }

    if(_kbhit())
    {
        btn=getch();

        if(47<btn && btn <59){
        ans1 = ans*10 + (btn-48)*(abs(ans)/ans);
        ans = ans1;
        if (indicator==-1){
                ans=-1*ans1;
            }
        indicator = 1;
        }

        if(btn==45){
            ans1 = -1*ans;
            ans = ans1;
            if (indicator==0){
                indicator=-1;
            }
        }

        if(btn == 8){
        ans1 = ans/10;
        ans = ans1;
        if (indicator==-1){
                indicator=0;
            }
    }
    }
}

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

int random(int n, int m, int jk = 1)
{
	srand(time(NULL)*jk);
	return rand()%n+m;
}

int attacking(int armor, int attack)
{
	int ar_coef1 = random(50, 1);
	float ar_coef = ar_coef1;
	ar_coef /= 100;
	int ar_damage = armor*ar_coef;
	if (attack-ar_damage<=0)
		return 0;
	else
		return attack-ar_damage;
}

void new_lvl()
{
	if (p_xp>=lvl[p_lv-1]) {
		printf("Новый уровень! +10$ и +5 ко всем параметрам!\n");
		p_lv++;
		gold += 10;
		p_at += 5;
		p_hp += 5;
		p_ar += 5;
		all_gold+= 10;
		if (p_lv>=6 && arena_lock == true)
			arena_lock = false;
	}
}

void settings()
{
	pun = 1; kur[0] = '>'; code = 0;
	do {
		system("cls");
		printf("Настройки\n\n%cСложность: \t", kur[0]);
		if (difficulty)
			printf("Сложно");
		else
			printf("Легко");
		printf("\n%cВ меню", kur[1]);
		code = select_pun(2);
	} while (code == 0);
	if (code == 1) {
		if (difficulty)
			difficulty = 0;
		else
			difficulty = 1;
		settings();
	} else
		menu();
}
