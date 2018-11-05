#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>

int main() {
    double median, mean = 0;

    //declare the vector
    std::vector<double> Data = {56, 32, -43, 23, 12, 93, 12, 56};

    //sort and print out the vector
    sort(Data.begin(), Data.end());

    std::cout << "Ordered sequence: ";
    for (double i : Data) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    //calculate and print out the mean
    for (double i : Data) {
        mean += i;
    }

    std::vector<double>::size_type Data_size;
    Data_size = Data.size();

    std::cout << "mean: " << (mean = mean / Data.size()) << std::endl;

    //calculate and print out the median
    if (Data_size % 2 == 0) {
        median = (Data[Data_size / 2] + Data[- 1 + Data_size / 2]) / 2;
    } else {
        median = Data[trunc(Data_size / 2)];
    }
    std::cout << "median: " << median << std::endl;

    //calculate the mode
    std::map<double, int> Data_count;

    for (double &i : Data) {
        if (Data_count.find(i) == Data_count.end()) {
            Data_count.insert(std::pair<double, int>(i, 1));
        }
        else {
            Data_count[i] += 1;
        }
    }

    //print the table value-frequency
    for (std::pair<double,int> i : Data_count) {
        std::cout << i.first << ": " << i.second <<std::endl;
    }

    {
        //MODE method 1:

        //decide the highest frequency value
        int Hfrquency = 0;
        for (std::pair<double, int> i : Data_count) {
            if (i.second > Hfrquency) {
                Hfrquency = i.second;
            }
        }

        //print the value with the highest frequency value
        std::cout << "mode: ";
        for (std::pair<double, int> i : Data_count) {
            if (i.second == Hfrquency) {
                std::cout << i.first << " ";
            }
        }
        std::cout << "(method 1)" << std::endl;
    }
    {
        // MODE, method 2:

        //calculate the mode:
        std::vector<double> mode;
        int Hfrquency = 0;
        for (std::pair<double, int> i : Data_count) {
            if (i.second > Hfrquency) {
                mode.clear();
                Hfrquency = i.second;
                mode.push_back(i.first);
            }
            else if (i.second == Hfrquency){
                mode.push_back(i.first);
            }
            else continue;
        }

        //print the mode:
        std::cout << "mode: ";
        for (double m : mode) {
            std::cout << m << " ";
        }
        std::cout << "(method 2)" << std::endl;
    }
    return 0;
}