//Artyukhov Vlad IU8-104

#pragma once
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>

#define height 3
#define width 3



class BrownRobinson
{

private:
	int		index;
	int		aStrategy;
	int		bStrategy;
	int		aPrize[width];
	float   aMixedStrategy[height];
	int		bLoss[height];
	float   bMixedStrategy[width];
	float	vLower;
	float	vUpper;
	float	vAverage;
	float	e;					 // эпсилон ошибка
	int     matrix[height][width];

public:
	BrownRobinson();
	~BrownRobinson();

	void set_E(float value);
	void calculate();

private:
	void countPrize();
	void countLoss();
	int  findMaxPrizeIndex();
	int  findMinLossIndex();
};

