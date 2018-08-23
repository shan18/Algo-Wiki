""" The following code uses python to implement breadth first search
"""

class Graph:
    
    def __init__(self):
        self.graph = {}
    
    def add_edge(self, u, v):
        if u not in self.graph:
            self.graph[u] = []
        self.graph[u].append(v)
    
    def bfs(self, source):
        visited = [False] * len(self.graph)
        queue = []
        
        queue.append(source)
        visited[source] = True
        
        while queue:
            s = queue.pop(0)
            print(s, end=' ')
            
            for i in self.graph[s]:
                if visited[i] == False:
                    visited[i] = True
                    queue.append(i)
