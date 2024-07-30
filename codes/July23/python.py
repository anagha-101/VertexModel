import matplotlib.pyplot as plt
import pandas as pd

data = pd.read_csv('codes/July23/vertices_square.csv')

# Separate the data into apical and basal coordinates
apical_x = data['Apical_x']
apical_y = data[' Apical_y']
basal_x = data[' Basal_x']
basal_y = data[' Basal_y']

plt.scatter(apical_x, apical_y, color='red', label='Apical')
plt.scatter(basal_x, basal_y, color='blue', label='Basal')

# lines connecting the vertices to form squares
N = 10  # Number of cells horizontally
M = 4   # Number of cells vertically
for i in range(M):
    for j in range(N):
        index = i * N + j
        if j < N - 1:  # Connect to the next cell in the row
            plt.plot([apical_x[index], apical_x[index+1]], [apical_y[index], apical_y[index+1]], color='black')
            plt.plot([basal_x[index], basal_x[index+1]], [basal_y[index], basal_y[index+1]], color='black')
        if i < M - 1:  # Connect to the next cell in the column
            plt.plot([apical_x[index], apical_x[index+N]], [apical_y[index], apical_y[index+N]], color='black')
            plt.plot([basal_x[index], basal_x[index+N]], [basal_y[index], basal_y[index+N]], color='black')
        # Connect apical to basal within the same cell
        plt.plot([apical_x[index], basal_x[index]], [apical_y[index], basal_y[index]], color='black')

plt.legend()
plt.show()