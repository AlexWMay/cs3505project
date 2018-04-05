

#ifndef UNDERFILLED_H
#define UNDERFILLED_H

#include <iostream>
#include <string>
#include "food_order.h"
#include <map>
#include <set>
#include <vector>
#include "boost/date_time/gregorian/gregorian.hpp" //include all types plus i/o
#include <boost/algorithm/string.hpp>
#include "food_list.h"

class underfilled
{
  
 private:
std::set<std::string> underfilled_set;

 public:
underfilled();
void add(std::string upc);
void clear();
void print_underfilled(std::string day, food_list & list);

};
#endif
