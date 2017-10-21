
#include "QueueLinked.h"

template <typename DataType>
QueueLinked<DataType>::QueueNode::QueueNode(const DataType& nodeData, QueueNode* nextPtr)
{
	//cant figure out constructor
}

template <typename DataType>
QueueLinked<DataType>::QueueLinked(int maxNumber = Queue<DataType>::MAX_QUEUE_SIZE)
{
}

template <typename DataType>
QueueLinked<DataType>::QueueLinked(const QueueLinked& other)
{
}

template <typename DataType>
QueueLinked<DataType>& QueueLinked<DataType>::operator=(const QueueLinked& other)
{
	dataItem = other->dataItem;
	next = other->next;
}

template <typename DataType>
QueueLinked<DataType>::~QueueLinked()
{
}

template <typename DataType>
void QueueLinked<DataType>::enqueue(const DataType& newDataItem) throw (logic_error)
{
	if (isEmpty()){
		front->dataItem = newDataItem;
		back = front;
	}
	else{
		back->next = new QueueNode(newDataItem, NULL);
		back = back->next;
	}
}

template <typename DataType>
DataType QueueLinked<DataType>::dequeue() throw (logic_error)
{
	if (isEmpty())
		throw logic_error("Queue is empty.");
	else{
		QueueNode* temp = front;
		DataType val = temp->dataItem;
		front = front->next;
		temp->next = NULL;
		delete temp;
		return val;
	}
}

template <typename DataType>
void QueueLinked<DataType>::clear()
{
	while (!(isEmpty())){
		dequeue();
	}
}

template <typename DataType>
bool QueueLinked<DataType>::isEmpty() const
{
	if (front->next == NULL){
		return true;
	}
	return false;
}

template <typename DataType>
bool QueueLinked<DataType>::isFull() const
{
	return false;
}

template <typename DataType>
void QueueLinked<DataType>::putFront(const DataType& newDataItem) throw (logic_error)
{
	if (isEmpty())
		throw logic_error("Queue is empty.");
	else{
		QueueNode* temp;
		temp->dataItem = newDataItem;
		temp->next = front;
		front = temp;
		delete temp;
	}
}

template <typename DataType>
DataType QueueLinked<DataType>::getRear() throw (logic_error)
{
	QueueNode* temp;
	temp = front;

	while (temp->next != back){
		temp = temp->next;
	}
	back = temp;
	back->next;
	delete temp;
}

template <typename DataType>
int QueueLinked<DataType>::getLength() const
{
	QueueNode* temp = front;
	int count = 1;

	while (temp->next != back){
		count++;
		temp = temp->next;
	}

	return count;
}

template <typename DataType>
void QueueLinked<DataType>::showStructure() const
{
    QueueNode *p;   // Iterates through the queue

    if ( isEmpty() )
	cout << "Empty queue" << endl;
    else
    {
	cout << "Front\t";
	for ( p = front ; p != 0 ; p = p->next )
	{
	    if( p == front ) 
	    {
		cout << '[' << p->dataItem << "] ";
	    }
	    else
	    {
		cout << p->dataItem << " ";
	    }
	}
	cout << "\trear" << endl;
    }
}