#pragma once

#include "Project09/GameState.h"
#include "Project09/Transformation.h"

class RootTransformation : public Transformation
{
public:
	RootTransformation(int resolution[2], bool fullscreen) : Transformation(0) {}

	~RootTransformation() {};

	Transformation* Begin();
	Transformation* Begin(bool activate);

	Transformation* Continue();
};
