class RandomizedSet {
public:
    vector<int> values; // this will store the values that are currently present.
    unordered_map<int,int> mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()){
            return false;
        }
        values.push_back(val);
        mp[val] =  values.size()-1; //storing index of val in values vector, in map.
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)!=mp.end()){ 
        //below is just we are copying the last i.e. back value 
        //to the index of val element that we have to remove,logic is we will copy that last value 
        //to this cur val position and remove that last value.
            
            values[mp[val]] = values.back();
            values.pop_back();
            mp[values[mp[val]]] = mp[val]; //assign the new index as we changed its(last value) position.
            mp.erase(val); //erase val from map.
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int randomIndex = rand() % values.size();//finding random index.
        return values[randomIndex]; //returning value at random index.
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */