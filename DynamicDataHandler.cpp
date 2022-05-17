#include "DynamicDataHandler.h"
DynamicDataHandler::DynamicDataHandler(std::string name) {
    maxRow = 0;
    filename = name + ".csv";
}

void DynamicDataHandler::Push(int column, long long data) {
    if (column >= columns.size()) {
        columns.push_back(std::vector<long long>());
    }
    int s = columns.at(column).size();
    if ( s > maxRow) maxRow = s;
    columns.at(column).push_back(data);
}

void DynamicDataHandler::Write() {
    std::ofstream fh;
    // Trunc overwrites existing data
    fh.open(filename, std::ofstream::trunc);
    for (int r = 0; r < maxRow; r++) {
        for (int c = 0; c < columns.size(); c++) {
            fh << std::to_string(columns[c][r]) << ",";
        }
        fh << "\n";
    }
    fh.close();
}