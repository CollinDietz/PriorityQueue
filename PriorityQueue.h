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

		//bin search the whole queue for a term t st t has higher priority than query 
		//and query has higher priorty that t->next
		//ie find the element that points to query in the list 
		QueueList<T>::link initBinSearch(QueueList<T>::link query);

		//binary search in the list for the node that has the closest priority less than the given item
		//i.e. the the item to the left of the given when inserted into the list 
		QueueList<T>::link binSearch(QueueList<T>::link query, QueueList<T>::link l, QueueList<T>::link r, int leftIndex, int rightIndex); 

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
		QueueList<T>::link leftOf = initbinSearch(t);

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

template<T>
void PriorityQueue<T>::initBinSearch(QueueList<T>::link	query)
{
	//check header and tail cases
	if(compare(query, this->head))
	{
		//query has higher priority then head, return NULL since nothing points to query
		return NULL;
	}
	else if(compare(this->tail, query))
	{
		//query has the lowest priority in the list, tail points to it
		return this>tail;
	}
	else
	{
		//else search the rest of the list
		binSearch(query, this->head, this->tail, 0, this->count()-1);
	}
}

template<T>
void PriorityQueue<T>::binSearch(QueueList<T>::link query, QueueList<T>::link l, QueueList<T>::link r, int leftIndex, int rightIndex)
{
	//if we have closed the search to one item it is the result
	if(0 == rightIndex - leftIndex)
	{
		return l;
	}
	else
	{
		//start looking from the left of the given term
		QueueList<T>::link term = l;
		int mid = (rightIndex + leftIndex) / 2; //find the mid point of the range
		for(int i = 0; i < mid - leftIndex; i++) //move term to it
		{	
			term = term->next;
		}

		//compare to term and term next
		//term should be higher priority then query
		if(!this->compare(term, query))
		{
			//if not query is higher priority and we need to look left on the list
			binSearch(query, l, term, leftIndex, mid);
		}
		//query should also be higher priorty than the next item in the list
		else if(!this->compare(query, term->next))
		{
			//if not we need to look to the right
			binSearch(query, term, r, mid, rightIndex);
		}
		else
		{
			//if both conditions met we have found the term that goes left of the search term
			return term;
		}

	}
}


#endif