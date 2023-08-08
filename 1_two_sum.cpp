#include <algorithm>
using namespace std;

class Solution{
	public:
		bool comparator(pair<int, int> p, int num){
			return p.first == num;
		}

		vector<int> twoSum(vector<int>& nums, int target){
			vector<int> result(2);
			vector<pair<int, int>> index_pair(nums.size());
			for(auto it = nums.begin(); it != nums.end(); it++){
				index_pair[distance(nums.begin(), it)]
					= make_pair(*it, distance(nums.begin(), it);
			}

			sort(index_pair.begin(), index_pair.end());
			for(auto it = index_pair.begin(); it != index_pair.end(); it++){
				int complement = target - (*it).first;
				if(binary_search(index_pair.begin(),
						 index_pair.end(),
						 complement,
						 comparator)
				   && complement != (*it).first){
					result[0] = (*it).second;
					result_it = equal_range(index_pair.begin(),
								index_pair.end(),
								complement,
								comparator)[0];
					result[1] = (*result_it).second;
				}
			}
			return result;
		}
};

int main(void){
	vector<int> nums{2, 7, 11, 15};
	int target = 9;
	Solution sol;
	cout << sol.twoSum(nums, target) << endl;
	return 0;
}
