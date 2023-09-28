#include <iostream>
#include "complex_class.h"
#include "simple_class.h"

using namespace complex_class;

int invite();
int D_Toss(Dices &d), D_Print(Dices &d), D_Toss_dice(Dices &d, int num), D_Add(Dices &d, simple_class::Dice &obj),
D_Removal(Dices &d, simple_class::Dice &obj), D_Sum(Dices &d), D_Find(Dices &d, int num), D_Ascii_art(Dices &d);

simple_class::Dice &D_Getting(Dices &d, int num);

int main()
{
	srand(time(nullptr));
	int rc;
	Dices g = 4;
	while (rc = invite())
	{
		switch(rc)
		{
			case 0:
				break;
			case 1:
			{
				D_Toss(g);
				break;
			}
			case 2:
			{
				std::cout << "Enter number of dice you want to toss:\n";
				int num = simple_class::getNum<int>(std::cin, std::cout, 0);
				D_Toss_dice(g, num);
				break;
			}
			case 3:
			{
				simple_class::Dice obj;
				obj.set_state(std::cin, std::cout);
				D_Add(g, obj);
				//obj.~Dice();
				break;
			}
			case 4:
			{
				simple_class::Dice obj_2;
				std::cout << "Enter value:\n";
				int val = simple_class::getNum<int>(std::cin, std::cout, 0);
				obj_2.set_val(val);
				D_Removal(g, obj_2);
				break;
			}
			case 5:
			{
				std::cout <<"Enter number of dice you want to get\n";
				int num = simple_class::getNum<int>(std::cin, std::cout, 0);
				simple_class::Dice &r = D_Getting(g, num);
				r.print(std::cout);
				break;
			}
			case 6:
			{
				int res = D_Sum(g);
				std::cout << res << "\n";
				break;
			}
			case 7:
			{
				std::cout << "Enter value you want to find in group of dices:\n";
				int val = simple_class::getNum<int>(std::cin, std::cout, 0);
				D_Find(g,val) ? std::cout<<"Present\n" : std::cout<<"Absent\n";
				break;
			}
			case 8:
			{
				D_Ascii_art(g);
				break;
			}
			case 9:
			{
				D_Print(g);
				break;
			}
			default:
				break;
		}
	}

	std::cout << "That's all, good luck!\n";
}

int D_Ascii_art (Dices &d)
{
	d.ascii_art();
	return 1;
}

int D_Find (Dices &d, int num)
{
	if (d.check(num))
		return 1;
	return 0;
}

simple_class::Dice &D_Getting (Dices &d, int num)
{
	return d[num-1];
}

int D_Sum(Dices &d)
{
	return d.sum();
}

int D_Removal (Dices &d, simple_class::Dice &obj)
{
	if (d -= obj)
		return 1;
	return 0;
}

int D_Add (Dices &d, simple_class::Dice &obj)
{
	if (d += obj)
		return 1;
	return 0;
}

int D_Toss_dice (Dices &d, int num)
{
	d(num);
	return 1;
}

int D_Toss(Dices &d)
{
	d();
	return 1;
}

int D_Print(Dices &d)
{
	d.print(std::cout);
	return 1;
}

int invite()
{
	std::cout << "0. Quit\n";
	std::cout << "1. Toss the dices\n";
	std::cout << "2. Toss dice with a given value\n";
	std::cout << "3. Add dice to group\n";
	std::cout << "4. Removal dice with given value from the group\n";
	std::cout << "5. Getting a dice from a group by its number\n";
	std::cout << "6. Counting the sum of points in a groop\n";
	std::cout << "7. Checking if a group has a dice with given value\n";
	std::cout << "8. ASCII-art\n";
	std::cout << "9. Print\n";
	int rc = simple_class::getNum<int>(std::cin, std::cout, 0, 9);
	return rc;
}
