#include "BrownRobinson.h"

int main() {

  std::array<std::array<int, height>, width> matrix = 
  { { 
    { 1, 17, 18 },
    { 14, 6, 16 },
    { 14, 14, 13 } 
  } };

	BrownRobinson table(matrix, 0.8);
	table.calculate();
	system("pause");
	return 0;
}