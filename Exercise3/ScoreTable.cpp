//
// Created by Kolio on 10/27/2026.
//

#include "ScoreTable.h"

ScoreTable::ScoreTable(int rows, int columns) {
    this->rows = rows;
    this->columns = columns;
    this->scoreTable = new double*[rows];
    for (int i = 0; i < rows; i++) {
        scoreTable[i] = new double[columns];
    }

}

ScoreTable::~ScoreTable() {
    for (int i = 0; i < rows; i++) {
        delete[] scoreTable[i];
    }
    delete[] scoreTable;
}

double & ScoreTable::at(int row, int column) {
    return scoreTable[row][column];
}

const double & ScoreTable::at(int row, int column) const {
    return scoreTable[row][column];
}

void ScoreTable::fillRow(int row, const double *score, int count) {
    if (row< 0 || row >= rows) {
        return;
    }
    int limit = (count <columns) ? count : columns;

    for (int j = 0; j < limit; j++) {
        this->at(row,j) = score[j];
    }
}



