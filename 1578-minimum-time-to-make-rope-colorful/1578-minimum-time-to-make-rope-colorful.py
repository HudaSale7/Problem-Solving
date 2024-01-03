class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        time = 0
        prev = ''
        maxTime = 0

        for i in range(len(colors)):
            if colors[i] == prev:
                if neededTime[i] > maxTime:
                    time += maxTime
                    maxTime = neededTime[i]
                else:
                    time += neededTime[i]

            else:
                maxTime = neededTime[i]

            prev = colors[i]

        return time
        
        