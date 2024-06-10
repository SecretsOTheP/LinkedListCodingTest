#pragma once
#include <iostream>
#include "util.h"

template<typename T>
struct LinkedListNode {
	// This is the data we're containing of type 't'.
	T m_data;
	// In a linked list, we need to have knowledge of what's ahead and forward. These CAN be null if there's nothing ahead of us or behind us.
	LinkedListNode* m_next;
	LinkedListNode* m_prev;

	LinkedListNode(const T& data) : m_data(data), m_next(nullptr), m_prev(nullptr) {}
};

template<typename T>
class DoublyLinkedList {
private:
	//Having knowledge of the head / tail is important for starting traversal backwards or forwards.
	LinkedListNode<T>* m_head;
	LinkedListNode<T>* m_tail;
	size_t m_size;

public:

	DoublyLinkedList() : m_head(nullptr), m_tail(nullptr), m_size(0) {}

	//Insert a new node into this LinkedList at the tail position.
	void InsertNode(const T& data) {
		LinkedListNode<T>* pNewNode = new LinkedListNode<T>(data);
		if (m_head == nullptr) {
			m_head = m_tail = pNewNode;
		}
		else {
			m_tail->m_next = pNewNode;
			pNewNode->m_prev = m_tail;
			m_tail = pNewNode;
		}
		m_size++;
	}

	// Append an element to the head position, as opposed to the tail position.
	void AppendNode(const T& data) {
		LinkedListNode<T>* pNewNode = new LinkedListNode<T>(data);
		if (m_head == nullptr) {
			m_head = m_tail = pNewNode;
		}
		else {
			pNewNode->m_next = m_head;
			m_head->m_prev = pNewNode;
			m_head = pNewNode;
		}
		m_size++;
	}

	//Remove a node by seeing if it matches 'data'.
	void RemoveNode(const T& data) {
		LinkedListNode<T>* pCurrentNode = m_head;
		//If we don't have an element, we need to exit out of this function anyway. Nothing to do!
		while (pCurrentNode != nullptr) {
			//Though, if we do.. check to see if the head element is equal to the data we're trying to remove.
			if (pCurrentNode->m_data == data) {

				//Check the current node's position.
				if (pCurrentNode == m_head) {
					m_head = m_head->m_next;
					if (m_head != nullptr)
						m_head->m_prev = nullptr;
					else
						m_tail = nullptr;
				}
				else if (pCurrentNode == m_tail) {
					m_tail = m_tail->m_prev;
					m_tail->m_next = nullptr;
				}
				else {
					pCurrentNode->m_prev->m_next = pCurrentNode->m_next;
					pCurrentNode->m_next->m_prev = pCurrentNode->m_prev;
				}

				//We've found the data to remove! And we've fixed the list. Remove it and return after decrementing the size.
				SAFE_DELETE(pCurrentNode);
				m_size--;
				return;
			}
			pCurrentNode = pCurrentNode->m_next;
		}
	}

	T PopNode() {
		if (m_head == nullptr) {
			return nullptr;
		}

		LinkedListNode<T>* pCurrentNode = m_head;
		T data = pCurrentNode->m_data;

		m_head = m_head->m_next;
		if (m_head != nullptr) {
			m_head->m_prev = nullptr;
		}
		else {
			m_tail = nullptr;
		}

		SAFE_DELETE(pCurrentNode);
		m_size--;

		return data;
	}

	// Get the total size of the linked list.
	inline int GetSize() const {
		return m_size;
	}

	//Get the head of the LinkedList. This is so we can iterate from specific positions to begin (ie; forward/back)
	LinkedListNode<T>* GetHead() const {
		return m_head;
	}

	//Get the tail of the LinkedList. his is so we can iterate from specific positions to begin (ie; forward/back)
	LinkedListNode<T>* GetTail() const {
		return m_tail;
	}

	// Implement a dtor to free memory contained in the LinkedList.
	~DoublyLinkedList() {
		LinkedListNode<T>* pCurrentNode = m_head;
		while (pCurrentNode != nullptr) {
			LinkedListNode<T>* pTempNode = pCurrentNode;
			pCurrentNode = pCurrentNode->m_next;
			SAFE_DELETE(pTempNode);
		}
	}
};