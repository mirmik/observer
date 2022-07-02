#include <Fiber.h>

void Source::make_fibers() 
{
	_fibers.clear();
	for (auto annot: dataseries.annotations()) 
		_fibers.push_back(std::make_shared<Fiber>(*this, annot));
}