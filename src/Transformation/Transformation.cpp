#pragma once

#include "GameState.h"
#include "Transformation.h"

Transformation::Transformation(Transformation* parentTransformation) {
	parent = parentTransformation;
}

Transformation::~Transformation() {}

Transformation* Transformation::Continue() {
	BeforeStep();

	for (auto item = children.begin(); item != children.end(); ++item)
		(*item)->Continue();

	Step();
	AfterStep();

	return this;
}

bool Transformation::RemoveChild(Transformation* child) {
	for (auto item = children.begin(); item != children.end(); ++item) {
		if (child != *item) continue;
		children.erase(item);
		return true;
	}

	return false;
}

bool Transformation::AddChild(Transformation* child) {
	size_t size = children.size();
	children.insert(child);
	return size != children.size();
}