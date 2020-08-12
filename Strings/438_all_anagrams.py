# O(P + S)
class Solution(object):
    def findAnagrams(self, s, p):
        p_count, cur_count, result = [0]*26, [0]*26, []
        for c in p:
            p_count[self._char2ind(c)] += 1

        p_len = len(p)
        a_start = 0
        for i, c in enumerate(s):
            c_ind = self._char2ind(c)
            
            #  wrong char, restart from next i + 1
            if p_count[c_ind] == 0:
                cur_count = [0]*26
                a_start = i + 1
            # good char, count it
            elif cur_count[c_ind] < p_count[c_ind]:
                cur_count[c_ind] += 1 
                # if reached p len save result, move start by 1 pos
                if i - a_start + 1 == p_len:
                    result.append(a_start)
                    cur_count[self._char2ind(s[a_start])] -= 1 
                    a_start += 1
            # good char, but reached its limit already
            # move start until removed its last encounter 
            else:
                for j in range(a_start, i):
                    cur_count[self._char2ind(s[j])] -=1
                    a_start += 1
                    if s[j] == c:
                        break
                cur_count[c_ind] +=1
            
        return result
            
    def _char2ind(self, c):
        return ord(c.lower()) - ord('a')


if __name__ == '__main__':
    s = input('s: ')
    p = input('p: ')
    print('Anagrams: ', Solution().findAnagrams(s, p))