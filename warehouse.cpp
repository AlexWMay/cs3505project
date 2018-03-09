/*
 * This class represents a warehouse.  It contains the warehouse inventory,
 *   and funcions to receive, evaluate requests and end of day needs.
 *
 * Jeremy Johnson, Al May
 *   CS3505 - Spring 2018
 */

#include <string>
#include <iostream>
#include "warehouse.h"

namespace cs3505
{

  std::string name;

  cs3505::warehouse::warehouse(std::string _name)
  {
    name = _name;
    

    //INSERT LOOP(or iteration) TO SET ALL OF THE AMOUNTS IN THE 
    //    REQUEST_MAP(using the item list) TO ZERO.
  };

  void cs3505::warehouse::receive (std::string upc, long long q)
  {


  }

  /*
   * Takes a requested value and adds the quantity to whatever quantity
   *     has already been requested for that day and stores it back into
   *     the request_map.
   */
  void cs3505::warehouse::request(std::string upc, long long q)
  {
    long long temp = request_map.at(upc);
    request_map.insert(std::pair<std::string, long long>(upc, temp));
  }

  void cs3505::warehouse::end_of_day()
  {



    // Set request qantity to zero after requests are filled.

  }

}
