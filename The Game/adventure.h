using namespace std;

int competition (int difficulty)
{

    anum = random(10+victory, 1, 1);
    bnum = random(10+victory, 1, 2);
    cnum = random(10+victory, 1, 3);
    indicator = 0;
    task = random(3*(difficulty+1), 0);
    ttime = 5; btn = 0; ans = 0; ans1=0;
    int c = clock() + ttime*1000;
    switch (task) {
        case (0):

            while (clock() < c && btn != 13){
                    delay(100);
                system("cls");
                printf("Сколько будет %d + %d ?\nНа размышление %d c!\nВаш ответ: ",anum,bnum,(c-clock())/1000 + 1);
                vvod();
            };

            if(ans==anum+bnum){
                system("cls");
                printf("Верно!");
                return 1;
            } else{
                system("cls");
                if (indicator){
                    printf("Неверно!\n");
                }else{
                    printf("Не успел!\n");
                }
                printf("Верный ответ - %d\n", anum+bnum);
                return 0;
            }
        break;
        case (1):
            while (clock() < c && btn != 13){
                    delay(100);
                system("cls");
                printf("Сколько будет %d - %d ?\nНа размышление %d c!\nВаш ответ: ",anum,bnum,(c-clock())/1000 + 1);
                vvod();
            };
            if(ans==anum-bnum){
                system("cls");
                printf("Верно!");
                return 1;
            } else{
                system("cls");
                if (indicator){
                    printf("Неверно!\n");
                }else{
                    printf("Не успел!\n");
                }
                printf("Верный ответ - %d\n", anum-bnum);
                return 0;
            }
        break;
        case (2):
            while (clock() < c && btn != 13){
                    delay(100);
                system("cls");
                printf("Сколько будет %d * %d ?\nНа размышление %d c!\nВаш ответ: ",anum,bnum,(c-clock())/1000 + 1);
                vvod();
            };
            if(ans==anum*bnum){
                system("cls");
                printf("Верно!");
                return 1;
            } else{
                system("cls");
                if (indicator){
                    printf("Неверно!\n");
                }else{
                    printf("Не успел!\n");
                }
                printf("Верный ответ - %d\n", anum*bnum);
                return 0;
            }
        break;
        case (3):
            while (clock() < c && btn != 13){
                    delay(100);
                system("cls");
                printf("Сколько будет %d + %d * %d ?\nНа размышление %d c!\nВаш ответ: ",anum,bnum,cnum,(c-clock())/1000 + 1);
               vvod();
            };
            if(ans==anum+bnum*cnum){
                system("cls");
                printf("Верно!");
                return 1;
            } else{
                system("cls");
                if (indicator){
                    printf("Неверно!\n");
                }else{
                    printf("Не успел!\n");
                }
                printf("Верный ответ - %d\n", anum+bnum*cnum);
                return 0;
            }
        break;
        case (4):
        while (clock() < c && btn != 13){
                delay(100);
                        system("cls");
                        printf("Сколько будет %d - %d * %d ?\nНа размышление %d c!\nВаш ответ: ",anum,bnum,cnum,(c-clock())/1000 + 1);
                        vvod();
                    };
            if(ans==anum-bnum*cnum){
                system("cls");
                printf("Верно!");
                return 1;
            } else{
                system("cls");
                if (indicator){
                    printf("Неверно!\n");
                }else{
                    printf("Не успел!\n");
                }
                printf("Верный ответ - %d\n", anum-bnum*cnum);
                return 0;
            }
        break;
        case (5):
            while (clock() < c && btn != 13){
                delay(100);
                system("cls");
                printf("Сколько будет %d + %d + %d ?\nНа размышление %d c!\nВаш ответ: ",anum,bnum,cnum,(c-clock())/1000 + 1);
                vvod();
            };
            if(ans==anum+bnum+cnum){
                system("cls");
                printf("Верно!");
                return 1;
            } else{
                system("cls");
                if (indicator){
                    printf("Неверно!\n");
                }else{
                    printf("Не успел!\n");
                }

                printf("Верный ответ - %d\n", anum+bnum+cnum);
                return 0;
            }
        break;
        default:
        return 0;
    }
    delay(1000);
    system("cls");
}

