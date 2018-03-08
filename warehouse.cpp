/*
 * This class represents a warehouse.  It contains the warehouse inventory,
 *   and funcions to receive, evaluate requests and end of day needs.
 *
 * Jeremy Johnson, Al May
 *   CS3505 - Spring 2018
 */

namespace cs3505{

  string name;

  warehouse(string _name){
    name = _name;
    

    //INSERT LOOP(or iteration) TO SET ALL OF THE AMOUNTS IN THE 
    //    REQUEST_MAP(using the item list) TO ZERO.
  };

  void receive(string upc, long long q){


  }

  /*
   * Takes a requested value and adds the quantity to whatever quantity
   *     has already been requested for that day and stores it back into
   *     the request_map.
   */
  void request(string upc, long long q){
    long long temp = request_map.at(upc);
    request_map.insert(std::pair<std::string, long long>(upc, temp));
  }

  void end_of_day(){



    // Set request qantity to zero after requests are filled.

  }

}
