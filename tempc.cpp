#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    const char* filename = "attendences.csv";

    std::ofstream ofs;
    ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    std::cout << "CSV file cleared successfully!" << std::endl;

    return 0;
}
