#pragma once

#include "RenderableTransformation.h"

class AudioTransformation : public RenderableTransformation
{
public:
	AudioTransformation(Transformation* parent) : RenderableTransformation(parent) {};
};