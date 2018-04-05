

#include <iostream>
#include <sstream>
#include "underfilled.h"

underfilled::underfilled()
{
  
}


void underfilled::add(std::string upc)
{
  underfilled_set.insert(upc);
}

void underfilled::clear()
{
  underfilled_set.clear();
}

void underfilled::print_underfilled(std::string day, food_list & list)
{
  std::set<std::string>::iterator it;
  for(it = underfilled_set.begin(); it != underfilled_set.end(); ++it)
    {
      std::cout << day << " " << *it << " " << list.get_name(*it);
    }
}
