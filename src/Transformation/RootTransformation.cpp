#include "Project09.h"

#include "RenderableTransformation.h"
#include "RootTransformation.h"

Transformation* RootTransformation::Begin(void) { return Begin(true); }

Transformation* RootTransformation::Begin(bool simulateRealTime) {
	// Executes our main loop for our root Transformation object
	delete (new TimeState());
	BeforePrepare()->Prepare()->AfterPrepare()->Continue();
	// TODO: Implement generic conccurency support for Transformation here
	while (simulateRealTime) Continue();
	BeforeTerminate()->Terminate()->AfterTerminate();
	return this;
}

Transformation* RootTransformation::Continue() {
	// After all steps have occured, RootTransformation takes care of calling into the renderable tree as well
	auto result = Transformation::Continue();
	for (auto item = children.begin(); item != children.end(); ++item) {
		auto renderable = (RenderableTransformation*) (*item);
		if (renderable == 0) continue;
		renderable->Render();
	}
	return result;
}
