#pragma once

#include "GameState.h"
#include "Transformation.h"

class RootTransformation : public Transformation
{
public:
	RootTransformation() : Transformation(0) {}

	~RootTransformation() {};

	Transformation* Begin();
	Transformation* Begin(bool activate);
};
