///
/// @file combinationGenerator.h
/// @author Jxtopher
/// @version 1
/// @date 2019
/// @brief see : https://fr.wikipedia.org/wiki/Arrangement_avec_r%C3%A9p%C3%A9tition
///

#ifndef JXTOPHER_COMBINATIONGENERATOR_H
#define JXTOPHER_COMBINATIONGENERATOR_H

#include <iostream>

using namespace std;

namespace jxtopher {

class CombinationGenerator {
  public:
	void operator()(const unsigned int nbDigit, unsigned int len_string, void (*f)(unsigned int, unsigned int *, unsigned int)) {
		unsigned int nbCall = 0;
		unsigned int *string = new unsigned int[len_string];

		for (unsigned int i = 0; i < len_string; i++)
			string[i] = 0;

		bool x = false;
		unsigned int i = 0;

		f(nbCall++, string, len_string);

		while (string[i] == (nbDigit - 1)) {
			i++;
			x = true;
		}

		while (i < (len_string)) {
			string[i]++;

			if (x) {
				for (unsigned int j = 0; j < i; j++)
					string[j] = 0;
				i = 0;
			}

			f(nbCall++, string, len_string);

			while (string[i] == (nbDigit - 1)) {
				i++;
				x = true;
			}
		}

		delete[] string;
	}

	static void f(unsigned int nbCall, unsigned int *string, unsigned int size) {
		std::cout << nbCall << " ";
		for (unsigned int i = 0; i < size; i++)
			std::cout << string[i] << " ";
		std::cout << std::endl;
	}
};

} // namespace jxtopher

#endif
