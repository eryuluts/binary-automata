#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <codecvt>

class Space
{
    int _nrows;
    int _ncolumns;
    std::vector<std::vector<bool>> _cell_grid;

public:
    Space(int nrows, int ncolumns)
        : _nrows(nrows), _ncolumns(ncolumns), _cell_grid(std::vector<std::vector<bool>>(_nrows, std::vector<bool>(_ncolumns)))
    {
        _cell_grid[_nrows/2][ncolumns/2] = true;
    }

    void tick()
    {
        std::vector<std::vector<bool>> _cell_grid_next_state = _cell_grid;
        for (int i = 0; i < _nrows; i++)
        {
            for (int j = 0; j < _ncolumns; j++)
            {
                // compute next state
                bool u = i < (_nrows - 1) ? _cell_grid[i + 1][j] : false;
                bool d = i > 0 ? _cell_grid[i - 1][j] : false;
                bool l = j > 0 ? _cell_grid[i][j - 1] : false;
                bool r = j < (_ncolumns - 1) ? _cell_grid[i][j + 1] : false;

                if ((u + d + l + r) % 2)
                {
                    _cell_grid_next_state[i][j] = !_cell_grid_next_state[i][j];
                }
            }
        }
         _cell_grid = _cell_grid_next_state;
    }

    void print() const
    {
        for (const auto &row : _cell_grid)
        {
            for (const auto &cell : row)
            {
                char c = cell ? '*' : ' ';
                std::cout << c << ' ';
            }
            std::cout << '\n';
        }
    }
};

int main()
{
    Space space(128, 128);

    space.print();
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        system("clear");
        space.tick();
        space.print();
    }

    return 0;
}