#ifndef OBSERVER_FIBER_H
#define OBSERVER_FIBER_H

#include <Source.h>
#include <igris/series/field_annotation.h>

class Fiber 
{
	std::shared_ptr<Source> source;
	igris::series_field_annotation annot;

public:
	Fiber() = default;
};

#endif