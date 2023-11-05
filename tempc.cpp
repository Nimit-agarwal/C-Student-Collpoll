#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    // Specify the path to the CSV file
    const std::string csvFileName = "attendences.csv"; // Change this to your CSV file's name

    // Open the CSV file for reading
    std::ifstream csvFile(csvFileName);

    if (!csvFile.is_open()) {
        std::cerr << "Error: Could not open the CSV file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(csvFile, line)) {
        // Use a stringstream to split the line into fields using a delimiter (e.g., comma)
        std::istringstream lineStream(line);
        std::string field;
        std::vector<std::string> fields;

        while (std::getline(lineStream, field, ',')) {
            fields.push_back(field);
        }

        // Print the fields from the CSV line
        for (const std::string& data : fields) {
            std::cout << data << " | ";
        }
        std::cout << std::endl;
    }

    // Close the CSV file
    csvFile.close();

    return 0;
}
