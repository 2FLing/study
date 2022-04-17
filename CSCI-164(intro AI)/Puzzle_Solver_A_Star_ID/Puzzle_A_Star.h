#ifndef _PUZZLE
#define _PUZZLE
#include "Node.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include<map>
#include "Pqueue.h"
using namespace std;
bool is_moveable(Node*, char);
string move_on(string, char);  // move the space(number 0) by the direction, and return the vector after moving as the result.                                                                                                         // find the index of the target, return -1 if not found.                                                                                                           // reads a series of numbers in string format and convert them to an array.
bool is_goal(string, string);  // check if the current state is the goal state.
void extend_states(Node* last_state, Pqueue* open_list,map<string,int>&expanded_nodes, string init_state, string goal); // extend the current state by adding its all of the available states.
int G_H(string current_state, string init_state, string goal);                                                                 // calculate the G and H of the current_state
void print_string(string);
pair<string, int> solve_puzzle(string, string); // it takes an initial state for the puzzle and the goal state of the puzzle than return the solution as a result.
string get_path(Node*);                        // get the solving path of the solution
char get_direction(string, string); // get the direction from one step to another step
void reverse(string&);
void print_process(Node*);               // print out the solving process
string test_solution(string init_state,string directions);
bool is_moveable(Node* state, char direction)
{
    string v = state->get_val();

    int cr = sqrt(v.size()); // column and row;
    int index = v.find('0');
    if (state->get_parent())
    {
        char direction_to_parent = get_direction(v, state->get_parent()->get_val());
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
        if (index >= v.size() - cr)
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
string move_on(string v, char direction)
{
    int cr = sqrt(v.size()); // column and row;
    int index = v.find('0');

    if (direction == 'u')
    {
        swap(v[index], v[index - cr]);
    }
    else if (direction == 'd')
    {
        swap(v[index], v[index + cr]);
    }
    else if (direction == 'l')
    {
        swap(v[index], v[index - 1]);
    }
    else
    {
        swap(v[index], v[index + 1]);
    }
    return v;
}
bool is_goal(string goal, string state)
{
    return (goal == state);
}
void extend_states(Node* current_state, Pqueue* open_list, map<string,int>&expaned_nodes, string init_state, string goal)
{

    string directions = "udrl";
    for (auto direction : directions)
    {
        if (is_moveable(current_state, direction))
        {
            string new_state = move_on(current_state->get_val(), direction);
            int gh = G_H(new_state, init_state, goal);
            Node* temp = new Node(new_state, gh);
            temp->set_parent(current_state);
            temp->set_depth(current_state->get_depth()+1);
            expaned_nodes[new_state]++;
            open_list->insert(temp);
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
    map<string, int> close_list;
    Pqueue* open_list;
    string path = "";
    Node* current_state;
    pair<string, int> res;
    map<string,int>expaned_nodes;
    string init_state = puzzle;
    int depth_limit=0;
    current_state = new Node(init_state, 0);
    open_list = new Pqueue(current_state);
    while (true)
    {
        current_state = open_list->pop();
        if (!current_state)
        {
            cout << "Unable to solve this puzzle :(" << endl;
            exit(1);
        }
        if (is_goal(goal, current_state->get_val()))
        {
            res.first = get_path(current_state);
            res.second = expaned_nodes.size();
            print_process(current_state);
            break;
        }
        while (current_state && close_list[current_state->get_val()] != 0)
        {
            current_state = open_list->pop();
        }
        if (!current_state)
        {
            cout << "Unable to solve this puzzle :(" << endl;
            exit(1);
        }
        close_list[current_state->get_val()]++;
        if(current_state->get_depth()>depth_limit)
        {
            open_list->clear();
            depth_limit++;
            close_list.clear();
            while(current_state->get_parent())
            {
                current_state=current_state->get_parent();
            }
            open_list->insert(current_state);
        }
        else
        {
            extend_states(current_state, open_list, expaned_nodes, init_state, goal);
        }
    }

    return res;
}

string get_path(Node* solution)
{
    string path;
    while (solution->get_parent())
    {
        Node* parent = solution->get_parent();
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
void reverse(string& str)
{
    string temp;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        temp.push_back(str[i]);
    }
    str = temp;
}
void print_process(Node* solution)
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
int G_H(string current_state, string init_state, string goal)
{
    int G = 0, H = 0, cr = sqrt(current_state.size());
    for (int i = 0; i < current_state.size(); i++)
    {
        if (current_state[i] != '0')
        {
            int num_in_init = init_state.find(current_state[i]);
            int num_in_goal = goal.find(current_state[i]);
            G += abs(num_in_init % cr - i % cr) + abs(num_in_init / 3 - i / 3);
            H += abs(num_in_goal % cr - i % cr) + abs(num_in_goal / 3 - i / 3);
        }
    }
    return G + H;
}

bool exist(vector<string> v, Node* n)
{
    for (auto ele : v)
    {
        if (ele == n->get_val())
            return true;
    }
    return false;
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
