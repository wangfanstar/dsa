#
# Example of using Python lists
#
box = [ 'pencil', 'pen', 'ruler', 'eraser' ]
print box
#['pencil', 'pen', 'ruler', 'eraser']
#
for item in box: print item,
print
# pencil pen ruler eraser
#
box.reverse()
for item in box: print item,
print
# eraser ruler pen pencil
#
box.sort()
for item in box: print item,
print
# eraser pen pencil ruler
#
for i in range(0, len(box)): print box[i],
print
# eraser pen pencil ruler
#
for i in range(len(box)-1, -1, -1): print box[i],
print
# ruler pencil pen eraser
#
for i in range(-1, -len(box)-1, -1): print box[i],
print
# ruler pencil pen eraser
#
bag = [ 'data structures', 'calculus', box, 2012012012 ]
print bag
# ['data structures', 'calculus', ['eraser', 'pen', 'pencil', 'ruler'], 2012012012]
for item in bag: print item,
print
# data structures calculus ['eraser', 'pen', 'pencil', 'ruler'] 2012012012
for item in bag[2]: print item,
print
# eraser pen pencil ruler
for item in bag[2][1:3]: print item,
print
# pen pencil
