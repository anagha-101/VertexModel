# # import matplotlib.pyplot as plt

# # def plot_cells():
# #     cell_list_x = []
# #     cell_list_y = []
# #     apical_xy_list = []
# #     basal_xy_list = []
# #     # make a list of cell coordinates
# #     # cell_list = []

# #     for i in range(1,7):
# #         apical_x = i
# #         apical_y = 2
# #         basal_x = i
# #         basal_y = 1
# #         cell_list_x.append([apical_x, basal_x])
# #         cell_list_y.append([apical_y, basal_y]) 
# #         # plt.plot(apical_x, apical_y, 'ro')
# #         # plt.plot(basal_x, basal_y, 'bo')
# #         plt.scatter(cell_list_x, cell_list_y)
# #         plt.yticks(range(0, 5, 1))
# #         plt.xlim(0, 8)
# #     # print(cell_list)
# #     plt.show()
        
# #     #     basal_xy = (i,1)
# #     #     apical_xy_list = 
# #     #     basal_xy_list = cell_list.append(basal_xy)
# #     # print(cell_list)
# #     # print(apical_xy_list)
# #     # print(basal_xy_list)    
# #     # #     list.append([apical_xy, basal_xy])
# #     # # print(list)
# #     # # for i in range(len(list)):
# #     # #     xs, ys = zip(*list[i])
# #     # #     plt.plot(xs, ys)
# #     # #     plt.xticks(range(0, 8, 1))
# #     # #     plt.ylim(0, 5)
# #     # # plt.plot(cell_list[apical_xy], 'ro')
# #     # # plt.plot(basal_xy, 'bo')
# #     # plt.ylim(0, 5)
# #     # plt.xlim(0, 8)
# #     # plt.show()
# # plot_cells()

# import matplotlib.pyplot as plt

# # Initialize lists to hold x and y coordinates for apical and basal points
# cell_list_x = []
# cell_list_y = []

# for i in range(1, 7):
#     apical_x = i
#     apical_y = 2
#     basal_x = i
#     basal_y = 1
    
#     # Append coordinates to the lists
#     cell_list_x.extend([apical_x, basal_x])
#     cell_list_y.extend([apical_y, basal_y])
#     plt.plot([apical_x[i], apical_x[i+1]], [ basal_x[i], basal_x[i+1]], 'k-')
#     # Draw a line between apical and basal points
#     plt.plot([apical_x, basal_x], [apical_y, basal_y], 'k-')  # 'k-' for black line
#     # plt.plot([apical_x, apical_y], [ basal_x, basal_y], 'k-')
# # Plot all points at once
# plt.scatter(cell_list_x, cell_list_y, color=['red' if y == 2 else 'blue' for y in cell_list_y])

# # Set y-ticks and x-limits
# plt.yticks(range(0, 5, 1))
# plt.xlim(0, 8)

# # Display the plot
# plt.show()

import matplotlib.pyplot as plt

# Apical coordinates
xa = [1, 2, 3, 4, 5, 6]
ya = [2, 2, 2, 2, 2, 2]

# Basal coordinates
xb = [1, 2, 3, 4, 5, 6]
yb = [1, 1, 1, 1, 1, 1]

# Plotting
plt.scatter(xa, ya, color='blue', label='Apical')
plt.scatter(xb, yb, color='red', label='Basal')

# Drawing lines between apical and basal points
for i in range(len(xa)):
    plt.plot([xa[i], xb[i]], [ya[i], yb[i]], 'k-')
    # plt.plot([xa[i], xa[i-1]], [xb[i], yb[i-1]], 'k-')  # 'k-' for black line

plt.legend()
plt.show()