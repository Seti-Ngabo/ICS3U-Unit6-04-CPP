// Copyright (c) 2019 St. Mother Teresa HS All rights reserved.
//
// Created by: Seti Ngabo
// Created on: Sept 2021
// This program print random numbers between 1 and 50 with the average

#include <iostream>
#include <random>
#include <iomanip>

template <int rows, int cols>
float randomAverage(int (&passedIn2DList)[rows][cols]) {
    // this function  accepst 2d arrays
    float finalSum = 0;
    int rowLine = sizeof(passedIn2DList)/sizeof(passedIn2DList[0]);
    int columnLine = sizeof(passedIn2DList[0])/sizeof(passedIn2DList[0][0]);


    for (size_t rowElement = 0; rowElement < rows; ++rowElement) {
        for (size_t columnElement = 0; columnElement < cols; ++columnElement) {
            finalSum += passedIn2DList[rowElement][columnElement];
        }
    }

    finalSum = finalSum / (rowLine * columnLine);

    return finalSum;
}

int main() {
    // This function uses 2d arrays

    int myRandoms;
    const int guessedInput1 = 3;
    const int guessedInput2 = 3;
    float finalAnswer;
    int a2DArray[guessedInput1][guessedInput2];

    for (int firstCounter = 0;
             firstCounter < guessedInput1;
             firstCounter++) {
        for (int secondCounter = 0;
                 secondCounter < guessedInput2;
                 secondCounter++) {
            std::random_device rseed;
            std::mt19937 rgen(rseed());
            std::uniform_int_distribution<int> idist(1, 50);
            myRandoms = idist(rgen);
            a2DArray[firstCounter][secondCounter]
            = myRandoms;
            std::cout << myRandoms << " ";
        }
        std::cout << "" << std::endl;
    }

    // call functions
    finalAnswer = randomAverage(a2DArray);

    // output
    std::cout << "" << std::endl;
    std::cout << std::fixed << std::setprecision(2)
    << finalAnswer << std::endl;

    std::cout << "\nDone." << std::endl;
}
