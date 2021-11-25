#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <algorithm>


struct TodoItem {
    std::string text;
    bool state = 0;
};

class Todo {
private:
    const std::string fname = ".todo";
    std::vector<TodoItem> todoList;
    std::vector<int> argsToInt(std::vector<std::string> args);
    void read_file();
    void save_file();
    bool todo_in_range(int num);

public:
    Todo();
    void add(std::vector<std::string> args);
    void rm(std::vector<std::string> args);
    void done(std::vector<std::string> args);
    void list();
    void clean();
    void purge();
    void usage();
    ~Todo();
};
