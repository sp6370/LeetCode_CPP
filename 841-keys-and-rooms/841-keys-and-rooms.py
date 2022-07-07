class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        
        visited = {}
        
        def helper(cur_node, rooms, visited):
            
            if cur_node in visited:
                return
            visited[cur_node] = True
            
            for nebr in rooms[cur_node]:
                if nebr not in visited:
                    helper(nebr, rooms, visited)
        
        helper(0, rooms, visited)
        
        return len(visited) == len(rooms)
                    
                    
                
            
            
            
        