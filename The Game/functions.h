using namespace std;

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
	printf("¬ведите ваш ник: ");
	cin>>::p_name;
}
