#define DATACLASS
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string.h>
#include "json.hpp"
#include "statistica.h"

using namespace std;

void print_v(vector<double> &vec)
{
    for (auto c : vec)
    {
        cout << c << endl;
    }
}