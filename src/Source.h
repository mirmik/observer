#ifndef OBSERVER_SOURCE_H
#define OBSERVER_SOURCE_H

#include <igris/series/series.h>
#include <nos/print.h>

/// Источник данных может хранить или собирать данные многих нитей.
class Source
{
public:
	igris::series dataseries = {};
	std::string declared_type;
	std::string source_name;

public:
	Source() = default;
	Source(std::string declared_type, std::string source_name)
		: declared_type(declared_type), source_name(source_name)
	{}
	
	virtual ~Source() 
	{
		nos::println("Source was destroyed:", source_info());
	}
	
	std::string source_info() 
	{
		return declared_type + " " + source_name;
	}
};

class CsvSource : public Source
{
public:
	CsvSource(const std::string& path) : Source("csv", path) 
	{
		dataseries.parse_csv_file(path);
	}

	virtual ~CsvSource() = default;
};

#endif