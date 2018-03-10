/*
 * This warehouse class is used to build warehouses for the Fooditem 
 *   storage.
 *
 * Jeremy Johnson, Al May
 * CS3505 - Spring 2018
 */


#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include<string>
#include "food_order.h"
#include<map>


class warehouse
{
  
  //ADD FRIEND CLASS HERE(WHEREVER MAIN IS SO IT CAN ACCESS VARIABLES)
  
  
 private:
  std::string name;
  long long request_quantity;
  std::map<std::string, long long> request_map;
  //std::map<std::set<food_order>> inventory;
  
 public:
  
  warehouse(std::string name);  // Constructor
  
  void receive(std::string upc, long long q);
  void request(std::string upc, long long q);
  void end_of_day();
};
#endif


