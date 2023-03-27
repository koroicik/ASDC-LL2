#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Item {
    int key;
    std::string value;
};

void readDataFromFile(std::vector<Item>& data, const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return;
    }
    int key;
    std::string value;
    while (infile >> key >> value) {
        data.push_back({ key, value });
    }
    infile.close();
}

int main() {
    std::vector<Item> data;
    readDataFromFile(data, "data.txt");
    // теперь данные находятся в массиве data
    return 0;
}
