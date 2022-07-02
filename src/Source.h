#ifndef OBSERVER_SOURCE_H
#define OBSERVER_SOURCE_H

#include <igris/series/series.h>
#include <ralgo/linalg/vecops.h>
#include <nos/print.h>
#include <Fiber.h>

class Fiber;

/// Источник данных может хранить или собирать данные многих нитей.
class Source
{
public:
	std::vector<std::shared_ptr<Fiber>> _fibers;
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

	void make_fibers();
	std::vector<std::shared_ptr<Fiber>> &fibers() { return _fibers; }
};

class CsvSource : public Source
{
public:
	CsvSource(const std::string& path) : Source("csv", path) 
	{
		dataseries.parse_csv_file(path);
		make_fibers();
	}

	virtual ~CsvSource() = default;
};

class TestSource : public Source
{
public:
	TestSource(const std::string& name) : Source("test", name) 
	{
		dataseries.set_elemsize(2*sizeof(double));
		auto t = ralgo::vecops::div_vs<std::vector<double>>(ralgo::vecops::arange(100), 10);		
		auto s = ralgo::vecops::sin(t);
		for (unsigned int i = 0; i < t.size(); ++i) 
		{
			std::pair<double, double> p = { t[i], s[i] }; 
			dataseries.push_object(&p, sizeof(p));
		}

		dataseries.annotator().add<double>("t");
		dataseries.annotator().add<double>("s");
		make_fibers();
	}
};

#endif