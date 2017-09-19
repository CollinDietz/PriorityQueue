#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <QueueList.h>

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
	else
	{
		typename QueueList<T>::link curr = this->head;
		typename QueueList<T>::link prev = NULL;
		//search until t has higher priority then curr
		while(!this->compare(t->item, curr->item) && curr != NULL)
		{
			//if current node has higer priority then t
			//move down the list
			prev = curr;
			curr = curr->next;
		}

		//element with lower priority has been found
		//insert t behind it

		//case: t has higher priority then head
		if(NULL == prev)
		{
			t->next = this->head;
			this->head = t;
		}
		//case: t has lowest priority in the list and is now tail
		else if(NULL == curr)
		{
			prev->next = t;
			t->next = NULL;
			this->tail = t;
		}
		//case t is somewhere in the middle of the list
		else
		{
			t->next = curr;
			prev->next = t;
		}
	}
}


#endif