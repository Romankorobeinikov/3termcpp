using namespace std;

void my_player();

void inform()
{
	system("cls");
	printf("�����: %d\n�������: %d\n�������� ������: %d\n�������: %d\n����������: %d$\n\n", bodies, death, ydar, promah, all_gold);
	system("pause");
	my_player();
}

void inv_print(int num)
{
	switch (num) {
    case (1):
	cout<<weapon.get_name();
	if (weapon.get_name() != "�����")
		printf("\nHP\t+%d\nATT\t+%d\nARM\t+%d", weapon.get_hp(), weapon.get_att(), weapon.get_arm());
	break;
    case (2):
	cout<<armor.get_name();
	if (armor.get_name() != "�����")
		printf("\nHP\t+%d\nATT\t+%d\nARM\t+%d", armor.get_hp(), armor.get_att(), armor.get_arm());
	break;
    case (3):
	cout<<amulet.get_name();
	if (amulet.get_name() != "�����")
		printf("\nHP\t+%d\nATT\t+%d\nARM\t+%d", amulet.get_hp(), amulet.get_att(), amulet.get_arm());
	break;
    default:
	break;
	}
}


void inventory()
{
	pun = 1; kur[0] = '>'; int b_sel = 0;
    do {
		system("cls");
		printf("����������\n\n%c������\n%c�����\n%c������\n%c�����\n\n", kur[0], kur[1], kur[2], kur[3]);
		b_sel = select_pun(4);
        inv_print(pun);
    } while (b_sel!=4);
    my_player();
}

void my_player()
{
	pun = 1; kur[0] = '>'; code = 0;
	do {
		system("cls");
		printf("��� �����:\nATT %d HP %d ARM %d\n\n%c����������\n%c����������\n%c� ����", p_at, p_hp, p_ar, kur[0], kur[1], kur[2]);
		code = select_pun(3);
	} while (code == 0);
	if (code == 1)
		inventory();
	else if (code == 2)
		inform();
	else
		menu();
}


