class MinStack {
public:
    stack<pair<int, int>> record;
    
    MinStack(){
        
    }
    
    void push(int val){
      //there is no minimum in the stack
      if(record.empty())
        record.push({val, val});
      else{
        int mini=min(val, record.top().second);
        record.push({val, mini});
      }
    }
    
    void pop(){
      record.pop();
    }
    
    int top(){
      return record.top().first;
    }
    
    int getMin(){
      return record.top().second;
    }
};