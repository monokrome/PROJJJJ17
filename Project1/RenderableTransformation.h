#include "Project09.h"

#include "Transformation.h"

#pragma once
class RenderableTransformation : public Transformation
{
public:
	RenderableTransformation(Transformation* parent) : Transformation(parent) {}
	~RenderableTransformation() {}

	DEFINE_ACTION(Render)
};

