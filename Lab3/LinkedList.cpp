#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() {
    this->head = nullptr;
}

LinkedList::~LinkedList() {
    //TODO WITH LAB INSTRUCTOR
    while(head != nullptr) {
	    Node* temp = head->next;
	    delete head;
	    head = temp;
	}
}

void LinkedList::add(int data) {
    Node* node = new Node();
    node->data = data;
    node->next = this->head;
    this->head = node;
}

void LinkedList::InsertNth(int index, int data) {
    //TODO
    //Good luck :)
    if(index < 0) {
    	return;
    }
    else if(index == 0 ) {
    	add(data);
    	return;
    }

    


    Node* cur = head;
    int i = 0;
    while(cur != nullptr){
    	if(i != index-1){
    		cur = cur->next;
    	} else {
    		Node* newNode = new Node();
   			newNode->data = data;
    		newNode->next = cur->next;
    		cur->next = newNode;
    		return;
    	}
    	i++;
    }


}


void LinkedList::RemoveDuplicates() {
    //TODO
    //Good luck :)
    Node* cur = this->head;
    while(cur != nullptr){

    		while(cur->next && cur->data == cur->next->data){

    			int x = cur->data;
    			int y = cur->next->data;

    			Node* temp = cur->next->next;
    			delete cur->next;

    			cur->next = temp;

    		}

    	if(cur->next != nullptr){
    		Node* temp = cur->next;
    		cur = temp;
    	} else {
    		return;
    	}
    }
}