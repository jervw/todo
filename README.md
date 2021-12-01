# Todo

Simple and easy to use Todo app written in C++. 

## Installation

Use the package manager [pip](https://pip.pypa.io/en/stable/) to install foobar.

```bash
git clone https://github.com/jervw/todo.git
cd todo
mkdir build && cd build
cmake ..
make
```
To add the `todo` command to your path, run:
```bash
cp todo /usr/bin/
```
## Usage

```
Usage: todo [COMMAND] [ARGUMENTS]
    - add [TASK/s]
        adds new task/s
        example: todo add 'do some coding
    - list
        lists all tasks
        example: todo list
    - done [NUMBER]
        marks task as done
        example: todo done 3 4
    - rm [NUMBER]
        removes a task
        example: todo rm 2
    - clean
        removes a completed tasks
        example: todo clean
    - purge
        removes all tasks
        example: todo purge
```

## License
[MIT](https://choosealicense.com/licenses/mit/)
