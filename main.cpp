// Authors: Alex May and Jeremy Johnson.
// Project: Assigment 4. Transaction Report. CS3505.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>


void end_day_for_every_warehouse();

int main()
{
    std::ifstream file( "data1.txt" );

    std::string line;
    while (std::getline(file, line))
      {
	std::istringstream iss(line);
        
	std::string indicator;
	iss >> indicator;
	if(indicator == "FoodItem")
	  {
	    
	  }
	else if(indicator == "Warehouse")
	  {
	    warenum++;
	  }
	else if(indicator == "Start")
	  {
	    startnum++;
	  }
	else if(indicator == "Receive:")
	  {
	    recnum++;
	  }
	else if(indicator == "Request:")
	  {
	    reqnum++;
	  }
	else if(indicator == "Next")
	  {
	    nexnum++;
	  }
	else if(indicator == "End")
	  {
	    endnum++;
	  }
	linenum++;
      }

    std::cout << << std::endl;
    
    return 0;
}

void end_day_for_every_warehouse()
{

}
