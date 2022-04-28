//Mingkuan Pang
//group 3
#include <vector>
#include "Heap.h"
using namespace std;
struct Sorts
{
    void insertion(vector<int> &v)
    {
        for (int i = 1; i < v.size(); i++)
        {
            int key = v[i];
            int j = i - 1;
            while (j >= 0 && v[j] > key)
            {
                v[j + 1] = v[j];
                j--;
            }
            v[j + 1] = key;
        }
    }
    void selection_sort(vector<int> &v)
    {
        if (v.size() > 1)
        {
            int min_index = 0, Start = 0, min = v[0];
            while (Start < v.size() - 1)
            {
                for (int i = Start; i < v.size(); i++)
                {
                    if (v[i] < min)
                    {
                        min = v[i];
                        min_index = i;
                    }
                }
                swap(v[min_index], v[Start]);
                Start++;
                min_index = Start;
                min = v[Start];
            }
        }
    }
    void bubble_sort(vector<int> &v)
    {
        for (int i = v.size() - 1; i > 0; i--)
        {
            int key = i;
            for (int j = 0; j < i; j++)
            {
                if (v[j] > v[key])
                {
                    key = j;
                }
            }
            swap(v[i], v[key]);
        }
    }
    void merge(vector<int> &v, int l, int m, int r)
    {
        if (v.size() > 1)
        {
            vector<int> lv;
            vector<int> rv;
            int len1 = m - l;
            int len2 = r - m;
            for (int i = 0; i < len1; i++)
            {
                lv.push_back(v[i + l]);
            }
            for (int i = 0; i < len2; i++)
            {
                rv.push_back(v[i + m]);
            }
            lv.push_back(INT_MAX);
            rv.push_back(INT_MAX);
            int j = 0, k = 0, pos = l;
            for (int i = l; i < r; i++)
            {
                if (lv[j] <= rv[k])
                    v[i] = lv[j++];
                else
                    v[i] = rv[k++];
            }
        }
    }

    void merge_sort(vector<int> &v, int l, int r)
    {
        if (r - l > 1)
        {
            int middle = (l + r) / 2;
            merge_sort(v, l, middle);
            merge_sort(v, middle, r);
            merge(v, l, middle, r);
        }
    }
    void quick_sort(vector<int> &v, int low, int high)
    {
        if (low < high)
        {
            int q = partition(v, low, high);
            quick_sort(v, low, q);
            quick_sort(v, q + 1, high);
        }
    }
    void counting_sort(vector<int> &v)
    {
        if (v.size() > 0)
        {
            int max = find_max(v);
            vector<int> auxiliary, new_v;
            for (int i = 0; i <= max; i++)
                auxiliary.push_back(0);
            for (int i = 0; i < v.size(); i++)
            {
                auxiliary[v[i]]++;
            }
            for (int i = 1; i < auxiliary.size(); i++)
            {
                int sum = auxiliary[i - 1];
                auxiliary[i] += sum;
            }
            for (int i = 0; i < v.size(); i++)
            {
                new_v.push_back(0);
            }
            for (int i = v.size() - 1; i >= 0; i--)
            {
                new_v[auxiliary[v[i]] - 1] = v[i];
                auxiliary[v[i]]--;
            }
            v = new_v;
        }
    }
    void radix_sort(vector<int> &v)
    {
        int max = find_max(v);
        int digits = count_digits(max);
        vector<int> new_v;
        for (auto ele : v)
            new_v.push_back(ele);
        for (int i = 0; i < digits; i++)
        {
            vector<int> auxiliary;
            for (int k = 0; k < 10; k++)
                auxiliary.push_back(0);
            for (int j = 0; j < v.size(); j++)
            {
                int tmp = v[j] / pow(10, i);
                int digit = tmp % 10;
                auxiliary[digit]++;
            }
            for (int j = 1; j < auxiliary.size(); j++)
                auxiliary[j] += auxiliary[j - 1];
            for (int j = v.size() - 1; j >= 0; j--)
            {
                int tmp = v[j] / pow(10, i);
                int digit = tmp % 10;
                new_v[auxiliary[digit] - 1] = v[j];
                auxiliary[digit]--;
            }
            v = new_v;
        }
    }
    int partition(vector<int> &v, int low, int high)
    {
        int pivot = v[(low + high) / 2];
        int i = low - 1;
        int j = high + 1;
        while (true)
        {
            while (v[++i] < pivot)
                ;
            while (v[--j] > pivot)
                ;
            if (i < j)
            {
                swap(v[i], v[j]);
            }
            else
                return j;
        }
    }
    int find_max(vector<int> v)
    {
        if (v.size() > 0)
        {
            int max = v[0];
            for (auto ele : v)
            {
                if (ele > max)
                    max = ele;
            }
            return max;
        }
        else
            return -1;
    }
    int count_digits(int num)
    {
        if (num == 0)
            return 1;
        else
        {
            int digit = 0;
            while (num > 0)
            {
                num /= 10;
                digit++;
            }
            return digit;
        }
    }
};
