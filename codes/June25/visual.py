# plot apical in red and basal in blue and each cell in a different color 
import matplotlib.pyplot as plt

# plot apical and basal points
apical_xy = [(1, 2), (2, 2), (3, 2), (4, 2), (5, 2), (6, 2)]
basal_xy = [(1, 1), (2, 1), (3, 1), (4, 1), (5, 1), (6, 1)]
plt.scatter(*zip(*apical_xy), color='red')
plt.scatter(*zip(*basal_xy), color='blue')

# Plotting each cell in a different color
coord = [[[1, 2], [1, 1], [2, 1], [2, 2]], [[2,2],[2,1],[3,1],[3,2]], [[3, 2], [3, 1], [4, 1], [4, 2]],[[4,2],[4,1],[5,1],[5,2]] ,[[5, 2], [5, 1], [6, 1], [6, 2]]]
for sublist in coord:
    sublist.append(sublist[0]) 

for i in range(len(coord)):
    xs, ys = zip(*coord[i]) #create lists of x and y values   
    # plt.xlim(-2.5, 15) 
    plt.xticks(range(-2, 15, 1))
    plt.ylim(-2.5, 5) 
    # plt.plot(xs,ys)
    # for edges in black
    plt.plot(xs,ys,'k-') 
plt.show()