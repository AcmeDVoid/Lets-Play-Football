#ifndef MYHEADER_H
#define MYHEADER_H
#include "StadiumList.h"
#include <QDebug>
#include <algorithm>
#include <QVector>
#include <QMessageBox>
#include <QWidget>
#include <QTableWidget>

// ReadFromFile function
// This function takes the file name QString typed and a List as its parameters
// The function will create a list from reading the file
void ReadFromFile(QString fileName, StadiumList &aMap);

#endif // MYHEADER_H
