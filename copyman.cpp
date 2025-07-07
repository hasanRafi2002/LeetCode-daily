#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



class FindSumPairs {
private:
    vector<int> nums1, nums2;
    unordered_map<int, int> count2;

public:
    FindSumPairs(vector<int>& n1, vector<int>& n2) {
        nums1 = n1;
        nums2 = n2;
        for (int num : nums2) {
            count2[num]++;
        }
    }

    void add(int index, int val) {
        int oldVal = nums2[index];
        count2[oldVal]--;
        nums2[index] += val;
        count2[nums2[index]]++;
    }

    int count(int tot) {
        int result = 0;
        for (int x : nums1) {
            int complement = tot - x;
            if (count2.find(complement) != count2.end()) {
                result += count2[complement];
            }
        }
        return result;
    }
};

int main() {
    int n1, n2;
    cout << "Enter size of nums1: ";
    cin >> n1;
    vector<int> nums1(n1);
    cout << "Enter elements of nums1: ";
    for (int i = 0; i < n1; ++i) {
        cin >> nums1[i];
    }

    cout << "Enter size of nums2: ";
    cin >> n2;
    vector<int> nums2(n2);
    cout << "Enter elements of nums2: ";
    for (int i = 0; i < n2; ++i) {
        cin >> nums2[i];
    }

    FindSumPairs obj(nums1, nums2);

    int q;
    cout << "\nEnter number of queries: ";
    cin >> q;

    cout << "Query format:\n";
    cout << "1 index value  --> to perform add(index, value)\n";
    cout << "2 total        --> to perform count(total)\n\n";

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int index, val;
            cin >> index >> val;
            obj.add(index, val);
            cout << "Added " << val << " to nums2[" << index << "]\n";
        } else if (type == 2) {
            int tot;
            cin >> tot;
            int result = obj.count(tot);
            cout << "Count of pairs with sum " << tot << ": " << result << "\n";
        } else {
            cout << "Invalid query type.\n";
        }
    }

    return 0;
}
