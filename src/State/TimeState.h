#pragma once

#include "Project09.h"

typedef double timeInfo;

class TimeState
{
public:
	TimeState();
	~TimeState();

	timeInfo Now() {
		/** Yay,,,,,,Winddds!
		 *
		 * TODO: Replace GetTickCount with something that has a resolution better than ~16ms.
		 **/
		return GetTickCount() * 1000.;
	};

	void UpdateCurrent();

protected:
	static timeInfo current;
	static timeInfo previous;
};