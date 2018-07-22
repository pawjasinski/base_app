#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include <iostream>
#include <string>
#include <cstdlib>
#include "sqlite3.h"

static int show(void *nothing, int argc, char **argv, char **colName);
void popBack(sqlite3 *db, int &i);
void showTable(sqlite3 *db);
void pushData(sqlite3 *db, int &i);
void closeBase(sqlite3 *db);

#endif /* FUNCTIONS_H_ */
