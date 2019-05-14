#include "list.h"

linked_list::linked_list()
{
	//vid skapande av en ny lista ska head och tail vara nullptr
	head = nullptr;
	tail = nullptr;
}

linked_list::linked_list(const linked_list & src)
{
	head = nullptr;
	tail = nullptr;

	for (size_t i = 0; i < src.size(); i++)
	{
		push_back(src.at(i));
	}
}

linked_list::~linked_list()
{
	for (size_t i = 0; i < size(); i++)
		pop_front();
}

linked_list & linked_list::operator=(const linked_list & rhs)
{
	for (node_t * move = rhs.head; move->next; move = move->next) this->push_back(move->value);
	return *this;
}

linked_list & linked_list::operator +=(const linked_list & rhs)
{
	auto a = rhs.size();
	for (int i = 0; i < a; i++)
		push_back(rhs.at(i));
	return *this;
}

void linked_list::push_back(double value)
{
	node_t * new_tail = new node_t(value);
	if (is_empty()) head = tail = new_tail;
	else {
		tail->next = new_tail;
		new_tail->prev = tail;
		tail = new_tail;
	}
}

void linked_list::push_front(double value)
{
	node_t * new_head = new node_t(value);

	if (is_empty())	head = tail = new_head;
	else {
		head->prev = new_head;
		new_head->next = head;
		head = new_head;
	}
}

bool linked_list::is_empty() const
{
	return head ? false : true;
}

void linked_list::print() const {
	for (node_t *it = head; it; it = it->next) {
		std::cout << it->value << (it->next ? ", " : "\n");
	}
}

void linked_list::print_reverse() const {
	for (node_t *it = tail; it; it = it->prev) {
		std::cout << it->value << (it->prev ? ", " : "\n");
	}
}

double linked_list::front() const
{
	return head ? head->value : 0;
}

double linked_list::back() const {
	return tail ? tail->value : 0;
}

double linked_list::at(size_t pos) const
{
	node_t * current_pos = head;
	for (size_t i = 0; i < pos; i++)
		current_pos = current_pos->next;

	return current_pos->value;
}

size_t linked_list::size() const
{
	std::size_t size = 0;
	for (node_t * it = this->head; it != nullptr; size++)
		it = it->next;
	return size;
}

double linked_list::pop_front() {
	double value = head->value;
	if (size() == 1)
	{
		delete head;
		head = nullptr;
	}
	else
	{
		node_t * temp = head->next;
		temp->prev = nullptr;
		delete head;
		head = temp;
	}
	return value;
}

double linked_list::pop_back() {
	double value = tail->value;
	if (size() == 1)
	{
		delete tail; //vi tar bort det som är i tail "pekaren" sen sätter vi tail till nullptr
		tail = nullptr;
	}
	else
	{
		node_t * temp = tail->prev;
		temp->next = nullptr;
		delete tail;
		tail = temp;
	}
	return value;
}

void linked_list::remove(size_t pos)
{
	node_t * del_node = head;
	for (size_t i = 0; i < pos; i++)
	{
		del_node = del_node->next;
	}
	if (!del_node->prev)
		pop_front();
	else if (!del_node->next)
		pop_back();
	else
	{
		del_node->next->prev = del_node->prev;
		del_node->prev->next = del_node->next;
		delete del_node;
	}
}

void linked_list::insert(double value, size_t pos)
{
	node_t * ins_pos = head;
	for (size_t i = 0; i < pos; i++) ins_pos = ins_pos->next;
	if (!ins_pos->prev) push_front(value);
	else if (!ins_pos->next) push_back(value);
	else
	{
		node_t * ins_node = new node_t(value, ins_pos, ins_pos->prev);
		ins_pos->prev->next = ins_node;
		ins_pos->prev = ins_node;
	}
}

linked_list::node_t::node_t(double value, node_t * next, node_t * prev) : prev(prev), next(next), value(value)
{

}