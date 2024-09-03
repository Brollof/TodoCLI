#include <iostream>
#include <string>
#include <CLI11.hpp>

using namespace std;

int main(int argc, char** argv)
{
	CLI::App app{"App description"};

	string tmp = "";
	uint32_t num = -1;

	CLI::App *add = app.add_subcommand("add", "add a new task");
	add->add_option("task", tmp)->required();

	CLI::App *list = app.add_subcommand("list", "show undone tasks");
	list->add_flag("--all", "show all tasks");

	CLI::App *complete = app.add_subcommand("complete", "complete task");
	complete->add_option("ID", num, "task ID")->required();


    CLI11_PARSE(app, argc, argv);

	return 0;
}

