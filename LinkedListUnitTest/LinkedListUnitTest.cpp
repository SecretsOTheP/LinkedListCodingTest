#include "pch.h"
#include "CppUnitTest.h"
#include "linked_list.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedListUnitTest
{
	TEST_CLASS(LinkedListUnitTest)
	{
	public:

		// Per the engineering test requirement, we need to be able to insert nodes into a doubly linked list and move forward. This tests for the string matching that order.
		TEST_METHOD(TestMoveForward)
		{
			DoublyLinkedList<int> list;
			list.InsertNode(5);
			list.InsertNode(10);
			list.InsertNode(15);
			list.InsertNode(20);

			std::stringstream strForwardStream;
			LinkedListNode<int>* pCurrentNode = list.GetHead();
			while (pCurrentNode != nullptr) {
				strForwardStream << pCurrentNode->m_data << " ";
				pCurrentNode = pCurrentNode->m_next;
			}

			Assert::AreEqual(std::string("5 10 15 20 "), strForwardStream.str());
		}

		// Per the engineering test requirement, we need to be able to insert nodes into a doubly linked list and move backward. This tests for the string matching that order.
		TEST_METHOD(TestMoveBackward)
		{
			DoublyLinkedList<int> list;
			list.InsertNode(5);
			list.InsertNode(10);
			list.InsertNode(15);
			list.InsertNode(20);

			std::stringstream strBackwardStream;
			LinkedListNode<int>* pCurrentNode = list.GetTail();
			while (pCurrentNode != nullptr) {
				strBackwardStream << pCurrentNode->m_data << " ";
				pCurrentNode = pCurrentNode->m_prev;
			}

			Assert::AreEqual(std::string("20 15 10 5 "), strBackwardStream.str());
		}

		// Per the engineering test requirement, we need to be able to insert nodes into a doubly linked list and move forward through the list. This test specifically handles the 'Remove Node' case while also traversing foward through the doubly linked list.
		TEST_METHOD(TestRemoveNodeForwards)
		{
			DoublyLinkedList<int> list;
			list.InsertNode(5);
			list.InsertNode(10);
			list.InsertNode(15);
			list.InsertNode(20);

			//This time, let's remove 10.
			list.RemoveNode(10);

			std::stringstream strForwardStream;
			LinkedListNode<int>* pCurrentNode = list.GetHead();
			while (pCurrentNode != nullptr) {
				strForwardStream << pCurrentNode->m_data << " ";
				pCurrentNode = pCurrentNode->m_next;
			}

			Assert::AreEqual(std::string("5 15 20 "), strForwardStream.str());
		}

		// Per the engineering test requirement, we need to be able to insert nodes into a doubly linked list and move backward. This test specifically handles the 'Remove Node' case while also traversing backwards through the doubly linked list.
		TEST_METHOD(TestRemoveNodeBackwards)
		{
			DoublyLinkedList<int> list;
			list.InsertNode(5);
			list.InsertNode(10);
			list.InsertNode(15);
			list.InsertNode(20);

			//This time, let's remove 15.
			list.RemoveNode(15);

			std::stringstream strBackwardStream;
			LinkedListNode<int>* pCurrentNode = list.GetTail();
			while (pCurrentNode != nullptr) {
				strBackwardStream << pCurrentNode->m_data << " ";
				pCurrentNode = pCurrentNode->m_prev;
			}

			Assert::AreEqual(std::string("20 10 5 "), strBackwardStream.str());
		}

		// Per the engineering test requirement, we need to be able to insert nodes into a doubly linked list and move forwards. While appending a node wasn't explicitly needed, I figured it would be great to include this as an example. We have Insert Node and Append Node which insert at opposite ends of the list at head or tail.
		TEST_METHOD(TestAppendElementMoveForwards)
		{
			DoublyLinkedList<int> list;
			list.InsertNode(5);
			list.InsertNode(10);
			list.InsertNode(15);
			list.AppendNode(20);


			std::stringstream strForwardStream;
			LinkedListNode<int>* pCurrentNode = list.GetHead();
			while (pCurrentNode != nullptr) {
				strForwardStream << pCurrentNode->m_data << " ";
				pCurrentNode = pCurrentNode->m_next;
			}

			Assert::AreEqual(std::string("20 5 10 15 "), strForwardStream.str());
		}

		// Per the engineering test requirement, we need to be able to insert nodes into a doubly linked list and move backwards. While appending a node wasn't explicitly needed, I figured it would be great to include this as an example. We have Insert Node and Append Node which insert at opposite ends of the list at head or tail.
		TEST_METHOD(TestAppendElementMoveBackwards)
		{
			DoublyLinkedList<int> list;
			list.InsertNode(5);
			list.InsertNode(10);
			list.InsertNode(15);
			list.AppendNode(20);


			std::stringstream strBackwardsStream;
			LinkedListNode<int>* pCurrentNode = list.GetTail();
			while (pCurrentNode != nullptr) {
				strBackwardsStream << pCurrentNode->m_data << " ";
				pCurrentNode = pCurrentNode->m_prev;
			}

			Assert::AreEqual(std::string("15 10 5 20 "), strBackwardsStream.str());
		}
	};
}
