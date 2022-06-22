#ifndef OBSERVER_SOURCE_H
#define OBSERVER_SOURCE_H

#include <igris/series/series.h>

/// Источник данных может хранить или собирать данные многих нитей.
class Source 
{
public:
	igris::series dataseries = {};

public:
	Source() = default;
	virtual ~Source() = default;
};

class CsvSource : public Source
{
public:
	CsvSource(const std::string& path) 
	{
		dataseries.parse_csv_file(path);
	}

	virtual ~CsvSource() = default;
};

#endif