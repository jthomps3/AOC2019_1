#pragma region Description

/*
	Author: Jon Thompson
	Dates: 3/10/2020 - IP
	Title: Advent of Code, 2019, Day 1
		   "The Tyranny of the Rocket Equation"
	Description: https://adventofcode.com/2019/day/1
	
	Part One:

	This program is used to determine the total amount
	of fuel required for all components in the given
	scenario.

	It will receive each components mass by reading
	the included .txt file (ACO2019_1In.txt).  Output
	will be displayed in a console.

	Part Two:

	Fuel itself requires fuel.  Best described by the
	given example:

	At first, a module of mass 1969 requires 654 fuel. 
	Then, this fuel requires 216 more fuel (654 / 3 - 2). 
	216 then requires 70 more fuel, which requires 21 fuel, 
	which requires 5 fuel, which requires no further fuel. 
	So, the total fuel required for a module of mass 
	1969 is 654 + 216 + 70 + 21 + 5 = 966.
*/

#pragma endregion

#pragma region Libraries

#include <iostream>
#include <fstream>
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;

#pragma endregion

unsigned int fuelRequired(unsigned int componentMass);

void main()
{
	ifstream fin("AOC2019_1In");
	if (fin.is_open())
	{
		unsigned int componentMass;
		unsigned int totalFuelNeeded = 0;

		while (!fin.eof())
		{
			fin >> componentMass;
			totalFuelNeeded += fuelRequired(componentMass);
		}
		cout << "Total fuel required: " << totalFuelNeeded << endl;
	}

	else
		cout << "Input file not found ... Aborting\n";

	if (fin.is_open())
		fin.close();
}


unsigned int fuelRequired(unsigned int componentMass)
{
	unsigned int fuel = 0;
	unsigned int currentMass = componentMass;
	
	while (currentMass >= 6)	// 6 / 3 - 2 = 0, so loop should not go any further
	{
		fuel += currentMass / 3 - 2;
		currentMass = currentMass / 3 - 2;
	}
	
	return fuel;
}