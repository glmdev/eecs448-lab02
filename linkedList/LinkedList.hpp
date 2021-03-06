/**
*	@author Garrett Mills
*	@date 2020-09-05
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList() 
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	return(m_size);
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;

	if ( m_front == nullptr ) {
		return false;
	}

	while(true) {
		if ( temp->getValue() == value ) {
			return true;
		}

		if ( temp->getNext() == nullptr ) {
			return false;
		} else {
			temp = temp->getNext();
		}
	}
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);	
	
}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);	
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );		
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = nullptr;
	Node<T>* secondToLast = nullptr;

	// if no elements, no delete
	if ( m_front == nullptr ) {
		return false;
	}

	// if we delete the head of the list, just set m_front
	if ( m_front->getNext() == nullptr ) {
		delete m_front;
		m_front = nullptr;
		m_size -= 1;
		return true;
	}

	secondToLast = m_front;
	lastNode = m_front->getNext();

	while(true) {
		if ( lastNode->getNext() == nullptr ) {
			// this really is the last node
			delete lastNode;
			m_size -= 1;
			secondToLast->setNext(nullptr);
			return true;
		} else {
			// not the last node. Loop onward, faithful steed.
			secondToLast = lastNode;
			lastNode = lastNode->getNext();
		}
	}

	// This shouldn't really be possible, but just in case.
	return false;
}	

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
