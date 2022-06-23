#ifndef OBSERVER_WORKSPACE_H
#define OBSERVER_WORKSPACE_H

#include <Source.h>
#include <ViewAdaptor.h>

#include <list>
#include <memory>

class Workspace 
{
public:
	std::list<std::shared_ptr<Source>> csv_sources = {};
	std::list<ViewAdaptor*> views = {};

public:
	Workspace() = default;

	void add_csv_source(const std::string& path);
	void add_crow_theme_source(const std::string& theme);

	std::string serialize_workspace();
	void deserialize_workspace(const std::string& dump);
};

#endif