#include <iostream>
#include <vector>
#include "wagon.h"
#include "train.h"

int main() {
    std::vector<Train> trains;

    Wagon w1, w2, w3;
    w1.init(50, 25.5);
    w2.init(40, 30.0);
    w3.init(45, 20.0);

    Train t1, t2, t3, t4, t5;
    t1.init(w1, w2, w3, 80, 60, 90, "expressccc");
    t2.init(w1, w2, w3, 70, 50, 80, "fasttrain");
    t3.init(w1, w2, w3, 90, 70, 85, "cccsuper");
    t4.init(w1, w2, w3, 60, 40, 75, "localtrain");
    t5.init(w1, w2, w3, 85, 65, 95, "anotherccc");

    trains.push_back(t1);
    trains.push_back(t2);
    trains.push_back(t3);
    trains.push_back(t4);
    trains.push_back(t5);

    for (auto& train : trains) {
        std::string name = train.getTrainName();
        if (name.length() >= 5) {
            name.replace(1, 4, "aa");
        }
        else if (name.length() > 1) {
            name.replace(1, name.length() - 1, "aa");
        }
        train.setTrainName(name);
    }

    std::string concatenated;
    for (const auto& train : trains) {
        if (train.getTrainName().find("ccc") != std::string::npos) {
            concatenated += train.getTrainName() + " ";
        }
    }

    if (!concatenated.empty()) {
        trains[0].setTrainName(concatenated);
    }

    trains[0].display();

    return 0;
}