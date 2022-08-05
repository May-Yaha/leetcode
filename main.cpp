#include <iostream>
#include <vector>
#include <map>

#include "util/conv_linked.h"

using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
  std::map<int, int> target_map;
  for (int i = 0; i < nums.size(); ++i) {
    if (target_map.find(nums[i]) == target_map.end()) {
      target_map[target - nums[i]] = i;
      return {target_map.find(nums[i])->second, i};
    }
  }

  return {0, 0};
}

class Solution {
 private:
  int carry = 0;
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode res(carry + l1->val + l2->val);

//    std::cout << res.val << "\t" << l1->val << "\t" << l2->val << std::endl;
    if (carry = res.val > 9) {
      res.val -= 10;
    }
    res.next =
        (carry == 0 && l1->next == nullptr && l2->next == nullptr) ? nullptr : addTwoNumbers(l1->next, l2->next);

    return &res;
  }
};

void two_sum_test() {
  std::vector<int> nums = {3, 2, 4};
  int target = 6;
  auto res = twoSum(nums, target);
  for (int i = 0; i < res.size(); ++i) {
    std::cout << res[i] << std::endl;
  }
}

void add_two_numbers_test() {
  std::vector<int> l1_list = {2, 4, 3};
  std::vector<int> l2_list = {5, 6, 4};

  ListNode l1, l2;
  vector_to_linked(l1, l1_list);
  vector_to_linked(l2, l2_list);

  Solution solution;
  auto res = solution.addTwoNumbers(&l1, &l2);
  while (res != nullptr) {
    std::cout << res << std::endl;
    res = res->next;
  }
}

void conv_linked_test() {
  std::vector<int> l1_list = {2, 4, 3};
  std::vector<int> l2_list = {5, 6, 4};

  auto l1 = vector_to_linked(l1_list);
  auto l2 = vector_to_linked(l2_list);

  ListNode l3;
  vector_to_linked(l3, l1_list);

  std::cout << "ok" << std::endl;
}

int main() {
//  conv_linked_test();
  add_two_numbers_test();
}
