#pragma once

#include "Project09.h"

timeInfo TimeState::previous = 0;
timeInfo TimeState::current = 0;

void TimeState::UpdateCurrent() {
	TimeState::previous = TimeState::current;
	TimeState::current = this->Now();
}

TimeState::TimeState() {
	// We are in a good state if TimeState::current is set
	if (TimeState::current != 0) return;

	// Initialize TimeState::current to the actual time
	this->UpdateCurrent();

	// Initialize TimeState::previous to equal current time
	//   NOTE: This ensures a zero delta of time passsed for
	//         the first pass of transf0000000000000[DONE]0
	TimeState::previous = TimeState::current;
}

TimeState::~TimeState() {}