#include "AnimatedGameActor.h"

void AnimatedGameActor::draw() {
	if (this->isOver())
		return;
	SkinGameActor::draw();	
}