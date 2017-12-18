#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "QueueList_Modified.h"

template <typename T>
class PriorityQueue: public QueueList<T>
{
	public:
		//contructs a priority queue such that any elements a and b
		//are in order such that if compare(a,b) == true
		//then a is in front of b in the queue
		PriorityQueue(bool(*compare)(T, T));

		~PriorityQueue(){} // destructor

		// push an item to the queue.
    	void push (const T i);

    	typedef bool (*CompareFunc)(T,T);


	private:
		CompareFunc compare;
		//binary search in the list for the node that has the closest priority less than the given item
		//i.e. the the item to the left of the given when inserted into the list 
		QueueList<T>::link binSearch(QueueList<T>::link i, QueueList<T>::link i, QueueList<T>::link i); 

		//puts the link item input st inListLeft points to it next, and input points to whatever inListLeft pointed to
		void insert(QueueList<T>::link input, QueueList<T>::link inListLeft); 
};

template <typename T>
PriorityQueue<T>::PriorityQueue(bool(*compare)(T,T))
{
	this->compare = compare;
}

template <typename T>	
void PriorityQueue<T>::push(const T i)
{
	//create a node for the new object
	typename QueueList<T>::link t = (typename QueueList<T>::link) new (typename QueueList<T>::node);
	t->item = i;
	t->next = NULL;

	//empty list case
	if (NULL == this->head)
	{	
		t->next = NULL;
		this->head = t;
		this->tail = t;
	}
	else //find by bin search
	{
		QueueList<T>::link leftOf = binSearch(t, 0, this->count()-1);

		//element with lower priority has been found
		//insert t behind it
		insert(t, leftOf);

	}
	this->size++;
}

template<T>
void PriorityQueue<T>::insert(QueueList<T>::link input, QueueList<T>::link inListLeft)
{
			//case: t has higher priority then head
		if(NULL == inListLeft)
		{
			t->next = this->head;
			this->head = t;
		}
		//case t is not the head
		else
		{
			t->next = inListLeft->next;
			inListLeft->next = t;
		}


}


#endif