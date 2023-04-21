#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>

class minDistance {
public:
	std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int K) {
        auto cmp = [](const std::vector<int> &p1, const std::vector<int> &p2) {
            return pow(p1[0], 2) + pow(p1[1], 2) < pow(p2[0], 2) + pow(p2[1], 2);
        };
        
        nth_element(points.begin(), points.begin() + K, points.end(), cmp);
        return std::vector<std::vector<int>>(points.begin(), points.begin() + K);
    }
};

void printVec(const std::vector<std::vector<int>> &vec, std::string msg="V")
{
    std::cout << msg <<" = [";
    for (int i =0;i <vec.size();i++)
        std::cout <<"["<< vec[i][0] <<","<< vec[i][1]<< "], ";
    std::cout << "]\n";
}

int main() {
	std::vector<std::vector<int>> points{{3,3},{5,-1},{-2,4}};
	minDistance solution;
	printVec(points,"Points");
	std::vector<std::vector<int>> sol = solution.kClosest(points,2);
	printVec(sol,"result");	
}
