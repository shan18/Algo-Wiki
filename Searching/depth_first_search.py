""" The following code uses python to implement depth first search
"""

class Graph:
    
    def __init__(self):
        self.graph = {}
    
    def add_edge(self, u, v):
        if u not in self.graph:
            self.graph[u] = []
        self.graph[u].append(v)
    
    def dfs_util(self, source, visited):
        print(source, end=' ')
        visited[source] = True
        for i in self.graph[source]:
            if visited[i] == False:
                self.dfs_util(i, visited)
    
    def dfs(self, source):
        visited = [False] * len(self.graph)
        self.dfs_util(source, visited)
