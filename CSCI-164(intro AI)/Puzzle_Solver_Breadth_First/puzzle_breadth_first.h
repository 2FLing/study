#ifndef _PUZZLE
#define _PUZZLE
#include "Node.h"
#include "Queue.h"
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
bool is_moveable(Node *, char);
string move_on(string, char);                         // move the space(number 0) by the direction, and return the vector after moving as the result.
bool is_goal(string, string);                         // check if the current state is the goal state.
void extend_state(Node *, Queue &, map<string, int>); // extend the current state by adding its all of the available states to it.
void print_string(string);
pair<string, int> solve_puzzle(string, string); // it takes an initial state for the puzzle and the goal state of the puzzle than return the solution as a result.
string get_path(Node *);                        // get the solving path of the solution
char get_direction(string, string);             // get the direction from one step to another step
void reverse(string &);
void print_process(Node *); // print out the solving process
string test_solution(string init_state, string directions);
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
void extend_state(Node *current_state, Queue &frontier, map<string, int> reached_nodes)
{
    string directions = "udrl";

    for (auto direction : directions)
    {
        if (is_moveable(current_state, direction))
        {
            string new_state = move_on(current_state->get_val(), direction);
            Node *temp = new Node(new_state);
            if (!frontier.exist(temp) && reached_nodes[new_state] == 0)
            {
                temp->set_parent(current_state);
                frontier.insert(temp);
            }
        }
    }
    reached_nodes[current_state->get_val()]++;
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
    string path = "";
    Node *current_state;
    map<string, int> expanded_nodes;
    pair<string, int> res = pair("", 0);
    string init_state = puzzle;
    current_state = new Node(init_state);
    Queue frontier(current_state);
    while (!frontier.is_empty())
    {
        current_state = frontier.pop();
        if (is_goal(goal, current_state->get_val()))
        {
            res.first = get_path(current_state);
            res.second = expanded_nodes.size() - 1;
            print_process(current_state);
            return res;
        }
        else
        {
            expanded_nodes[current_state->get_val()]++;
            extend_state(current_state, frontier, expanded_nodes);
        }
    }
    if (frontier.is_empty())
    {
        cout << "Not able to solve this puzzle :(";
        exit(1);
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
string test_solution(string init_state,string directions)
{
    for(int i=0;i<directions.size();i++)
    {
        Node* temp = new Node(init_state);
        char direction = directions[i];
        if(is_moveable(temp,direction));
        {
            init_state = move_on(init_state,direction);
        }
    }
    return init_state;
}
#endif // !PUZZLE
