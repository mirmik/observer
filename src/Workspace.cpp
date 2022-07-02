#include <Workspace.h>

Workspace::Workspace() 
{
	add_test_source("test0");
	add_test_source("test1");
	add_test_source("test2");
}

void Workspace::add_csv_source(const std::string& path) 
{
	sources.push_back(std::make_shared<CsvSource>(path));
}

void Workspace::add_test_source(const std::string& name) 
{
	sources.push_back(std::make_shared<TestSource>(name));
}

std::vector<std::shared_ptr<Fiber>> Workspace::fibers() 
{
	std::vector<std::shared_ptr<Fiber>> ret;
	for (auto& source : sources) 
	{
        auto f = source->fibers();
        std::copy(f.begin(), f.end(), std::back_inserter(ret));
	}
	return ret;	
}