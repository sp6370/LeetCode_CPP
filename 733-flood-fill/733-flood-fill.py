class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        
        seen = set()
        
        R = len(image)
        C = len(image[0])
        
        nbr = [(1,0),(-1,0),(0,1),(0,-1)]
        stack = [(sr, sc)]
        seen.add((sr, sc))
        org_col = image[sr][sc]
        image[sr][sc] = newColor
        
        while stack:
            curr_r, curr_c = stack.pop()
            
            for r,c in nbr:
                nbr_r = curr_r + r
                nbr_c = curr_c + c
                
                r_in_bound = nbr_r in range(R)
                c_in_bound = nbr_c in range(C)
                
                if r_in_bound and c_in_bound:
                    if (nbr_r, nbr_c) not in seen and image[nbr_r][nbr_c] == org_col:
                        stack.append((nbr_r, nbr_c))
                        seen.add((nbr_r, nbr_c))
                        image[nbr_r][nbr_c] = newColor
        
                
        return image
        