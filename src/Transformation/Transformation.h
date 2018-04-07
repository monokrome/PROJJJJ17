#pragma once

#include "Project09.h"

#include <unordered_set>

#include "GameState.h"
#include "TimeState.h"

#define DEFINE_ACTION_STEP(__NAME__) Transformation* __NAME__() { return (Transformation*) this; }

#define DEFINE_ACTION(__NAME__);                      \
	DEFINE_ACTION_STEP(Before##__NAME__);             \
	DEFINE_ACTION_STEP(__NAME__);                     \
	DEFINE_ACTION_STEP(After##__NAME__)

class Transformation;

typedef Transformation* _TransformationPtr;
typedef std::unordered_set<_TransformationPtr> transformationSet;

class Transformation
{
public:
	Transformation(Transformation* parent);
	~Transformation();

	bool AddChild(Transformation* child);
	bool RemoveChild(Transformation* child);

	Transformation* Continue();

	DEFINE_ACTION(Prepare);
	DEFINE_ACTION(Step);
	DEFINE_ACTION(Terminate);

protected:
	transformationSet children;  // Container for our set of Transformation* children
	Transformation *parent;      // Reference to the parent Transformation* object

private:
	const static GameState state;
};