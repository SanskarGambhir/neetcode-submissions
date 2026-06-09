class MinStack {
public:
    stack<int> s;
    vector<int> minValueTrack;

    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(s.size() == 1){
            minValueTrack.push_back(val);
        }
        else if(val < minValueTrack.back()){
            minValueTrack.push_back(val);
        }
        else{
            minValueTrack.push_back(minValueTrack.back());
        }
    }
    
    void pop() {
        s.pop();
        minValueTrack.pop_back();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minValueTrack.back();
    }
};
