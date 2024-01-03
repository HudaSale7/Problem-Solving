class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        prev = 0
        res = 0
        for s in bank:
            curr = s.count('1')
            if curr != 0:
                res += curr * prev
                prev = curr

        return res
        