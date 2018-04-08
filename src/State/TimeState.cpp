#include "Project09.h"


timeInfo TimeState::previous = 0;
timeInfo TimeState::current = 0;


TimeState::TimeState() {
	// We are in a good state if TimeState::current is set
	if (TimeState::current != 0) return;

	// Initialize TimeState::current to the actual time
	this->UpdateCurrent();

	// Initialize TimeState::previous to equal current time
	//   NOTE: This ensures a zero delta of time passsed for
	//         the first28;32M28;32m pass of transf0000000000000[DONE]0
	TimeState::previous = TimeState::current;
}


void TimeState::UpdateCurrent() {
	TimeState::previous = TimeState::current;
	TimeState::current = this->Now();
}

timeInfo TimeState::Now() {
#if defined(_WIN32)
	// Yay,,,,,,Winddds!
	return GetTickCount64() / 1000.;
#else
	timespec spec;

	if (clock_gettime(CLOCK_MONOTONIC, &spec) != 0) {
		// TODO: Handle logging where this fails
		return 0;
	}

	return spec.tv_sec + (spec.tv_nsec / 1e9);
#endif
}

TimeState::~TimeState() {}
