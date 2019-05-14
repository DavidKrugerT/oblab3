#include "list.h"

void print_list(linked_list l);
bool is_sorted(linked_list l);
linked_list merge(linked_list list1, linked_list list2);

int main()
{
	//uppgift 1
	linked_list L1, L2, L3;

	for (int i = 0; i < 5; i++)
	{
		L1.push_back(L1.back() + rand() % 20);
		L2.push_back(L2.back() + rand() % 20);
		L3.push_back(L3.back() + rand() % 20);
	}
	L1.print();
	L2.print();
	////Uppgift 2 och 3 
	//if (L1.at(49) < L2.at(49))
	//{
	//	std::cout << "L2 has a larger element " << std::endl;
	//	L2.remove(49);
	//}
	//else
	//{
	//	std::cout << "L1 has a larger element " << std::endl;
	//	L1.remove(49);
	//}

	////Uppgift 4
	//L3 = L1;
	//L3.print();

	////uppgift 5
	//for (int i = 0; i < 50; i++)
	//{
	//	L3.pop_back();
	//	L3.push_front(L3.pop_back());
	//}

	//uppgift 7
	linked_list L4 = merge(L1, L2);
	std::cout << "L4" << std::endl;
	L4.print();

	//uppgift 8
	bool sorted = is_sorted(L4);
	if (sorted == true)
		std::cout << "this list is sorted. " << std::endl;
	else
		std::cout << "This list is not sorted. " << std::endl;

	system("PAUSE");
	return 0;
}

linked_list merge(linked_list list1, linked_list list2) 
{

	linked_list new_list;

	while (!list1.is_empty() && list2.is_empty())
		list1.front() > list2.front() ? new_list.push_back(list2.pop_front()) : new_list.push_back(list2.pop_front());
	while (!list1.is_empty()) new_list.push_back(list1.pop_front());
	while (!list2.is_empty()) new_list.push_back(list2.pop_front());
	return new_list;
}

bool is_sorted(linked_list l) {
	for (int i = 0; i < (l.size() - 1); i++)
		if (l.at(i) > l.at(i + 1))
			return false;
	return true;
	
}

//uppgift 6 
void print_list(linked_list l)
{
	l.print();
}
