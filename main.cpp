#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

void sort_vector(vector<double> &dvec)
{
    sort(dvec.begin(), dvec.end());
}

void print_list(vector<double> &dvec)
{
    size_t i = dvec.size();

    if (i % 2)
    {
        for (size_t ind = 0; ind < i; ++ind)
        {
            if (ind == (i / 2) + 1)
                cout << "\"" << dvec[ind] << "\""
                     << " ";
            else
                cout << dvec[ind] << " ";
        }
    }
    else
    {
        for (size_t ind = 0; ind < i; ++ind)
        {
            if ((ind == (i / 2)) || (ind == (i / 2) - 1))
                cout << "\"" << dvec[ind] << "\""
                     << " ";
            else
                cout << dvec[ind] << " ";
        }
    }

    cout << "\n";
}

bool check_list(vector<double> &dvec)
{
    for (auto &a : dvec)
    {
        if ((a < (-70)) || (a > 2'080'000'000))
            return false;
    }

    return true;
}

void print_median(vector<double> &dvec)
{
    int i = dvec.size();

    if (i >= 2)
    {
        if (dvec.size() % 2)
        {
            cout << "MEDIAN is " << dvec[(i / 2) + 1];
        }
        else
        {
            double median = (dvec[i / 2] + dvec[(i / 2) - 1]) / 2;
            cout << "MEDIAN is " << median;
        }
    }
    else if (i == 1)
    {

        cout << "MEDIAN is " << dvec[0];
    }
    else
    {
        cout << "MEDIAN is " << 0;
    }

    cout << "\n";
}

int main()
{
    ifstream fin;

    fin.open("sample.txt");
    string line;
    //cout << fin.is_open();

    vector<double> dvec;
    while (fin)
    {

        // Read a Line from File
        getline(fin, line);

        std::replace(line.begin(), line.end(), ',', ' ');
        stringstream str(line);
        double dval{};
        while (str >> dval)
        {
            //cout << dval << ":";
            dvec.push_back(dval);
        }
    }

    sort_vector(dvec);
    if (!check_list(dvec))
    {
        cerr << "Error Out of range \n";
        return EXIT_FAILURE;
    }
    print_list(dvec);
    print_median(dvec);

    fin.close();

    return EXIT_SUCCESS;
}
