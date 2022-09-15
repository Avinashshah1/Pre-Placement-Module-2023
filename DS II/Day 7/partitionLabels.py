def partitionLabels(self, s: str) -> List[int]:
        
        temp = {val:index for index, val in enumerate(s)}
        
        
        consider = s[0]
        start = 0
        ans = []
        
        for i in range(len(s)):
            
            if i == temp[consider]:
                ans.append(temp[consider] - start + 1)
                start = i + 1
                if i < len(s) - 1:
                    consider = s[i+1]
                continue
                
            if temp[s[i]] > temp[consider]:
                temp[consider] = temp[s[i]]
                
        return ans