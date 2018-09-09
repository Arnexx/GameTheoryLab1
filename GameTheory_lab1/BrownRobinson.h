//Artyukhov Vlad IU8-104

#pragma once
#include <cstring>
#include <cstdlib>
#include <array>
#include <vector>
#include <ctime>
#include <iostream>
#include <iomanip>

#define height 3
#define width 3

class BrownRobinson
{

private:
	int	index;
	int	aStrategy;
	int	bStrategy;
  std::array<int, width>             aPrize;
  std::array<int, height>	           bLoss;
  std::array<float, height>          aMixedStrategy;
  std::array<float, width>           bMixedStrategy;
  std::array<std::array<int, height>, width>  matrix;
	float	vLower;
	float	vUpper;
	float	vAverage;
  float	e;                        // error delta

public:
	BrownRobinson(std::array<std::array<int, height>, width> matrix ,float _e);
	std::vector<std::vector<float>> calculate();

private:
	void countPrize();
	void countLoss();
	int  findMaxPrizeIndex();
	int  findMinLossIndex();
};

