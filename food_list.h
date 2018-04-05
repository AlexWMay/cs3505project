



#ifndef FOOD_LIST_H
#define FOOD_LIST_H


#include <iostream>
#include <string>
#include "food_order.h"
#include <map>
#include <set>
#include <vector>
#include "boost/date_time/gregorian/gregorian.hpp" //include all types plus i/o
#include <boost/algorithm/string.hpp>

class food_list
{

 private:
  std::map<std::string, std::string> food_names;

 public:

  food_list();
  void add(std::string upc, std::string name);
std::string get_name(std::string upc);
  

};
#endif
