#ifndef CHAIN_H
#define CHAIN_H

template <class T>
class Chain;

template <class T>
class ChainNode {
	friend Chain<T>;
	public:
		ChainNode(T dt, ChainNode<T>* lk = NULL):link(lk) {
			data = dt;
		}
	private:
		T data;
		ChainNode<T>* link;
};

template <class T>
class Chain {
	public:
	Chain();
	bool IsEmpty() const;
	void Insert(const T& dt);
	void InsertBack(const T& dt);
	void Delete(const T& dt);
	void Reverse();
	void Show() const;
	class ChainIterator;
	ChainIterator begin() const {return ChainIterator(first);}
	ChainIterator end() const {return ChainIterator(NULL);}
	private:
		ChainNode<T>* first;
		ChainNode<T>* last;
};

template <class T>
class Chain<T>::ChainIterator {
	public:
		ChainIterator(ChainNode<T>* startNode = NULL) {
			current = startNode;
		}
		T& operator*() const {return current->data;}
		T* operator->() const {return &current->data;}
		ChainIterator& operator++() {
			current = current->link;
			return *this;
		}
		ChainIterator operator++(int) {
			ChainIterator old = *this;
			current = current->link;
			return old;
		}
		bool operator!=(const ChainIterator right) const {
			return current != right.current;
		}
		bool operator==(const ChainIterator right) const {
			return current == right.current;
		}
	private:
		ChainNode<T>* current;
};

template <class T>
Chain<T>::Chain()
{
	first = NULL;
	last = NULL;
}

template <class T>
bool Chain<T>::IsEmpty() const
{
	return first == NULL;
}

template <class T>
void Chain<T>::Insert(const T& dt)
{
	ChainNode<T> *node = new ChainNode<T>(dt);
	if (IsEmpty()) {
		last = node;
	}
	node->link = first;
	first = node;
}

template <class T>
void Chain<T>::InsertBack(const T& dt)
{
	ChainNode<T> *node = new ChainNode<T>(dt);
	if (IsEmpty()) {
		node->link = last;
		first = node;
		last = node;
		return;
	}
	last->link = node;
	last = node;
}

template <class T>
void Chain<T>::Delete(const T& dt)
{
	ChainNode<T> *node, **temp, *ls;
	temp = &first;
	node = (*temp);
	while (node) {
		if (node->data == dt) {
			if (node == last) {
				last = ls;
			}
			(*temp) = node->link;
			delete node;
			return;
		}
		temp = &(node->link);
		if (node->link == last) {
			ls = node;
		}
		node = node->link;
	}
}

template <class T>
void Chain<T>::Reverse()
{
	if (IsEmpty() || first == last) {
		return;
	}
	ChainNode<T> *front, *middle, *rear = NULL;
	front = first->link;
	middle = first;
	while (front != NULL) {
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
void Chain<T>::Show() const
{
	if (IsEmpty()) {
		std::cout << "It's empty!" << std::endl;
		return;
	}
	ChainNode<T> *node = first;
	while(node) {
		std::cout << node->data << ' ';
		node = node->link;
	}
	std::cout << std::endl;
}
#endif
