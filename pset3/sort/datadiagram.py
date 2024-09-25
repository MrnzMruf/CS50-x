import pandas as pd
import matplotlib.pyplot as plt

# Step 1: Time data
data_real_time = {
    "Algorithm Type": ["sort 1", "sort 2", "sort 3"],
    "random 5000": [0.054, 0.022, 0.059],
    "random 10000": [0.173, 0.044, 0.115],
    "random 50000": [7.145, 3.804, 4.216],
    "sorted 5000": [0.02, 0.02, 0.049],
    "sorted 10000": [0.047, 0.05, 0.042],
    "sorted 50000": [5.185, 3.385, 5.76],
    "reversed 5000": [0.226, 0.043, 0.119],
    "reversed 10000": [8.161, 4.742, 4.678]
}

data_user_time = {
    "Algorithm Type": ["sort 1", "sort 2", "sort 3"],
    "random 5000": [0.035, 0.004, 0.02],
    "random 10000": [0.14, 0.006, 0.072],
    "random 50000": [5.001, 0.032, 1.694],
    "sorted 5000": [0.001, 0.003, 0.018],
    "sorted 10000": [0.029, 0.003, 0.024],
    "sorted 50000": [0.043, 0.178, 0.082],
    "reversed 5000": [4.316, 0.21, 1.921],
    "reversed 10000": [0.041, 0.033, 0.174]
}

data_sys_time = {
    "Algorithm Type": ["sort 1", "sort 2", "sort 3"],
    "random 5000": [0.019, 0.017, 0.019],
    "random 10000": [0.029, 0.017, 0.035],
    "random 50000": [0.189, 0.168, 0.173],
    "sorted 5000": [0.018, 0.018, 0.02],
    "sorted 10000": [0.166, 0.165, 0.037],
    "sorted 50000": [0.019, 0.018, 0.017],
    "reversed 5000": [0.041, 0.033, 0.036],
    "reversed 10000": [0.174, 0.174, 0.174]
}

# Step 2: Create DataFrames
df_real_time = pd.DataFrame(data_real_time)
df_user_time = pd.DataFrame(data_user_time)
df_sys_time = pd.DataFrame(data_sys_time)

# Step 3: Save DataFrames as CSV
df_real_time.to_csv('real_time_sorting.csv', index=False)
df_user_time.to_csv('user_time_sorting.csv', index=False)
df_sys_time.to_csv('sys_time_sorting.csv', index=False)

# Step 4: Plot the graphs
# Plot for Real Time
plt.figure(figsize=(15, 5))
for i in range(len(df_real_time)):
    plt.plot(df_real_time.columns[1:], df_real_time.iloc[i, 1:], marker='o', label=df_real_time.iloc[i, 0])
plt.title('Real Time for Sorting Algorithms')
plt.xlabel('Algorithm Type and Input Size')
plt.ylabel('Time (seconds)')
plt.xticks(rotation=45)
plt.legend()
plt.grid()
plt.tight_layout()
plt.savefig('real_time_sorting.png')  # Save the plot
#########################################################  plt.show()

# Plot for User Time
plt.figure(figsize=(15, 5))
for i in range(len(df_user_time)):
    plt.plot(df_user_time.columns[1:], df_user_time.iloc[i, 1:], marker='o', label=df_user_time.iloc[i, 0])
plt.title('User Time for Sorting Algorithms')
plt.xlabel('Algorithm Type and Input Size')
plt.ylabel('Time (seconds)')
plt.xticks(rotation=45)
plt.legend()
plt.grid()
plt.tight_layout()
plt.savefig('user_time_sorting.png')  # Save the plot
#########################################################  plt.show()

# Plot for Sys Time
plt.figure(figsize=(15, 5))
for i in range(len(df_sys_time)):
    plt.plot(df_sys_time.columns[1:], df_sys_time.iloc[i, 1:], marker='o', label=df_sys_time.iloc[i, 0])
plt.title('Sys Time for Sorting Algorithms')
plt.xlabel('Algorithm Type and Input Size')
plt.ylabel('Time (seconds)')
plt.xticks(rotation=45)
plt.legend()
plt.grid()
plt.tight_layout()
plt.savefig('sys_time_sorting.png')  # Save the plot
#########################################################  plt.show()
