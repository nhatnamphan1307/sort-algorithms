import sys
import numpy as np
import time

numOfArrays = 10
elements = 1000000


with open(r"D:\UIT\Coding\SortAlgo\data.txt", "r") as f:
    data = np.fromfile(f, sep=" ")


if len(data) != numOfArrays * elements:
    raise ValueError("Error: The number of elements in the file is not correct")

data = data.reshape((numOfArrays, elements))  

sorted_arrays = []
for i in range(numOfArrays):
    start = time.time()
    
    sorted_arr = np.sort(data[i])
    
    end = time.time()
    duration = (end - start) * 1000  
    
    sorted_arrays.append(sorted_arr)
    
    print(f"Dataset {i + 1}: {duration:.2f} ms", file=sys.stderr)


np.savetxt("numpysort.txt", sorted_arrays, fmt="%.6f")