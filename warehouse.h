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

namespace cs3505{

  class warehouse{

    //ADD FRIEND CLASS HERE(WHEREVER MAIN IS SO IT CAN ACCESS VARIABLES)


  private:
    warehouse(const std::string & name);  // Constructor

    void receive(string upc, int quantity);
    void request(string upc, int quantity);
    void end_of_day();



  };
}
#endif


