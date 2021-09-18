#include <iostream>
#include <string>

int hash_function(int prime, std::string str, int table_len)
{
	int i, hash;
	hash = 0;
	for (i = 0; i < str.size(); i++)
	{
		hash = (prime * hash + str[i] + 3) % table_len;
	}
	if (hash % 2 == 0)
		hash++;
	return hash;
}


class Cell
{
public:
	std::string str;
	int status;
	Cell()
	{
		str = "NILL";
		status = 1;
	}
};


class Array
{
public:
	int length;
	int memory;
	Cell* data;
	Array(int arraysize, int lenght)
	{
		int i;
		length = 0;
		memory = arraysize;
		Cell* new_array = new Cell[memory];
		data = new_array;
	}
};


class Hash_table
{
public:
	Array array{ 8, 0 };
	Hash_table()
	{
		Array new_array{ 8, 0 };
		array = new_array;
	}

	Array remove(std::string str)
	{
		if (index(str) == -1)
			std::cout << "Can't find this" << std::endl;
		else
		{
			array.data[index(str)].status = 0;
			array.length--;
		}
		return array;
	}

	void print()
	{
		int i;
		for (i = 0; i < array.memory; i++)
		{
			if (array.data[i].status == 1)
				std::cout << array.data[i].str << std::endl;
			else
				std::cout << "NILL" << std::endl;
		}
	}

	Array add(std::string str)
	{
		if (array.length > array.memory * 3 / 4)
		{
			int i;
			Array new_array{ array.memory * 2 , array.memory };
			Array privious_array = array;
			array = new_array;
			for (i = 0; i < privious_array.memory; i++)
				if ((privious_array.data[i].status == 1) && (privious_array.data[i].str != "NILL"))
					add(privious_array.data[i].str);
			add(str);
		}
		else
		{
			int step, k;
			k = 0;
			step = hash_function(29, str, array.memory);
			if (step == 0)
				step++;
			while ((array.data[(hash_function(47, str, array.memory) + k * step) % array.memory].str != "NILL") &&
          (array.data[(hash_function(47, str, array.memory) + k * step) % array.memory].status == 1))
				k++;
			array.data[(hash_function(47, str, array.memory) + k * step) % array.memory].str = str;
			array.length++;
		}
		return array;
	}

	int index(std::string str)
	{
		int hash1, hash2, k;
		hash1 = hash_function(47, str, array.memory);
		hash2 = hash_function(29, str, array.memory);
		k = 0;
		while ((array.data[(hash1 + k * hash2) % array.memory].str != str) && (array.data[(hash1 + k * hash2) % array.memory].str != "NILL"))
			k++;
		if (array.data[(hash1 + k * hash2) % array.memory].str == str)
		{
			if (array.data[(hash1 + k * hash2) % array.memory].status == 1)
				return (hash1 + k * hash2) % array.memory;
		}
		else
			return -1;
	}

	void find(std::string str)
	{
		if (index(str) == -1)
			std::cout << "Can't find this" << std::endl;
		else
			std::cout << "Placenumber is " << index(str) + 1 << std::endl;
	}

};


int main()
{

	return 0;
}
