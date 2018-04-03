#pragma once

#include "GameState.h"
#include "Transformation.h"

class RootTransformation : public Transformation
{
public:
	RootTransformation(int resolution[2], bool fullscreen) : Transformation(0) {}

	~RootTransformation() {};

	Transformation* Begin();
	Transformation* Begin(bool activate);

	Transformation* Continue();
};