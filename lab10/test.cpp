//Given a rectangular grid of characters you have to find out the length of a side of the largest square such that all the characters of the square are same and the center [intersecting point of the two diagonals] of the square is at location (r,c). The height and width of the grid is M and N respectively. Upper left corner and lower right corner of the grid will be denoted by (0, 0) and (M − 1, N − 1) respectively. Consider the grid of characters given below. Given the location (1, 2) the length of a side of the largest square is 3.
//The input starts with a line containing a single integer T (< 21). This is followed by T test cases. The first line of each of them will contain three integers M, N and Q (< 21) separated by a space where M, N denotes the dimension of the grid. Next follows M lines each containing N characters. Finally, there will be Q lines each containing two integers r and c. The value of M and N will be at most 100.
//For each test case in the input produce Q + 1 lines of output. In the first line print the value of M , N and Q in that order separated by single space. In the next Q lines, output the length of a side of the largest square in the corresponding grid for each (r, c) pair in the input.


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int M, N, Q;
        cin >> M >> N >> Q;
        cout << M << " " << N << " " << Q << endl;
        vector<string> grid;
        for (int j = 0; j < M; j++)
        {
            string s;
            cin >> s;
            grid.push_back(s);
        }
        for (int j = 0; j < Q; j++)
        {
            int r, c;
            cin >> r >> c;
            int max_side = 1;
            while (r - max_side >= 0 && r + max_side < M && c - max_side >= 0 && c + max_side < N)
            {
                bool flag = true;
                for (int k = r - max_side; k <= r + max_side; k++)
                {
                    for (int l = c - max_side; l <= c + max_side; l++)
                    {
                        if (grid[k][l] != grid[r][c])
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag)
                    {
                        break;
                    }
                }
                if (flag)
                {
                    max_side++;
                }
                else
                {
                    break;
                }
            }
            cout << max_side * 2 - 1 << endl;
        }
    }
    return 0;
}



