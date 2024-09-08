# Todo CLI
Todo CLI is a simple and efficient command-line to-do list application designed to help you manage your tasks directly from the terminal. With an easy-to-use interface, you can add, remove, and mark tasks as completed, and view all tasks in a neatly formatted table.

## Features
- Add task: quickly add new tasks to your list.
- Remove task: delete tasks that are no longer needed.
- Mark as done: mark tasks as completed.
- List tasks: display all tasks in a table format with the following columns:
  - ID: unique identifier for each task.
  - Task: description of the task.
  - Created: how long ago the task was created.
  - Done: status of the task (completed or not).
- Persistent storage: all tasks are stored on disk in a CSV format, ensuring that your tasks are saved between sessions.

## Purpose
This program was created for educational purposes to demonstrate basic concepts of command-line applications, CSV file handling and printing data in tabular format.

## Usage
### Prerequisites
To build the Todo CLI program, you will need to use the Meson build system. Follow the steps below to install Meson and build the program on a Linux system.

### Installing Meson
1. Install Meson using your package manager. For example, on Debian-based systems like Ubuntu, you can run:
```bash
sudo apt update
sudo apt install meson
```

Alternatively, you can install Meson using pip:
```bash
pip install meson
```
2. Install Ninja, a small build system that Meson uses:
```bash
sudo apt install ninja-build
```

### Building the Program
1. Clone the repository:
```bash
git clone https://github.com/Brollof/TodoCLI.git
cd TodoCLI
```
2. Set up the build directory:
```bash
meson setup builddir
```
3. Build the program:
```bash
meson compile -C builddir
```
4. Run the Todo CLI program:
```bash
./builddir/todocli
```
### Commands
Use the following commands to manage your tasks:
- add [task] — Add a new task.
- delete [task ID] — Remove a task by its ID.
- complete [task ID] — Mark a task as done.
- list — Display all tasks in a table format.
