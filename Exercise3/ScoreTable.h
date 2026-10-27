//
// Created by Kolio on 10/27/2026.
//

#ifndef LAB3_SCORETABLE_H
#define LAB3_SCORETABLE_H


class ScoreTable {

private:
    double** scoreTable;
    int rows;
    int columns;

public:
    ScoreTable(int rows, int columns);
    ~ScoreTable();
    [[nodiscard]]double& at(int row, int column);
    [[nodiscard]]const double& at(int row, int column) const;
    void fillRow(int row, const double* score, int count);
    friend void compareRows(const ScoreTable& scoreTable,int row1,int row2);


};


#endif //LAB3_SCORETABLE_H
