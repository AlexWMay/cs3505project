

#include "food_list.h"

food_list::food_list()
{
  
}

void food_list::add(std::string upc, std::string name)
{
  food_names.insert(std::pair<std::string, std::string>(upc, name));
}


std::string food_list::get_name(std::string upc)
{
  return food_names[upc];
}
