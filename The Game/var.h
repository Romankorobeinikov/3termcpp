using namespace std;

int gold = 10, p_at = 7, p_hp = 10, p_ar = 5, p_lv = 1, p_xp = 0, lvl_loc, tren = 1, victory, enemy, enemy_cof, loc_score, all_gold, bodies, ydar, promah, win, lose,
    death, lvl [50], tren_pr [100], att_id = 0, arm_id = 0, item_id = 0, pun, code, apl_at[5], apl_hp[5], apl_ar[5], aen_n[5], a_stake, pl_table[5], pl_plc_table[5],
    pl_scores[5], arena_all_pl, apl_kill[5], a_rew_xp, price_itm, itm_id;
char btn, kur[] = "                    ";
string p_name;

string shop_item [16] = {"Пусто", "Ржавая кастрюля", "Старая кольчуга", "Железные латы", "Золотые доспехи", "Алмазная броня", "Кухонный нож", "Ржавый топор", "Короткий меч",
    "Булава", "Меч паладина", "Чеснок на нитке", "Святая вода", "Золотой крестик", "Кулон силы", "Кольцо всевластия"};
int arm_b [16] = {0, 3, 15, 28, 40, 70, 0, 0, 0, 0, 0, 1, 5, 10, 20, 35};
int att_b [16] = {0, 0, 0, 0, 0, 0, 12, 25, 32, 43, 60, 0, 0, 5, 30, 45};
int hp_b [16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 10, 20, 25, 40};
int price [16] = {0, 12, 60, 112, 160, 280, 48, 100, 128, 172, 240, 15, 75, 175, 375, 600};
bool proid = false, info = false, arena_lock = true, a_stake_b = false, autosave = false;

Players_item armor, weapon, amulet;
