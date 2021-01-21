#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

void permutation(string word);
int factorial(int n);

int main(int argc, char *argv[])
{
    // cout << argc << " " << argv << endl;

    // for (int i = 0; i < argc; i++)
    // {
    //     cout << argv[i] << endl;
    // }

    string word = "";
    if (argc >= 2)
    {
        word = string(argv[1]);
        // cout << "word: " << word << endl;
        permutation(word);
    }

    return 0;
}

int factorial(int n)
{
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

string exclude_char(string text, int index)
{
    string tmp = "";
    for (int i = 0; i < (int)text.length(); i++)
    {
        if (i != index)
        {
            tmp += text[i];
        }
    }
    return tmp;
}

void print_permutation(string word, string tmp)
{
    if (tmp == "")
    {
        cout << word << endl;
        return;
    }

    for (int i = 0; i < (int)tmp.length(); i++)
    {
        string a(word);
        a += tmp[i];
        print_permutation(a, exclude_char(tmp, i));
    }
}

void get_index_array(int n, int length, int* array)
{
    int l = length;
    for (int i = 0; i < length; i++)
    {
        array[i] = n % l;
        l--;
        // cout << array[i];
    }

    // cout << endl;
}

string make_text_of_order(string text, int *order)
{
    int l = (int)text.length();
    string tmp = "";
    for (int i = 0; i < l; i++)
    {
        tmp += text[order[i]];
        text = exclude_char(text, order[i]);
    }
    return tmp;
}

void permute_linear(string text)
{
    int n = (int)text.length();
    int total = factorial(n);

    for (int i = 0; i < total; i++)
    {
        int array[n];
        get_index_array(i, n, array);
        string word = make_text_of_order(text, array);
        cout << word << endl;
    }
}

void permutation(string word)
{
    // print_permutation("", word);
    permute_linear(word);
}