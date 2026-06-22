#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int twoPtr_trapRainwater(const vector<int>& height, vector<int>& water_levels) 
{
    if (height.empty()) return 0;

    int n = height.size();
    water_levels.assign(n, 0);
    
    int left = 0, right = n - 1;
    int left_max = 0, right_max = 0;
    int total_water = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= left_max) {
                left_max = height[left];
            }
            else {
                water_levels[left] = left_max - height[left];
                total_water += water_levels[left];
            }
            left++;
        }
        else {
            if (height[right] >= right_max) {
                right_max = height[right];
            }
            else {
                water_levels[right] = right_max - height[right];
                total_water += water_levels[right];
            }
            right--;
        }
    }
    return total_water;
}

int main() 
{




    return 0;
}
