/**
 *  @file main.cpp
 *
 *  @date 2-jan-2010
 *  @author Ives van der Flaas
 */

#include <iostream>
#include "univhac.h"

int main()
{
	Univhac univhac;

	int foo = 15;

	for(int i = 0; i < 10000; i++)
		foo *= foo;

	std::cout << "10 000 multiplications take " << univhac.poll() << " seconds. " << std::endl;

	return 0;

}
