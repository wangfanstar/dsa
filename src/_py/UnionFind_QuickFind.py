class UnionFind:
   def __init__(self, n):
      self.g = self.n = n
      self.group = [ k for k in range(n) ]

   def find(self, k):
      return self.group[k]

   def union(self, i, j):
      iGroup , jGroup = self.group[i] , self.group[j]
      if iGroup == jGroup:
         return
      for k in range(self.n):
         if (self.group[k] == jGroup):
            self.group[k] = iGroup
      self.g -= 1

   def enumerate(self):
      print self.group, " [", self.g, "/", self.n, "]"
