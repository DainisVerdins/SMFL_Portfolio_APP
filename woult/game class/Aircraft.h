#pragma once
#include "Entity.h"
class Aircraft :public Entity
{
public:
	enum class Type
	{
		Eagle,
		Raptor,
	};
public:
	explicit Aircraft(Type type) :mType{ mType } {};
private:
	Type mType;
};

