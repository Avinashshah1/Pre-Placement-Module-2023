class Solution {
public:
    string addStrings(string num1, string num2) {
      int i=num1.size()-1;
        int j=num2.size()-1;
        int sum=0;
        string s="";
        
        while(i>=0||j>=0 ||sum!=0)
        {
            if(i>=0)
            {
                sum=sum+ (num1[i]-'0');
                i--;
            }
            if(j>=0)
            {
                sum=sum + (num2[j]-'0');
                j--;
            }
            
            s=s+char(sum%10 + '0');
            sum=sum/10;
            
           
            
            
        }
    
        reverse(s.begin(),s.end());
        return s;
        
        
        
    }
};