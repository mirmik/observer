#include <Fiber.h>

std::string Fiber::name() 
{
	return source.source_info() + " " + annot.machname;
}