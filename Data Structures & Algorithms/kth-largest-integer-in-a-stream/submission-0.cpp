class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> kLargest;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto x:nums){
            kLargest.push(x);
        }

        while(kLargest.size()>k){
            kLargest.pop();
        }
    }
    
    int add(int val) {
        if(kLargest.size()<k){
            kLargest.push(val);
        }
        else if(kLargest.top()<val){
            kLargest.pop();
            kLargest.push(val);
        }

        return kLargest.top();
    }
};