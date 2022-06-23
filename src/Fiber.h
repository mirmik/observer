#ifndef OBSERVER_FIBER_H
#define OBSERVER_FIBER_H

#include <Source.h>
#include <igris/series/field_annotation.h>

class FiberID 
{
public:
    std::string source_type;
    std::string source_name;
    std::string fiber_name;
};

class Fiber 
{
	std::shared_ptr<Source> source;
	igris::series_field_annotation annot;

public:
	Fiber() = default;
};

#endif