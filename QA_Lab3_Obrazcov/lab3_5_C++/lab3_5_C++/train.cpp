#include <iostream>
#include <limits>
#include "train.h"

void Train::init(Wagon w1, Wagon w2, Wagon w3,
    int fillPercent1, int fillPercent2, int fillPercent3,
    std::string trainName) {
    this->wagon1 = w1;
    this->wagon2 = w2;
    this->wagon3 = w3;
    this->fillPercent1 = fillPercent1;
    this->fillPercent2 = fillPercent2;
    this->fillPercent3 = fillPercent3;
    this->trainName = trainName;
}

void Train::read() {
    std::cout << "Enter train name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, this->trainName);

    std::cout << "Wagon 1" << std::endl;
    this->wagon1.read();
    std::cout << "Enter fill percentage for wagon 1: ";
    std::cin >> this->fillPercent1;

    std::cout << "Wagon 2" << std::endl;
    this->wagon2.read();
    std::cout << "Enter fill percentage for wagon 2: ";
    std::cin >> this->fillPercent2;

    std::cout << "Wagon 3" << std::endl;
    this->wagon3.read();
    std::cout << "Enter fill percentage for wagon 3: ";
    std::cin >> this->fillPercent3;
}

void Train::display() {
    std::cout << "Train name: " << this->trainName << std::endl;
    std::cout << "Wagon 1 (" << this->fillPercent1 << "% full): ";
    this->wagon1.display();
    std::cout << "Wagon 2 (" << this->fillPercent2 << "% full): ";
    this->wagon2.display();
    std::cout << "Wagon 3 (" << this->fillPercent3 << "% full): ";
    this->wagon3.display();
    std::cout << "Actual revenue: " << actualRevenue() << std::endl;
}

double Train::actualRevenue() {
    double revenue = 0;
    revenue += wagon1.expectedRevenue() * (fillPercent1 / 100.0);
    revenue += wagon2.expectedRevenue() * (fillPercent2 / 100.0);
    revenue += wagon3.expectedRevenue() * (fillPercent3 / 100.0);
    return revenue;
}

Wagon Train::minExpectedRevenueWagon() {
    double rev1 = wagon1.expectedRevenue();
    double rev2 = wagon2.expectedRevenue();
    double rev3 = wagon3.expectedRevenue();

    if (rev1 <= rev2 && rev1 <= rev3) {
        return wagon1;
    }
    else if (rev2 <= rev3) {
        return wagon2;
    }
    else {
        return wagon3;
    }
}

Wagon Train::getWagon1() {
    return wagon1;
}

Wagon Train::getWagon2() {
    return wagon2;
}

Wagon Train::getWagon3() {
    return wagon3;
}

std::string Train::getTrainName() const {
    return trainName;
}

void Train::setTrainName(std::string name) {
    trainName = name;
}