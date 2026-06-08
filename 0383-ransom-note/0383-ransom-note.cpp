class Solution {
public:
bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int>ransom_hashmap(26);
    unordered_map<char,int>magazine_hashmap(26);

    for(int i = 0 ; i < ransomNote.size() ; i++){
        ransom_hashmap[ransomNote[i]]++;
    }

    for (int i = 0; i < magazine.size(); i++) {
      magazine_hashmap[magazine[i]]++;
    }
    bool flag = true;
    for (int i = 0; i < ransomNote.size(); i++) {
        if(magazine_hashmap.find(ransomNote[i]) == magazine_hashmap.end()){
            return false;
        }
        if(ransom_hashmap[ransomNote[i]] > magazine_hashmap[ransomNote[i]]){
            return false;
        }
        if(ransom_hashmap[ransomNote[i]] <= magazine_hashmap[ransomNote[i]]){
            continue;
        }
    }

    return flag;
}
};