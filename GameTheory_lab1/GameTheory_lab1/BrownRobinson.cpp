#include "BrownRobinson.h"
using namespace std;


BrownRobinson::BrownRobinson()
{
	index = 1;
	aStrategy = 1;
	bStrategy = 1;
	e = 0.8;

	int tempMatrix[height][width] = { {1, 17, 18}, {14, 6, 16}, {14, 14, 13} };
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			matrix[i][j] = tempMatrix[i][j];
		}
	}

	memset(aPrize, 0, sizeof(int) * width);
	memset(aMixedStrategy, 0, sizeof(int) * width);
	memset(bLoss, 0, sizeof(int) * height);
	memset(bMixedStrategy, 0, sizeof(int) * height);


	
}


BrownRobinson::~BrownRobinson()
{
}

void BrownRobinson::set_E(float value)
{
	this->e = value;
}

void BrownRobinson::calculate()
{
	float delta = 1 + e;
	cout.setf(ios::fixed);
	
	while (delta > e)
	{
		countPrize();
		countLoss();
		aMixedStrategy[aStrategy - 1]++;
		bMixedStrategy[bStrategy - 1]++;

		cout << index << "    X" << aStrategy << "    Y" << bStrategy << "    |    ";

		for (int i = 0; i < width; i++)
		{
			cout << aPrize[i] << "    ";
		}
		cout << "|    ";

		for (int i = 0; i < height; i++)
		{
			cout << bLoss[i] << "    ";
		}
		cout << "|    ";

		aStrategy = findMaxPrizeIndex() + 1;
		bStrategy = findMinLossIndex() + 1;
		
		vUpper = aPrize[aStrategy - 1] / (float)index;
		vLower = bLoss[bStrategy - 1] / (float)index;
		vAverage = (vLower + vUpper) / 2.0;
		delta = vUpper - vLower;
		cout << setprecision(3);
		cout << vUpper << "    " << vLower << "    " << vAverage << "    |    " << delta << endl;
		index++;
	}
	index--;
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
	cout << ")";
	
}

void BrownRobinson::countPrize()
{
	for (int i = 0; i < width; i++)
	{
		aPrize[i] += matrix[bStrategy - 1][i];
	}

}

void BrownRobinson::countLoss()
{
	for (int i = 0; i < height; i++)
	{
		bLoss[i] += matrix[i][aStrategy - 1];
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
			counter = 1;
		}
		else if (aPrize[i] = maxPrize)
			counter++;
	}

	if (counter > 1)
	{
		srand(time(0));
		int tempCounter = rand() % counter;
		for (int i = 0; (i < width) && (tempCounter > 0) ; i++)
		{
			if (aPrize[i] = maxPrize)
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
		else if (bLoss[i] = minLoss)
			counter++;
	}

	if (counter > 1)
	{
		srand(time(0));
		int tempCounter = rand() % counter;
		for (int i = 0; (i < width) && (tempCounter > 0); i++)
		{
			if (bLoss[i] = minLoss)
			{
				minLossIndex = i;
				tempCounter--;
			}
		}

	}
	return minLossIndex;
}
