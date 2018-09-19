#include <iostream>
#include <vector>

using namespace std;

bool IsValid(int i, int j, const int &row, const int &col)
{
  if(i < 0 || i >= row)
     return false;
  if(j < 0 || j >= col)
     return false;
  return true;
}
void getNumberOfIslandsR(const vector<vector<int>>& binaryMatrix, vector<vector<int>>& binaryMatrixVisited,
                         int i, int j, const int &row, const int &col)
{
  binaryMatrixVisited[i][j] = 1;

  const static vector<pair<int, int>> dirs = { { -1, 0 }, {1, 0}, {0, -1}, {0, 1} };
  for (const auto& d : dirs) {
    const auto i_ = i + d.first;
    const auto j_ = j + d.second;
    if (IsValid(i_, j_, row, col) && binaryMatrix[i_][j_] == 1 && binaryMatrixVisited[i_][j_] == 0) {
      getNumberOfIslandsR(binaryMatrix, binaryMatrixVisited, i_, j_, row, col);
    }
  }


  // if(IsValid(i - 1, j, row, col) && binaryMatrix[i - 1][j] == 1 && binaryMatrixVisited[i - 1][j] == 0)
  // {
  //   getNumberOfIslandsR(binaryMatrix, binaryMatrixVisited, i - 1, j, row, col);
  // }
  //   if(IsValid(i + 1, j, row, col) && binaryMatrix[i + 1][j] == 1&& binaryMatrixVisited[i + 1][j] == 0)
  // {
  //   getNumberOfIslandsR(binaryMatrix, binaryMatrixVisited, i + 1, j, row, col);
  // }
  //   if(IsValid(i, j - 1, row, col) && binaryMatrix[i][j - 1] == 1&& binaryMatrixVisited[i][j - 1] == 0)
  // {
  //   getNumberOfIslandsR(binaryMatrix, binaryMatrixVisited, i, j - 1, row, col);
  // }
  //   if(IsValid(i, j + 1, row, col) && binaryMatrix[i][j + 1] == 1&& binaryMatrixVisited[i][j + 1] == 0)
  // {
  //   getNumberOfIslandsR(binaryMatrix, binaryMatrixVisited, i, j + 1, row, col);
  // }

}
int getNumberOfIslands( const vector<vector<int>>& binaryMatrix )
{
  // your code goes here
  if (binaryMatrix.empty())
    return 0;
  const int cols = static_cast<int>(binaryMatrix[0].size());
  const int rows = static_cast<int>(binaryMatrix.size());
  vector<vector<int>> binaryMatrixVisited(rows, vector<int>(cols, 0));

  int noOfIslands = 0;
  for(int i = 0; i < rows; i++)
    for(int j = 0; j < cols; j++)
    {
      if(binaryMatrix[i][j] == 1 && binaryMatrixVisited[i][j] == 0)
      {
        getNumberOfIslandsR(binaryMatrix, binaryMatrixVisited, i, j, rows, cols);
        noOfIslands++;
      }
    }

  return noOfIslands;

}

int main() {
  vector<vector<int>> binaryMatrix {{1, 0, 1, 1},
                                    {0, 0, 0, 0},
                                    {0, 1, 1, 0},
                                    {0, 0, 0, 1}};
  cout<<getNumberOfIslands(binaryMatrix);
  return 0;
}
