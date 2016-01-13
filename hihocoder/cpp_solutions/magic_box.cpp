#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    string seq;
    cin >> seq;

    int max_len = 0;
    // int cur_len = 0;
    int cr = 0, cy = 0, cb = 0;

    for (int i = 0; i < seq.length(); i++)
    {
        if (seq[i] == 'R')
        {
            cr += 1;
        }
        else if (seq[i] == 'Y')
        {
            cy += 1;
        }
        else {
            cb += 1;
        }

        int a = abs(cr-cy);
        int b = abs(cy-cb);
        int c = abs(cb-cr);

        if ((a == x &&((b == y && c == z) || (b == z && c == y))) ||
            (a == y &&((b == x && c == z) || (b == z && c == x))) ||
            (a == z &&((b == x && c == y) || (b == y && c == x))) )
        {
            int count = cr + cy + cb;

            if (count > max_len)
            {
                max_len = count;
            }
            cr = cy = cb = 0;
        }

    }

    int count = cr + cy + cb;
    if (count > max_len)
    {
        max_len = count;
    }
    cout << max_len << endl;
    return 0;

}
