import matplotlib.pyplot as plt

# uncomment the altered coord list to see the effect of the change
coord = [[ [ 0, 0 ], [ 2, 0 ], [ 2, 2 ], [ 0, 2 ] ], 
         [ [ 2, 0 ], [ 4, 0 ], [ 4, 2 ], [ 2, 2 ] ], 
         [ [ 4, 0 ], [ 6, 0 ], [ 6, 2 ], [ 4, 2 ] ],
         # [ [ 4, 0 ], [ 6, 0 ], [ 6, 2 ], [ 5, 3 ], [ 4, 2 ] ],
         [ [ 6, 0 ], [ 8, 0 ], [ 8, 2 ], [ 6, 2 ] ],
         [ [ 8, 0 ], [ 10,0 ], [ 10, 2 ], [ 8, 2 ] ]]

# repeat the first point to create a 'closed loop'
for sublist in coord:
    sublist.append(sublist[0]) 

for i in range(len(coord)):
    xs, ys = zip(*coord[i]) #create lists of x and y values   
    # plt.xlim(-2.5, 15) 
    plt.xticks(range(-2, 15, 1))
    plt.ylim(-2.5, 5) 
    plt.plot(xs,ys) 
plt.show()






