#include <iostream>
#include "simple_class.h"

using namespace simple_class;

int invite();
int D_Init (Dice &d);
int D_Random_Value (Dice &d);
int D_Generation_based_on_probabilities (Dice &d);
int D_Print (Dice &d);

int (*f[])(Dice&) = {NULL, D_Init, D_Random_Value, D_Generation_based_on_probabilities};

int main()
{
    int rc;
    Dice d;
    while (rc = invite())
	if (!f[rc](d))
		break;
    D_Print(d);
    std::cout<<"That's all. Good luck!\n";
}

int D_Print (Dice &d)
{
	try
	{
		d.print();
	}
	catch(...)
	{
		throw;
		return 0;
	}
	return 1;
}

int D_Generation_based_on_probabilities (Dice &d)
{
	try
	{
		d.generate_random_value();
	}
	catch(...)
	{
		throw;
		return 0;
	}
	return 1;
}

int D_Random_Value (Dice &d)
{
	try
	{
	 	d.set_random();
	}
	catch(...)
	{
		throw;
		return 0;
	}
	return 1;
}

int D_Init (Dice &d)
{
	try
	{
		d.set_state();
	}
	catch(...)
	{
		throw;
		return 0;
	}
	return 1;
}

int invite()
{
        std::cout << "Select one option:\n";
        std::cout << " 0. Quit\n";
        std::cout << " 1. Initialization with the side dropped out and probabilities of dropping sides:\n";
        std::cout << " 2. Initialization with the random side\n";
        std::cout << " 3. Generating a random value for a dice based on probability\n";
        std::cout << " 4. Compare two dices\n";
        std::cout << " 5. ASCII-art\n";
	int rc;
	try
	{
        	rc = getNum<int>(0,3);
	}
	catch(...)
	{
		throw;
		return 0;
	}
        return rc;
}
