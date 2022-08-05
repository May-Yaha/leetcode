#pragma once
#include <iostream>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode vector_to_linked(std::vector<int>& list) {
  ListNode p;

  for (int num : list) {
    p.next = new ListNode(num, p.next);
  }

  return p;
}

void vector_to_linked(ListNode& list, std::vector<int>& nums) {
  if (nums.empty()){
    return;
  }

  list.next = new ListNode(nums.back(), list.next);
  nums.pop_back();

  return vector_to_linked(list, nums);
}