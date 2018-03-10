/*
 * This warehouse class is used to build warehouses for the Fooditem 
 *   storage.
 *
 * Jeremy Johnson, Al May
 * CS3505 - Spring 2018
 */


#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <string>
#include "food_order.h"
#include <map>
#include <set>
#include <vector>

class warehouse
{
  
  //ADD FRIEND CLASS HERE(WHEREVER MAIN IS SO IT CAN ACCESS VARIABLES)
  
  
 private:
  std::string name;
  long long request_quantity;
  std::map<std::string, long long> request_map;
  std::map<std::string, std::vector<food_order> > inventory;
  std::map<std::string, long long> received_items;
  std::map<std::string, long long> requested_items;
  
 public:
  
  warehouse(std::string _name);  // Constructor
  warehouse(const warehouse & other);
  
  void receive(std::string upc, long long q);
  void request(std::string upc, long long q);
  std::string end_of_day();
  std::string get_name();
};
#endif


