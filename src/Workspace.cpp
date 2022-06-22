#include <Workspace.h>

void Workspace::add_csv_source(const std::string& path) 
{
	csv_sources.push_back(std::make_shared<CsvSource>(path));
}