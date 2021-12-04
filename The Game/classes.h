using namespace std;

class Players_item
{
private:
	int arm, att, hp;
	string name;
public:
	void set_param(int armb, int attb, int hpb, string nm)
	{
		arm = armb;
		att = attb;
		hp = hpb;
		name = nm;
	}
	int get_arm()
	{
		return arm;
	}
	int get_att()
	{
		return att;
	}
	int get_hp()
	{
		return hp;
	}
	string get_name()
	{
		return name;
	}
};
