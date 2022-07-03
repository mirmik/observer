#ifndef OBSERVER_WORKSPACE_H
#define OBSERVER_WORKSPACE_H

#include <Source.h>
#include <Fiber.h>
#include <ViewAdaptor.h>

#include <list>
#include <memory>

class Workspace 
{
public:
	std::list<std::shared_ptr<Source>> sources = {};
	std::list<std::unique_ptr<ViewAdaptor>> views = {};

public:
	Workspace();

	void add_csv_source(const std::string& path);
	void add_test_source(const std::string& name);
	void add_crow_theme_source(const std::string& theme);

	std::string serialize_workspace();
	void deserialize_workspace(const std::string& dump);

	std::vector<std::shared_ptr<Fiber>> fibers();

	ChartViewAdaptor& create_chart_view_adaptor(); 
	ChartViewAdaptor& create_chart_view_adaptor(std::shared_ptr<Fiber> fiber); 
};

#endif