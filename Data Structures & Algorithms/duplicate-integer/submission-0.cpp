class MyHashSet{
private:
    int SIZE;
    vector<vector<int>> table;
    int hashFunction(int key){
        return abs(key)%SIZE;
    }
public:
    MyHashSet(int size = 1000){
        SIZE=size;
        table.resize(SIZE);
    }
    void insertHash(int key){
        int index = hashFunction(key);
        for (int num: table[index]){
            if (num==key) return;
        }
        table[index].push_back(key);
    }
    bool contains(int key){
        int index = hashFunction(key);
        for (int num: table[index]){
            if (num==key) return true;
        }
        return false;
    }
};
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        MyHashSet mySet(10000); 
        
        for (int i = 0; i < nums.size(); i++) {
            if (mySet.contains(nums[i])) {
                return true; 
            }
            mySet.insertHash(nums[i]);
        }
        
        return false;
    }
};