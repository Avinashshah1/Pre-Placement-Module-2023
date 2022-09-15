class Solution:
    def frequencySort(self, s: str) -> str:
        counts=dict()
        for i in s:
            counts[i]=counts.get(i,0)+1
        lst=list()
        for i,j in counts.items():
            lst.append((j,i))
        lst=sorted(lst,reverse=True)
        sr=""
        for i,j in lst:
            for k in range(0,i):
                sr=sr+j
        return sr;
                