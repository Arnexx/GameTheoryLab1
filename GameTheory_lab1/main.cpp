#include "BrownRobinson.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() 
{
  std::ofstream out("../tool/out.txt");

  std::array<std::array<int, height>, width> matrix = 
  { { 
    { 1, 17, 18 },
    { 14, 6, 16 },
    { 14, 14, 13 } 
  } };

	BrownRobinson table(matrix, 0.8);
  vector<vector<float>> result = table.calculate();

  // Save results to file
  for (const auto row : result) 
  {
    std::copy(row.begin(), row.end(), std::ostream_iterator<float>(out, " "));
    out << endl;
  }

	system("pause");
  out.close();
	return 0;
}