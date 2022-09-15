def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        if(len(ransomNote) > len(magazine)):
            return False
        
        values = {}
        for i in range(len(magazine)):
            if(magazine[i] in values):
                values[magazine[i]] += 1
            else:
                values[magazine[i]] = 1
        
        for j in range(len(ransomNote)):
            if (ransomNote[j] in values):
                if(values[ransomNote[j]] == 0):
                    return False
                values[ransomNote[j]] -= 1
            else:
                return False
                
            
        return True