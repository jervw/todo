#include "todo.hh"

struct TodoItem todoItem;

Todo::Todo()
{
    read_file();
}

Todo::~Todo()
{
    save_file();
}

void Todo::read_file()
{
    std::fstream f(fname, std::ios::in);
    std::string ftext;
    bool fstate;

    while(f >> ftext >> fstate)
    {
        TodoItem item;
        item.text = ftext;
        item.state = fstate;
        todoList.push_back(item);
    }

    f.close();
}

void Todo::save_file()
{
    std::fstream f(fname, std::ios::out | std::ios::trunc);
    for(auto i : todoList)
        f << i.text << " " << i.state << "\n";
    f.close();
}


void Todo::list()
{
    std::cout << "Type 'todo help' for the list of commands.\n";

    for(int i = 1; i <= todoList.size(); ++i)
    {
        std::cout << "\e[1m" << i << "\e[0m ";
        std::string text = todoList[i-1].text;
        std::string s = (todoList[i-1].state) ? "\u2713 " + todoList[i-1].text  : "\u2717 " + todoList[i-1].text;
        std::cout << s << "\n";
    }
}

void Todo::add(std::vector<std::string> args)
{
    for(auto i : args)
    {
        TodoItem item;
        item.text = i;
        todoList.push_back(item);
    }
}

void Todo::rm(std::vector<std::string> args)
{
    std::vector<int> nums = argsToInt(args);

    for(auto j : nums)
        if(todo_in_range(j))
            todoList.erase(todoList.begin() + j-1);
}

void Todo::done(std::vector<std::string> args)
{
    std::vector<int> nums = argsToInt(args);

    for(auto j : nums)
        if(todo_in_range(j))
            todoList[j-1].state = 1;
}

void Todo::clean()
{
    if(todoList.size() > 0)
        for(int x = 0; x <= todoList.size(); x++)
            if(todoList[x].state)
                todoList.erase(todoList.begin() + x);
}


bool Todo::todo_in_range(int num)
{
    return (0 <= num && num <= todoList.size());
}

std::vector<int> Todo::argsToInt(std::vector<std::string> args)
{
    std::vector<int> nums;
    std::transform(args.begin(), args.end(), std::back_inserter(nums),
        [](const std::string& str) { return std::stoi(str); });

    return nums;
}

void Todo::purge() { todoList.clear(); }

void Todo::usage()
{
    std::string s =
        "Usage: todo [COMMAND] [ARGUMENTS]\n"
        "Simple Todo app written in c++"
        "Available commands:\n"
        "   - add [TASK/s]\n"
        "       adds new task/s\n"
        "       example: todo add 'do some coding\n"
        "   - list\n"
        "       lists all tasks\n"
        "       example: todo list\n"
        //"   - sort\n"
        //"       sorts tasks by completion\n"
        //"       example: todo sort\n"
        "   - done [NUMBER]\n"
        "       marks task as done\n"
        "       example: todo done 3 4\n"
        "   - rm [NUMBER]\n"
        "       removes a task\n"
        "       example: todo rm 2\n"
        "   - clean\n"
        "       removes a completed tasks\n"
        "       example: todo clean\n"
        "   - purge\n"
        "       removes all tasks\n"
        "       example: todo purge\n";
    std::cout << s;
}