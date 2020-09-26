# LeetCode
Solutions in C++ & Python 3 for LeetCode problems. New problems will be continuously added.  

To compile a *C++* solution run:  
```
gcc -Wall path/to/the.cpp -o main -lc++ -std=c++11
./main
```  
__Note:__ For [LinkedLists](LinkedLists/) and [Trees](Trees/) add `parse_input.cpp` like this:
```
gcc -Wall path/to/the.cpp path/to/parse_input.cpp -o main -lc++ -std=c++11
./main
```  

For *Python 3* just do:
```
python3 path/to/the.py
```  
And follow the prompts.   

# Table of contents

- **Arrays**

| Problem | Solution | Time complexity | Space complexity |
| ------ | ------ | ------ | ------ |
| [48. Rotate Image](https://leetcode.com/problems/rotate-image/) | [cpp](Arrays/48_rotate_image.cpp) [py](Arrays/48_rotate_image.py) | O(N<sup>2</sup>) | O(1) |
| [53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) | [cpp](Arrays/53_max_subarray.cpp) [py](Arrays/53_max_subarray.py) | O(N) | O(1) |
| [55. Jump Game](https://leetcode.com/problems/jump-game/) | [cpp](Arrays/55_jump_game.cpp) [py](Arrays/55_jump_game.py) | O(N) | O(1) |
| [283. Move Zeroes](https://leetcode.com/problems/move-zeroes/) | [cpp](Arrays/283_move_zeroes.cpp) [py](Arrays/283_move_zeroes.py) | O(N) | O(1) |

- **Linked Lists**

| Problem | Solution | Time complexity | Space complexity |
| ------ | ------ | ------ | ------ |
| [2. Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) | [cpp](LinkedLists/2_add_two_numbers.cpp) [py](LinkedLists/2_add_two_numbers.py) | O(M + N) | O(max(M, N)) |
| [19. Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) | [cpp](LinkedLists/19_remove_nth_node.cpp) [py](LinkedLists/19_remove_nth_node.py) | O(N) | O(1) |
| [21. Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/) | [cpp](LinkedLists/21_merge_2sorted.cpp) [py](LinkedLists/21_merge_2sorted.py) | O(N + M) | O(1) |

- **Math**

| Problem | Solution | Time complexity | Space complexity |
| ------ | ------ | ------ | ------ |
| [509. Fibonacci Number](https://leetcode.com/problems/fibonacci-number/) | [cpp](Math/509_fibonacci_number.cpp) [py](Math/509_fibonacci_number.py) | O(N) | O(1) |

- **Sorting**

| Problem | Solution | Time complexity | Space complexity |
| ------ | ------ | ------ | ------ |
| [75. Sort Colors](https://leetcode.com/problems/sort-colors/) | [cpp](Sorting/75_sort_colors.cpp) [py](Sorting/75_sort_colors.py) | O(N), one pass | O(1) |
| [179. Largest Number](https://leetcode.com/problems/largest-number/) | [cpp](Sorting/179_largest_number.cpp) [py](Sorting/179_largest_number.py) | O(SNlogN)<sup>\*</sup> | O(SN)<sup>\*</sup> | 
  
<sup>\*</sup>*S = logEL* - [average](https://stackoverflow.com/questions/50261364/explain-why-time-complexity-for-summing-digits-in-a-number-of-length-n-is-ologn) number of digits in an element of the array 

- **Strings**

| Problem | Solution | Time complexity | Space complexity |
| ------ | ------ | ------ | ------ |
| [20. Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) | [cpp](Strings/20_valid_parentheses.cpp) [py](Strings/20_valid_parentheses.py) | O(N) | O(N) |
| [299. Bulls and Cows](https://leetcode.com/problems/bulls-and-cows/) | [cpp](Strings/299_bulls_and_cows.cpp) [py](Strings/299_bulls_and_cows.py) | O(N) | O(1) |
| [438. Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/) | [cpp](Strings/438_all_anagrams.cpp) [py](Strings/438_all_anagrams.py) | O(P + S) | O(1) |
| [771. Jewels and Stones](https://leetcode.com/problems/jewels-and-stones/) | [cpp](Strings/771_jewels_and_stones.cpp) [py](Strings/771_jewels_and_stones.py) | O(J + S) | O(J) |
| [921. Minimum Add to Make Parentheses Valid](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/) | [cpp](Strings/921_min_add_to_make_valid.cpp) [py](Strings/921_min_add_to_make_valid.py) | O(N) | O(1) |

- **Trees**

| Problem | Solution | Time complexity | Space complexity |
| ------ | ------ | ------ | ------ |
| [94. Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/) | [cpp](Trees/94_inorder_traversal.cpp) [py](Trees/94_inorder_traversal.py) | O(N) | O(logN) |
| [102. Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/submissions/) | [cpp](Trees/102_level_order_traversal.cpp) [py](Trees/102_level_order_traversal.py) | O(N) | O(N) |
| [104. Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/) | [cpp](Trees/104_max_depth.cpp) [py](Trees/104_max_depth.py) | O(N) | DFS: O(logN) \| BFS: O(N) |
| [111. Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree/) | [cpp](Trees/111_min_depth.cpp) [py](Trees/111_min_depth.py) | O(N) | DFS: O(logN) \| BFS: O(N) |
| [199. Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/) | [cpp](Trees/199_right_side_view.cpp) [py](Trees/199_right_side_view.py) | O(N) | O(logN) |