void adventure(int mnstr_hp)
{
	do
	{
		system("cls");
		cout<<monster.get_name();
		printf(": %d HP\n", monster.hp);
		cout<<player.get_name();
		printf(": %d HP\nНажмите любую кнопку, чтобы атаковать", player.hp);
		btn = getch();
		system("cls");
		result = competition (difficulty);

		if (result==0) {
			printf("Вы промахнулись\n");
			promah++;
			delay(500);
		} else {
			int damage = attacking(monster.get_arm(), player.get_att());
			cout<<"Вы нанесли "<<monster.get_name();
			printf(" %d урона\n", damage);
			monster.hp -= damage;
			ydar++;
			delay(500);
		}
		if (monster.hp>0) {
			if (random(2, 0)==0) {
				cout<<monster.get_name()<<" промахнулся";
			} else {
				int damage = attacking(player.get_arm(), monster.get_att());
				cout<<monster.get_name();
				printf(" нанёс Вам %d урона", damage);
				player.hp -= damage;
			}
			btn = getch();
		}
		if (monster.hp<=0) {
			printf("\n\n");
			cout<<monster.get_name()<<" погиб\n";
			system("pause");
			system("cls");
			printf("Победа!\n");
			info = true;
			int sum = mnstr_hp+monster.get_att()+monster.get_arm();
			int rew_xp = sum*3/2, rew_gld = sum/7;
			victory++;
			bodies++;
			p_xp += rew_xp;
			gold += rew_gld;
			all_gold += rew_gld;
			printf("Награда: +%d$ +%d XP\n", rew_gld, rew_xp);
			new_lvl();
			if (victory == 53) {
				printf("Поздравляем! Вы очистили эти земли от зла! Награда: +500 $\n");
				gold += 500;
				proid = true;
			} else {
				if (victory == en_score[enemy_cof]) {
					enemy++;
					enemy_cof++;
					if (enemy == en_loc_score[loc_score]) {
						lvl_loc++;
						loc_score++;
					}
				}
			}
			system("pause");
			menu();
		}
		if (player.hp<=0) {
			printf("\n\n");
			cout<<player.get_name()<<" погиб\n";
			system("pause");
			system("cls");
			info = true;
			int rew_xp = ceil((mnstr_hp+monster.get_att()+monster.get_arm())*0.3);
			p_xp += rew_xp;
			death++;
			gold += 3;
			all_gold += 3;
			printf("Вы проиграли!\nНаграда: +3$ +%d XP\n", rew_xp);
			new_lvl();
			system("pause");
			menu();
		}
	} while (monster.hp>0);
}

void adventure_start()
{
	if ( proid==true ) {
		printf(" \nК сожалению, для вас больше нет приключений :(");
		btn = getch();
		menu();
	} else {
		system("cls");
		monster.set_param(sen_ar[victory], sen_at[victory], sen_hp[victory], enemy_st[enemy]);
		player.set_param(p_ar, p_at, p_hp, p_name);
		pun = 1; kur[0] = '>'; code = 0;
		do {
			system("cls");
			cout<<"Локация: "<<location[lvl_loc]<<"\n\n"<<monster.get_name();
			printf(":\nATT %d HP %d ARM %d\n\n", monster.get_att(), monster.hp, monster.get_arm());
			cout<<player.get_name();
			printf(":\nATT %d HP %d ARM %d\n\n%cНапасть\n%cВ меню", player.get_att(), player.hp, player.get_arm(), kur[0], kur[1]);
			code = select_pun(2);
		} while (code == 0);
		if (code == 1)
			adventure(monster.hp);
		else
			menu();
	}
}
