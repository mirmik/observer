#ifndef OBSERVER_WORKSPACE_H
#define OBSERVER_WORKSPACE_H

#include <Source.h>

#include <list>
#include <memory>

class Workspace 
{
public:
	std::list<std::shared_ptr<Source>> csv_sources = {};

public:
	Workspace() = default;

	void add_csv_source(const std::string& path);
};

#endif