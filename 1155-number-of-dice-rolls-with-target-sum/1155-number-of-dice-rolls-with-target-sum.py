class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        hm = {}
        def bfs(m, res, hm) -> int:
            if(res > target): return 0
            if(m == 0): 
                if(res == target):
                    return 1
                return 0

            count = 0

            if hm.get(str(m) + "," + str(res)) is not None: 
                return hm[str(m) + "," + str(res)]
                
            for i in range(1, k+1):
                if(res > target): break
                count = (count + bfs(m-1, res+i, hm) % 1000000007) % 1000000007

            hm[str(m) + "," + str(res)] = count 
            return count

        
        return bfs(n, 0, hm)
