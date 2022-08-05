//给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。 
//
// 请你将两个数相加，并以相同形式返回一个表示和的链表。 
//
// 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。 
//
// 
//
// 示例 1： 
// 
// 
//输入：l1 = [2,4,3], l2 = [5,6,4]
//输出：[7,0,8]
//解释：342 + 465 = 807.
// 
//
// 示例 2： 
//
// 
//输入：l1 = [0], l2 = [0]
//输出：[0]
// 
//
// 示例 3： 
//
// 
//输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
//输出：[8,9,9,9,0,0,0,1]
// 
//
// 
//
// 提示： 
//
// 
// 每个链表中的节点数在范围 [1, 100] 内 
// 0 <= Node.val <= 9 
// 题目数据保证列表表示的数字不含前导零 
// 
//
// Related Topics 递归 链表 数学 👍 8438 👎 0

#include <iostream>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/*
 *
 *
 *  //go ahead an instantiate a ListNode for ->next
        $return = new ListNode($this->carry + $l1->val + $l2->val);

        //如果 val 大于等于 10，carry 将进位设置为1，val减去10
        if ($this->carry = intval($return->val > 9)) {
            $return->val -= 10;
        }

        //如果没有下一个数字了，就做完了。否则将 next 定义为 ListNotes 的下一个
        $return->next = (!$this->carry && is_null($l1->next) && is_null($l2->next))
            ? null
            : $this->addTwoNumbers($l1->next, $l2->next);

        //完成嵌套循环以定义所有内容后，返回结果
        return $return;
 */
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
//leetcode submit region end(Prohibit modification and deletion)
