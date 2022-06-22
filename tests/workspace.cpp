#include <doctest/doctest.h>
#include <Workspace.h>
#include <Fiber.h>

TEST_CASE("Workspace") 
{
	Workspace ws;
	ws.add_csv_source("csv_test.csv");
}