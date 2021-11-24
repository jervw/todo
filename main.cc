#include "todo.hh"

int main(int argc, char* argv[])
{
    Todo todo;

    if(argc > 1)
    {
        std::vector<std::string> args(argv + 2, argv + argc);
        std::string cmd = argv[1];

        if(cmd=="init")
            todo.init();
        if(cmd=="add")
            todo.add(args);
        if(cmd=="rm")
            todo.rm(args);
        if(cmd=="list")
            std::cout << "list\n";
        if(cmd=="done")
            std::cout << "done\n";
    }
    else
        todo.list();

    return 0;
}