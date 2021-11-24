#pragma once
#include <vector>
#include <string>
#include <iostream>


struct TodoItem {
    std::string text;
    int priority = 0;
    bool state = 0;
};

class Todo {
private:
    std::string strikethrough(const std::string& text);
    const std::string fname = ".todo";
    std::vector<TodoItem> todoList;

public:
    Todo();
    void readFile();
    void saveFile();
    void init();
    void list();
    void add(std::vector<std::string> args);
    void rm(std::vector<std::string> args);
    void done(std::vector<std::string> args);
    ~Todo();
};
