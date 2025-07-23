class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        if len(mat) * len(mat[0]) != r * c:
            return mat
        res = []
        temp = []
        for lis in mat:
            for elmt in lis:
                if len(temp) != c:
                    temp.append(elmt)
                else:
                    res.append(temp)
                    temp = []
                    temp.append(elmt)
        if len(temp) != 0:
            res.append(temp)
        return res
