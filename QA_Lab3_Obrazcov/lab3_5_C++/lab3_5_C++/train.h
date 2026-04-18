#pragma once
#ifndef TRAIN_H_
#define TRAIN_H_

#include "wagon.h"
#include <string>

class Train {
public:
    void init(Wagon w1, Wagon w2, Wagon w3,
        int fillPercent1, int fillPercent2, int fillPercent3,
        std::string trainName);
    void read();
    void display();
    double actualRevenue();
    Wagon minExpectedRevenueWagon();
    Wagon getWagon1();
    Wagon getWagon2();
    Wagon getWagon3();
    std::string getTrainName() const;
    void setTrainName(std::string name);

private:
    Wagon wagon1;
    Wagon wagon2;
    Wagon wagon3;
    int fillPercent1;
    int fillPercent2;
    int fillPercent3;
    std::string trainName;
};

#endif