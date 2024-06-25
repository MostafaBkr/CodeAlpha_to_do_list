/*
MIT License

Copyright (c) 2024 CodeAlpha

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/    
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TaskManager {
private:
    vector<string> task_list;
    vector<bool> completed;

public:
    void insert_task() {
        string task;
        cin.ignore();
        cout << "Enter task " << task_list.size() + 1 << ": ";
        getline(cin, task);
        task_list.push_back(task);
        completed.push_back(false);
        cout << endl;
    }

    void view_tasks() const {
        cout << "\nTasks:" << endl;
        for (size_t i = 0; i < task_list.size(); ++i) {
            cout << i + 1 << ". " << task_list[i]
                << (completed[i] ? " [Completed]" : "") << endl;
        }
    }

    void complete_task() {
        int task_num;
        cout << "Enter task number to mark as completed: ";
        cin >> task_num;
        if (task_num > 0 && task_num <= task_list.size()) {
            completed[task_num - 1] = true;
            cout << "Task " << task_num << " marked as completed." << endl;
        }
        else {
            cout << "Invalid task number." << endl;
        }
    }

    void remove_task() {
        int task_num;
        cout << "Enter task number to remove: ";
        cin >> task_num;
        if (task_num > 0 && task_num <= task_list.size()) {
            task_list.erase(task_list.begin() + task_num - 1);
            completed.erase(completed.begin() + task_num - 1);
            cout << "Task " << task_num << " removed." << endl;
        }
        else {
            cout << "Invalid task number." << endl;
        }
    }
};

void menu() {
    cout << "\nMenu\n"
        << "1. Insert task\n"
        << "2. View tasks\n"
        << "3. Complete task\n"
        << "4. Remove task\n"
        << "5. Exit\n"
        << "Enter your choice: ";
}

int main() {
    TaskManager user_task_list;
    int choice = 5;
    do {
        menu();
        cin >> choice; cout << endl;
        switch (choice) {
        case 1:
            user_task_list.insert_task();
            break;
        case 2:
            user_task_list.view_tasks();
            break;
        case 3:
            user_task_list.complete_task();
            break;
        case 4:
            user_task_list.remove_task();
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
    return 0;
}

