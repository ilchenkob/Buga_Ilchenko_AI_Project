#pragma once
#include "point.h"
#include "config.h"
#include <stdlib.h>
#include <list>

using namespace global;

class AbstractAgent
{
public:

	virtual bool ReadyToGo() = 0;

};

class CAI_Engine
{
public:

	CAI_Engine() {}

	void SetAgent( AbstractAgent* ptr ) { m_ptrAgent = ptr; };

private:

	AbstractAgent *m_ptrAgent;
};