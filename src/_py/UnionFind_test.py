from random import randrange

#
from UnionFind_QuickFind import UnionFind

test_size = 12
uf = UnionFind( test_size )
uf.enumerate()

while 1 < uf.g :
   uf.union( randrange( test_size ), randrange( test_size ) )
   uf.enumerate()

