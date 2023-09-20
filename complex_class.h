#ifndef COMPLEX_CLASS
#define COMPLEX_CLASS

#include <iostream>
#include <cstring>
#include "simple_class.h"

namespace complex_class
{
    /*template <class T>
    T getNum(std::istream &in, std::ostream &out, T min = std::numeric_limits<T>::min(), T max = std::numeric_limits<T>>    {
        T a;
        while (true)
        {
            in >> a;
            if (in.eof()) //конец файла
                throw std::runtime_error("Failed to read number: EOF");
            else if (in.bad()) //невосстановимая ошибка входного потока
                throw  std::runtime_error(std::string("Failed to read number") + strerror(errno));
            else if (in.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std:: cout<<"You are wrong, repeat please!"<<std::endl;
            }
            else if (a>=min && a<=max)
                return a;
            else
                out << "You are wrong! Repeat, please\n";
        }
    }*/

	class Dices
	{
		private:
		 	simple_class::Dice *arr; //массив игральных костей
			int size; //размер массива
	};
}

#endif
