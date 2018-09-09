#include "BrownRobinson.h"

using namespace std;

BrownRobinson::BrownRobinson(std::array<std::array<int, height>, width> _matrix, float _e) :
  matrix(_matrix),
  index(1),
  aStrategy(1),
  bStrategy(1),
  aPrize(),
  bLoss(),
  aMixedStrategy(),
  bMixedStrategy(),
  vLower(0),
  vUpper(0),
  vAverage(0),
  e(_e)
{}

vector<vector<float>> BrownRobinson::calculate()
{
	float delta = 1 + e;
	cout.setf(ios::fixed);
	
  vector<vector<float>> result;

	do
	{
		countPrize();
		countLoss();
		aMixedStrategy[aStrategy - 1]++;
		bMixedStrategy[bStrategy - 1]++;

		cout << index << "\tX" << aStrategy << "\tY" << bStrategy << "\t|\t";

		for (int i = 0; i < width; i++)
		{
			cout << aPrize[i] << "\t";
		}
		cout << "|\t";

		for (int i = 0; i < height; i++)
		{
			cout << bLoss[i] << "\t";
		}
		cout << "|\t";

		aStrategy = findMaxPrizeIndex() + 1;
		bStrategy = findMinLossIndex() + 1;
		
		vUpper = aPrize[aStrategy - 1] / (float)index;
		vLower = bLoss[bStrategy - 1] / (float)index;
		vAverage = (vLower + vUpper) / 2.0;
		delta = vUpper - vLower;
		cout << setprecision(3);
		cout << vUpper << "\t" << vLower << "\t" << vAverage << "\t\t|\t" << delta << endl;
		index++;
    result.push_back({ vUpper, vLower, vAverage, delta });
  } while (delta > e);
	

	cout << "A mixed strategy (";
	
  for (int i = 0; i < width; i++)
	{
		aMixedStrategy[i] /= (float)index;
		cout << aMixedStrategy[i] << "  ";
	}
	cout << ")" << endl << "B mixed strategy (";
	
  for (int i = 0; i < height; i++)
	{
		bMixedStrategy[i] /= (float)index;
		cout << bMixedStrategy[i] << "  ";
	}
	cout << ")" << endl;
	
  return result;
}

void BrownRobinson::countPrize()
{
	for (int i = 0; i < width; i++)
	{
		aPrize[i] += matrix[i][bStrategy - 1];
	}

}

void BrownRobinson::countLoss()
{
	for (int i = 0; i < height; i++)
	{
		bLoss[i] += matrix[aStrategy - 1][i];
	}
}

int BrownRobinson::findMaxPrizeIndex()
{
	int maxPrize = aPrize[0];
	int maxPrizeIndex = 0;
	int counter = 0;
	for (int i = 0; i < width; i++)
	{
		if (aPrize[i] > maxPrize)
		{
			maxPrize = aPrize[i];
			maxPrizeIndex = i;
			counter++;
		}
		else if (aPrize[i] == maxPrize)
			counter++;
	}

	if (counter > 1)
	{
		srand(time(0));
		int tempCounter = rand() % counter;
		for (int i = 0; (i < width) && (tempCounter > 0) ; i++)
		{
			if (aPrize[i] == maxPrize)
			{
				maxPrizeIndex = i;
				tempCounter--;
			}
		}

	}
	return maxPrizeIndex;
}

int BrownRobinson::findMinLossIndex()
{
	int minLoss = bLoss[0];
	int minLossIndex = 0;
	int counter = 0;
	for (int i = 0; i < height; i++)
	{
		if (bLoss[i] < minLoss)
		{
			minLoss = bLoss[i];
			minLossIndex = i;
			counter = 1;
		}
		else if (bLoss[i] == minLoss)
			counter++;
	}

	if (counter > 1)
	{
		srand(time(0));
		int tempCounter = rand() % counter;
		for (int i = 0; (i < width) && (tempCounter > 0); i++)
		{
			if (bLoss[i] == minLoss)
			{
				minLossIndex = i;
				tempCounter--;
			}
		}

	}
	return minLossIndex;
}
