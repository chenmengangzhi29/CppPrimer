#include <iostream>
#include <vector>
#include<math.h>
using namespace std;

class Solution {
public:
	vector<int> Find_Array(int& n) {
		vector<int> ans;
		int i = 0, j = 0, count = 0;
		if (n == 1) {
			ans.push_back(1);
			return ans;
		}
		for (i = 2; i < 1000000000; ++i) {
			for (j = 2; j <= sqrt(i); ++j) {
				if (i % j == 0)
					break;
			}
			if (j > sqrt(i)) {
				ans.push_back(i);
				count++;
				if (count >= n) {
					return ans;
				}
			}

		}
		return ans;

	}

};




//int main() {
//	int n;
//	solution s;
//	vector<int> array;
//	cin >> n;
//	array = s.find_array(n);
//	for (int i = 0; i < array.size(); ++i) {
//		cout << array[i] <<' ';
//	}
//	cout << endl;
//
//	return 0;
//}