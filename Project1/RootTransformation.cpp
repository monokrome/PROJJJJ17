#include "Project09.h"

#include "RootTransformation.h"

Transformation* RootTransformation::Begin(void) { return Begin(true); }

Transformation* RootTransformation::Begin(bool simulateRealTime) {
	// Executes our main loop for our root Transformation object
	delete (new TimeState());

	auto root = ((Transformation*)this);

	root->BeforePrepare()
		->Prepare()
		->AfterPrepare()
		->AfterPrepare();

	// Initial step always runs regardless of isRealTime state
	root->Continue();

	// Simulating over time only occurs if simulateRealTime is true
	while (simulateRealTime) root->Continue();

	root->BeforeTerminate()->Terminate()->AfterTerminate();

	return root;
}