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
Run the Todo CLI program in your terminal and use the following commands to manage your tasks:\
./todocli add [task] — Add a new task.\
./todocli delete [task ID] — Remove a task by its ID.\
./todocli complete [task ID] — Mark a task as done.\
./todocli list — Display all tasks in a table format.
