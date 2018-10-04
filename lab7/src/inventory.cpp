#include "inventory.h"
#include <iostream>
using namespace std;


Inventory::Inventory(){
	
}

void Inventory::addItem(string s, int c){
	for(size_t i = 0; i < this->size(); i++){
		if (this->at(i).name == s){ this->at(i).amount += c; return; }
	}
	this->push_back(Item(s,c));
}

void Inventory::removeItem(string s){
	for(size_t i = 0; i < this->size(); i++){
		if (this->at(i).name == s){ this->erase(this->begin()+i); }
	}
}

int Inventory::getNumItems(string s){
	for(size_t i = 0; i < this->size(); i++){
		if (this->at(i).name == s){ return this->at(i).amount; }
	}
	return 0;
}

void Inventory::printAllItems(){
	for(size_t i = 0; i < this->size(); i++){
		cout << this->at(i).name << " " << this->at(i).amount << endl;
	}
}



