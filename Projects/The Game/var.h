using namespace std;

string p_name, apl_name[5], apl_st;
string location [4] = {"??????????", "???????????", "Ҹ???? ???", "??????? ?????"};
string shop_item [16] = {"?????", "?????? ????????", "?????? ????????", "???????? ????", "??????? ???????", "???????? ?????", "???????? ???", "?????? ?????", "???????? ???",
    "??????", "??? ????????", "?????? ?? ?????", "?????? ????", "??????? ???????", "????? ????", "?????? ??????????"};
int arm_b [16] = {0, 3, 15, 28, 40, 70, 0, 0, 0, 0, 0, 1, 5, 10, 20, 35};
int att_b [16] = {0, 0, 0, 0, 0, 0, 12, 25, 32, 43, 60, 0, 0, 5, 30, 45};
int hp_b [16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 10, 20, 25, 40};
int price [16] = {0, 12, 60, 112, 160, 280, 48, 100, 128, 172, 240, 15, 75, 175, 375, 600};
string enemy_st [18] = {"?????", "?????????? ?????", "????", "?????????? ????", "?????-??????", "?????-????", "?????", "????", "????-?????", "??????", "??????-???????",
    "??????-?????", "??????-???????", "??????", "?????", "?????????? ??????", "??????", "???????? ????????"};
string pl_names [26] = {"??????", "?????", "????", "?????", "??????", "??????", "?????", "?????", "????", "??????", "??????", "??????", "??????", "??????", "??????", "?????",
    "????", "??????", "?????", "??????", "?????", "??????", "?????", "?????", "??????", "?????"};
int gold = 10, p_at = 7, p_hp = 10, p_ar = 5, p_lv = 1, p_xp = 0, lvl_loc, tren = 1, victory, enemy, enemy_cof, loc_score, all_gold, bodies, ydar, promah, win, lose,
    death, lvl [50], tren_pr [100], att_id = 0, arm_id = 0, item_id = 0, pun, code, apl_at[5], apl_hp[5], apl_ar[5], aen_n[5], a_stake, pl_table[5], pl_plc_table[5],
    pl_scores[5], arena_all_pl, apl_kill[5], a_rew_xp, price_itm, itm_id, task, difficulty = 0, anum, bnum, cnum, result, ttime, i, indicator, ans = 0,ans1=0;
int sen_hp [53] = {8,10,12,14,16,25,30,40,42,44,70,50,54,57,65,69,72,100,80,82,85,130,120,125,130,135,140,143,146,120,122,190,220,224,226,230,260,265,270,280,300,305,309,
312,330,340,350,360,370,380,390,400,500};
int sen_at [53] = {10,12,14,16,20,30,35,37,40,42,66,67,72,75,82,87,92,110,90,93,96,130,132,135,140,143,150,157,160,170,180,205,215,219,223,227,250,255,260,270,320,327,334,
342,360,367,375,382,396,404,415,425,570};
int sen_ar [53] = {6,8,10,12,15,30,35,28,30,32,60,55,57,60,73,76,80,90,80,85,90,130,140,143,148,152,140,143,147,160,165,190,200,205,210,215,230,233,238,245,290,297,302,308,
300,307,314,324,330,339,344,350,600};
int en_score [17] = {5,7,10,11,14,17,18,21,22,26,29,31,32,36,40,44,52};
int  en_loc_score [3] = {4,7,13};
bool proid = false, info = false, arena_lock = true, a_stake_b = false, autosave = false;
char btn, kur[] = "                    ";

Creature monster, player;
Players_item armor, weapon, amulet;
