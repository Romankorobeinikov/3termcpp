#include <iostream>
#include <string>


struct Cells
{
	std::string value;
	Cells* next_ptr;
};

class List
{
public:
	int length;
	Cells* first;
	Cells* last;
	List()
	{
		length = 0;
		first = nullptr;
		last = nullptr;
	}
};

List append(List list, std::string value)
{
	Cells* cell = new Cells;
	(*cell).value = value;
	(*cell).next_ptr = nullptr;
	if (list.length == 0)
	{
		list.first = cell;
	}
	else
	{
		if (list.length == 1)
		{
			list.last = list.first;
			(*list.first).next_ptr = cell;
		}
		(*list.last).next_ptr = cell;
		list.last = cell;
	}
	list.length += 1;
	return list;
}

void print_list(List list)
{
	if (list.length == 0)
		std::cout << "Empty" << std::endl;
	else
	{
		Cells last_cell;
		last_cell = *list.first;
		while (last_cell.next_ptr != nullptr)
		{
			std::cout << last_cell.value << " ";
			last_cell = *last_cell.next_ptr;
		}
		std::cout << last_cell.value << std::endl;
	}
}

List remove(List list, std::string a)
{
	List new_list;
	Cells* cell, * previous_cell;
	int warning;
	warning = 0;
	if (list.length >= 2)
	{
		if ((*list.first).value == a)
		{
			new_list.first = (*list.first).next_ptr;
			new_list.length = list.length - 1;
			new_list.last = list.last;
			return new_list;
		}
		else
		{
			cell = (*list.first).next_ptr;
			previous_cell = list.first;
			new_list.first = list.first;
			new_list.length = list.length - 1;
			new_list.last = list.last;
			while ((*cell).value != a)
			{
				if ((*cell).next_ptr != nullptr)
				{
					previous_cell = cell;
					cell = (*cell).next_ptr;
				}
				else
				{
					std::cout << "Can't find this" << std::endl;
					warning = 1;
					break;
				}
			}
			if (warning == 0)
			{
				(*previous_cell).next_ptr = (*cell).next_ptr;
				if ((*cell).next_ptr == nullptr)
					new_list.last = previous_cell;
				return new_list;
			}
			else
				return list;
		}
	}
	else
	{
		if (list.length == 0)
			return list;
		else
		{
			if ((*list.first).value == a)
				return List();
			else
			{
				std::cout << "Can't find this" << std::endl;
				return list;
			}
		}
	}
}

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

class Hash_table
{
public:
	List* array;
	int length;
	int memory;
	Hash_table(int size)
	{
		int i;
		length = 0;
		memory = size;
		array = new List[memory];
		for (i = 0; i < memory; i++)
			array[i] = List();
	}
	void print()
	{
		int i;
		for (i = 0; i < memory; i++)
			print_list(array[i]);
	}
};

Hash_table hash_add(Hash_table table, std::string str)
{
	if (static_cast<double>(table.length) / table.memory >= 0.5)
	{
		Cells* cell;
		int i;
		Hash_table privious_table = table;
		table = Hash_table(privious_table.memory * 2);
		for (i = 0; i < privious_table.memory; i++)
		{
			cell = privious_table.array[i].first;
			while (cell != nullptr)
			{
				table = hash_add(table, cell->value);
				cell = cell->next_ptr;
			}
		}
	}
	int hash = hash_function(47, str, table.memory);
	table.array[hash] = append(table.array[hash], str);
	table.length++;
	return table;
}

int index(Hash_table table, std::string str)
{
	int i = 1;
	int hash = hash_function(47, str, table.memory);
	Cells* cell = table.array[hash].first;
	while ((cell != nullptr) && (cell->value != str))
		cell = cell->next_ptr;
	if (cell == nullptr)
		return -1;
	else
		return hash;
}

void hash_find(Hash_table table, std::string str)
{
	if (index(table, str) == -1)
		std::cout << "Can't find this" << std::endl;
	else
		std::cout << str << "Placenumber is" << std::endl;
}

Hash_table hash_remove(Hash_table table, std::string str)
{
	if (index(table, str) == -1)
		std::cout << "Can't find this";
	else
		table.array[hash_function(47, str, table.memory)] = remove(table.array[hash_function(47, str, table.memory)], str);
	return table;
}

int main()
{
	return 0;
}
