#include "fighter.h"
using namespace std;

int damageAmount = 75;

Fighter::Fighter(string name) : Player(name) {
	// nothing to do here
}

void Fighter::doAction(Player *target) {
	if (!target) return;
	target->setHP(target->getHP()-damageAmount);
	
}