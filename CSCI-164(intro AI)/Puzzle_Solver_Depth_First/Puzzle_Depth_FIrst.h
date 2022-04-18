#ifndef _PUZZLE
#define _PUZZLE
#include "Node.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <unordered_map>
using namespace std;
bool is_moveable(Node *, char);
string move_on(string, char);                  // move the space(number 0) by the direction, and return the vector after moving as the result.                                                                                                                // find the index of the target, return -1 if not found.                                                                                                                 // reads a series of numbers in string format and convert them to an array.
bool is_goal(string, string);                  // check if the current state is the goal state.
void extend_states(vector<Node *> &open_list); // extend the current state by adding its all of the available states.
void print_string(string);
pair<string, int> solve_puzzle(string, string); // it takes an initial state for the puzzle and the goal state of the puzzle than return the solution as a result.
string get_path(Node *);                        // get the solving path of the solution
char get_direction(string, string);             // get the direction from one step to another step
void reverse(string &);
void print_process(Node *); // print out the solving process
string test_solution(string init_state, string directions);
bool exist(vector<Node *> v, string state);
int cal_closed_node(unordered_map<string, int> nodes);
bool is_moveable(Node *state, char direction)
{
    string str = state->get_val();

    int cr = sqrt(str.size()); // column and row;
    int index = str.find('0');
    if (state->get_parent())
    {
        int direction_to_parent = get_direction(str, state->get_parent()->get_val());
        if (direction == direction_to_parent)
            return false;
    }
    if (direction == 'u')
    {
        if (index < cr)
            return false;
        else
            return true;
    }
    else if (direction == 'd')
    {
        if (index >= str.size() - cr)
            return false;
        else
            return true;
    }
    else if (direction == 'l')
    {
        if (index % cr == 0)
            return false;
        else
            return true;
    }
    else
    {
        if (index % cr == (cr - 1))
            return false;
        else
            return true;
    }
}
string move_on(string str, char direction)
{
    int cr = sqrt(str.size()); // column and row;
    int index = str.find('0');

    if (direction == 'u')
    {
        swap(str[index], str[index - cr]);
    }
    else if (direction == 'd')
    {
        swap(str[index], str[index + cr]);
    }
    else if (direction == 'l')
    {
        swap(str[index], str[index - 1]);
    }
    else
    {
        swap(str[index], str[index + 1]);
    }
    return str;
}

bool is_goal(string goal, string state)
{
    return (goal == state);
}
void extend_states(vector<Node *> &open_list)
{

    string directions = "udrl";
    Node *current_state = open_list.back();
    open_list.pop_back();
    for (auto direction : directions)
    {
        if (is_moveable(current_state, direction))
        {
            string new_state = move_on(current_state->get_val(), direction);
            if (!exist(open_list, new_state))
            {
                Node *temp = new Node(new_state);
                temp->set_parent(current_state);
                open_list.push_back(temp);
            }
        }
    }
}
void print_string(string v)
{
    int cr = sqrt(v.size());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
        if (i % cr == cr - 1)
            cout << endl;
    }
    cout << endl;
}
pair<string, int> solve_puzzle(string puzzle, string goal)
{
    unordered_map<string, int> close_list;
    vector<Node *> open_list;
    string path = "";
    Node *current_state;
    pair<string, int> res;
    string init_state = puzzle;
    current_state = new Node(init_state);
    open_list.push_back(current_state);
    while (true)
    {
        current_state = open_list.back();
        if (is_goal(goal, current_state->get_val()))
        {
            res.first = get_path(current_state);
            res.second = cal_closed_node(close_list);
            break;
        }
        while (current_state && close_list[current_state->get_val()] != 0)
        {
            if (open_list.empty())
            {
                cout << "Unable to solve this puzzle :(" << endl;
                exit(1);
            }
            else
            {
                current_state = open_list.back();
                open_list.pop_back();
            }
        }
        close_list[current_state->get_val()]++;
        extend_states(open_list);
    }

    return res;
}

string get_path(Node *solution)
{
    string path;
    while (solution->get_parent())
    {
        Node *parent = solution->get_parent();
        char direction = get_direction(parent->get_val(), solution->get_val());
        path.push_back(direction);
        solution = parent;
    }
    if (path.empty())
        path = "None";
    else
        reverse(path);
    return path;
}
char get_direction(string step, string next_step)
{
    int zero_in_step = step.find('0');
    int zeor_in_next_step = next_step.find('0');
    if (zeor_in_next_step == zero_in_step + 1)
        return 'r';
    else if (zeor_in_next_step == zero_in_step - 1)
        return 'l';
    else if (zeor_in_next_step > zero_in_step)
        return 'd';
    else
        return 'u';
}
void reverse(string &str)
{
    string temp;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        temp.push_back(str[i]);
    }
    str = temp;
}
void print_process(Node *solution)
{
    vector<string> process;
    while (solution->get_parent())
    {
        process.push_back(solution->get_val());
        solution = solution->get_parent();
    }
    process.push_back(solution->get_val());
    for (int i = process.size() - 1; i >= 0; i--)
    {
        print_string(process[i]);
    }
}
int cal_closed_node(unordered_map<string, int> nodes)
{
    int count = 0;
    for (auto ele : nodes)
    {
        if (ele.second == 1)
            count++;
    }
    return count;
}

string test_solution(string init_state, string directions)
{
    for (int i = 0; i < directions.size(); i++)
    {
        Node *temp = new Node(init_state);
        char direction = directions[i];
        if (is_moveable(temp, direction))
            ;
        {
            init_state = move_on(init_state, direction);
        }
    }
    return init_state;
}
bool exist(vector<Node *> v, string state)
{
    for (auto ele : v)
    {
        if (ele->get_val() == state)
            return true;
    }
    return false;
}
#endif // !PUZZLE
