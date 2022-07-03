#ifndef OBSERVER_FIBER_H
#define OBSERVER_FIBER_H

#include <Source.h>
#include <igris/series/field_annotation.h>
//#include <igris/series/fiber.h>

class Source;

class FiberID 
{
public:
    std::string source_type;
    std::string source_name;
    std::string fiber_name;
};

class Fiber
{
	Source& source;
	igris::series_field_annotation annot;

public:
	Fiber() = default;
	Fiber(Source& source, igris::series_field_annotation annot) 
		:source(source), annot(annot)
	{}
	Fiber(const Fiber& fiber) = delete;
	Fiber& operator=(const Fiber& fiber) = delete;

	std::string name();

	~Fiber() { nos::println("Fiber was destroyed:", name()); }
};

#endif