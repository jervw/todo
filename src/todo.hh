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
    const std::string fname = std::getenv("HOME") + std::string("/.todo");
    std::vector<std::string> args;
    std::vector<TodoItem> todoList;
    std::vector<int> argsToInt(std::vector<std::string> args);
    bool todoInRange(int num);
    void readFile();
    void saveFile();

public:
    Todo(int argc, char* argv[]);
    void add();
    void rm();
    void done();
    void list();
    void clean();
    void purge();
    void usage();
    ~Todo();
};
