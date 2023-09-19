#include <iostream>
#include "simple_class.h"

using namespace simple_class;

void Dice::print(std::ostream &c) //вывод состояния игральной кости (переадча потока в аргументы)
{
            c << "Current value of dice: " << this->value << std::endl;
            for (int i = 0; i<6; i++)
            {
                c << "Probability of dropping value " << (i+1) << ": " << this->probabilities[i] << std::endl;
            }
}

void Dice::set_state(std::istream &in, std::ostream &out) //ввод состояния класса через входной поток (передача потока в аргументы функции)
{
                try
                {
                	out << "Enter dropped value of dice:\n";
                	int val = getNum<int>(std::cin, std::cout,1,6);
                	this->value = val;
                	double sum = 1.0;
                	while (sum > 0.0)
                	{
                		sum = 1.0;
                		for (int i=0; i<6; i++)
                		{
                        		out << "Enter probability of dropping number #" << (i+1) << ":\n";
                        		double cur = getNum<double>(std::cin, std::cout, 0,sum);
                        		this->probabilities[i] = cur;
                        		sum -= cur;
                		}
                		if (sum > 0.0)
                		{
                        		out << "Sum of probabilities must be equal to 1.0. Repeat, pleace\n";
                		}
                	}
                }
                catch(...)
                {
                        throw;
                }
}

void Dice::generate_random_value() //генерация рандомного значения игральной кости с учетом вероятностей
{
            srand(time(nullptr));
            int p = rand()%101;
            double cnt = (int) (this->probabilities[0]*100);
            for (int i = 0; i<6; i++)
            {
                if (this->probabilities[i] != 0 && cnt > p)
                {
                        this->value = i + 1;
                        break;
                }
                else if (i < 5)
                {
                        cnt += (int) (this->probabilities[i+1]*100);
                }
            }
}

bool Dice::operator == (const Dice &other) const //сравнивать только значения без вероятностей
{
                if (this->value == other.value)
                {
                        for (int i=0; i<6; i++)
                        {
                                if (this->probabilities[i] != other.probabilities[i])
                                        return false;
                        }
                        return true;
                }
                return false;
}

std::string Dice::ascii_art() //формирование строки(!) и ее вывод (должна возвращать string)
{
                std::string s = ".-------.|       |";
                if (this->value == 1)
                {
                        s += "|   *   |";
                }
                else if (this->value == 2)
                {
                        s += "|  **   |";
                }
                else if (this->value == 3)
                {
                        s += "|  ***  |";
                }
                else if (this->value == 4)
                {
                        s += "| ****  |";
                }
                else if (this->value == 5)
                {
                        s += "| ***** |";
                }
                else if (this->value == 6)
                {
                        s += "| ******|";
                }
                s += "|       |";
                s += "'-------'";
                return s;
}
