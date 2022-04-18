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
string move_on(string, char);                  // move the space(number 0) by the direction, and return the vector after moving as the result.                                                                                 // find the index of the target, return -1 if not found.                                                                                 // reads a series of numbers in string format and convert them to an array.
bool is_goal(string goal, string state);       // check if the current state is the goal state.
void extend_states(vector<Node *> &open_list); // extend the current state by adding its all of the available states.                                                 // calculate the G and H of the current_state
void print_string(string);
pair<string, int> solve_puzzle(string, string); // it takes an initial state for the puzzle and the goal state of the puzzle than return the solution as a result.
string get_path(Node *);                        // get the solving path of the solution
char get_direction(string, string);             // get the direction from one step to another step
void reverse(string &);
void print_process(Node *);         // print out the solving process
bool exist(vector<Node *>, string); // it check if the argument node is exist in the vector.
string test_solution(string init_state, string directions);
int cal_closed_node(unordered_map<string, int>);
int find_element(string v, char element)
{
    int index = -1;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == element)
        {
            index = i;
            break;
        }
    }
    return index;
}
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
string move_on(string state, char direction)
{
    int cr = sqrt(state.size()); // column and row;
    vector<int> res;
    int index = state.find('0');

    if (direction == 'u')
    {
        swap(state[index], state[index - cr]);
    }
    else if (direction == 'd')
    {
        swap(state[index], state[index + cr]);
    }
    else if (direction == 'l')
    {
        swap(state[index], state[index - 1]);
    }
    else
    {
        swap(state[index], state[index + 1]);
    }
    return state;
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
                temp->set_depth(current_state->get_depth() + 1);
                open_list.push_back(temp);
            }
        }
    }
}
void print_string(string state)
{
    int cr = sqrt(state.size());
    for (int i = 0; i < state.size(); i++)
    {
        cout << state[i] << " ";
        if (i % cr == cr - 1)
            cout << endl;
    }
    cout << endl;
}
pair<string, int> solve_puzzle(string puzzle, string goal)
{
    int limit = 0;
    string init_state, goal_state;
    unordered_map<string, int> close_list;
    vector<Node *> open_list;
    string path = "";
    Node *current_state;
    pair<string, int> res;
    init_state = puzzle;
    goal_state = goal;
    current_state = new Node(init_state);
    open_list.push_back(current_state);
    while (true)
    {
        current_state = open_list.back();
        if (is_goal(goal_state, current_state->get_val()))
        {
            res.first = get_path(current_state);
            res.second = cal_closed_node(close_list);
            print_process(current_state);
            break;
        }
        else
        {
            if (current_state->get_depth() == limit)
            {
                open_list.pop_back();
                if (open_list.empty())
                {
                    Node *node = new Node(init_state);
                    current_state = node;
                    open_list.push_back(current_state);
                    limit++;
                    close_list.clear();
                }
            }
            while (current_state && close_list[current_state->get_val()] != 0)
            {
                if (!open_list.empty())
                {
                    open_list.pop_back();
                    if (open_list.empty())
                    {

                        Node *node = new Node(init_state);
                        current_state = node;
                        open_list.push_back(current_state);
                        limit++;
                        close_list.clear();
                    }
                    current_state = open_list.back();
                }
            }
            if (current_state->get_depth() < limit)
            {
                close_list[current_state->get_val()]++;
                extend_states(open_list);
            }
        }
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

bool exist(vector<Node *> v, string state)
{
    for (auto ele : v)
    {
        if (ele->get_val() == state)
            return true;
    }
    return false;
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
#endif // !PUZZLE
