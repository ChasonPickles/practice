#include "observer.h"
#include "subject.h"

Observer::Observer(Subject * station) : radio (station){
	radio->register_listener(this);
}
