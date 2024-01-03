class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        m = {}
        result = []
        for e in nums:
            if e in m:
                m[e] += 1
            else:
                m[e] = 1
        
        while(1):
            temp = []
            for key in m:
                if(m[key] > 0):
                    temp.append(key)
                    m[key] -= 1
            if(len(temp) == 0): break
            result.append(temp)
            
        return result