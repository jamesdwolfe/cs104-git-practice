#include "healer.h"
using namespace std;

int healAmount = 75;

Healer::Healer(string name) : Player(name) {
	// nothing to do here
}

void Healer::doAction(Player *target) {
	if (!target) return;
	if(target->getHP()+healAmount > target->getMaxHP()) {
		target->setHP(target->getMaxHP()); 
		return;
	} else {
		target->setHP(target->getHP()+healAmount);
	}
	
}