# visualise the 2d cells using coordinates from a csv file
import matplotlib.pyplot as plt
import pandas
data = pandas.read_csv('codes/July16/vertices.csv')
print(data)

# plot apical and basal points
apical_xy = data.iloc[:, 0:2]
basal_xy = data.iloc[:, 2:4]
plt.scatter(apical_xy.iloc[:, 0], apical_xy.iloc[:, 1], color='red')
plt.scatter(basal_xy.iloc[:, 0], basal_xy.iloc[:, 1], color='blue')
# connect the points
plt.plot(apical_xy.iloc[:, 0], apical_xy.iloc[:, 1], 'k-')
plt.plot(basal_xy.iloc[:, 0], basal_xy.iloc[:, 1], 'k-')
# connect the vertical points
for i in range(len(apical_xy)):
    plt.plot([apical_xy.iloc[i, 0], basal_xy.iloc[i, 0]], [apical_xy.iloc[i, 1], basal_xy.iloc[i, 1]], 'k-')
plt.xlim(0, 10) 
plt.ylim(0, 10) 
plt.show()