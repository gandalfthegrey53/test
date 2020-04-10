#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

template <class T>
class Circularlist;

template <class T>
class ChainNode {
	friend Circularlist<T>;
	public:
		ChainNode(T dt, ChainNode<T>* lk = NULL):link(lk) {
			data = dt;
		}
	private:
		T data;
		ChainNode<T>* link;
};

template <class T>
class Circularlist {
	public:
	Circularlist();
	bool IsEmpty() const;
	void Insert(const T& dt);
	void InsertBack(const T& dt);
	void Delete(const T& dt);
	void Reverse();
	void First() const;
	void Last() const;
	void Show() const;
	private:
		ChainNode<T>* first;
		ChainNode<T>* last;
};

template <class T>
Circularlist<T>::Circularlist()
{
	first = NULL;
	last = NULL;
}

template <class T>
bool Circularlist<T>::IsEmpty() const
{
	return first == NULL;
}

template <class T>
void Circularlist<T>::Insert(const T& dt)
{
	ChainNode<T> *node = new ChainNode<T>(dt);
	if (IsEmpty()) {
		first = last = node;
		node->link = node;
		return;
	}
	node->link = first;
	last->link = node;
	first = node;
}

template <class T>
void Circularlist<T>::InsertBack(const T& dt)
{
	ChainNode<T> *node = new ChainNode<T>(dt);
	if (IsEmpty()) {
		first = node;
		last = node;
		node->link = node;
		return;
	}
	node->link = first;
	last->link = node;
	last = node;
}

template <class T>
void Circularlist<T>::Delete(const T& dt)
{
	if (IsEmpty()) {
		std::cout << "It's empty!" << std::endl;
		return;
	} else if (first->link == first) {
		if (dt == first->data) {
			delete first;
			first = last = NULL;
		}
		return;
	}
	ChainNode<T> *node, **temp, *ls;
	temp = &first;
	node = (*temp);
	while (node->link != first) {
		if (node->data == dt) {
			(*temp) = node->link;
			last->link = first;
			delete node;
			return;
		}
		temp = &(node->link);
		node = node->link;
		if (node->link == last) {
			ls = node;
		}
	}
	if (node->data == dt) {
			(*temp) = node->link;
			delete node;
			last = ls;
			return;
	}
}

template <class T>
void Circularlist<T>::Reverse()
{
	if (IsEmpty() || first == last) {
		return;
	}
	ChainNode<T> *front, *middle, *rear = last;
	front = first->link;
	middle = first;
	while (front != first) {
		middle->link = rear;
		rear = middle;
		middle = front;
		front = front->link;
	}
	middle->link = rear;
	last = first;
	first = middle;
}

template <class T>
void Circularlist<T>::First() const
{
	if (IsEmpty()) {
		std::cout << "It's empty!" << std::endl;
		return;
	}
	std::cout << first->data << std::endl;
}

template <class T>
void Circularlist<T>::Last() const
{
	if (IsEmpty()) {
		std::cout << "It's empty!" << std::endl;
		return;
	}
	std::cout << last->data << std::endl;
}

template <class T>
void Circularlist<T>::Show() const
{
	if (IsEmpty()) {
		std::cout << "It's empty!" << std::endl;
		return;
	}
	ChainNode<T> *node = first;
	while(node->link != first) {
		std::cout << node->data << ' ';
		node = node->link;
	}
	std::cout << node->data <<' ';
	std::cout << std::endl;
}
#endif
