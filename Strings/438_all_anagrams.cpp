// O(P + S)
class Solution {
public:
    std::vector<int> findAnagrams(const std::string&  s, const std::string& p) {
        std::vector<int> p_count(26, 0), cur_count(26, 0), result;
        // fill p letters count
        for(char c: p)
            p_count.at(char2ind(c))++;

        int p_len = p.size();
        int a_start = 0; 
        char c; int c_ind;
        for (int i = 0; i < s.size(); i++){
            c = s.at(i); c_ind = char2ind(c);
            
            // wrong char, restart from next i + 1
            if (p_count.at(c_ind) == 0){
                std::fill(cur_count.begin(), cur_count.end(), 0);
                a_start = i + 1;
            }
            // good char, count it
            else if(cur_count.at(c_ind) < p_count.at(c_ind)){
                cur_count.at(c_ind)++;
                // if reached p len save result, move start by 1 pos
                if(i - a_start + 1 == p_len){
                    result.push_back(a_start);
                    cur_count.at(char2ind(s.at(a_start)))--;
                    a_start++;
                }
            }
            // good char, but reached its limit already
            // move start until removed its last encounter 
            else {
                for (int j = a_start; j < i; j++){
                    cur_count.at(char2ind(s.at(j)))--;
                    a_start++;
                    if (s.at(j) == c)
                        break;
                }
                cur_count.at(c_ind)++;
            }
        }
        return result;
    }
protected:
    int char2ind(char c){
        return tolower(c, locale()) - 'a';
    }
};