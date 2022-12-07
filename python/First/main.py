import matplotlib.pyplot as plt
import numpy as np
X, insert, heap, merge, quick = [], [], [], [], []
for line in open('D:\C++ folders\RogalskiProject\python\First/TimeOfProcessingMicroseconds.txt', 'r'):
    values = [float(s) for s in line.split()]
    X.append(values[0])
    insert.append(values[1])
    heap.append(values[2])
    merge.append(values[3])
    quick.append(values[4])
    print(values[0], values[1], values[2], values[3], values[4])

plt.plot(X, insert, color='r', label='Insert')

plt.plot(X, heap, color='g', label='Heap')

plt.plot(X, merge, color='b', label='Merge')

plt.plot(X, quick, color='y', label='Quick')

plt.xlabel("The size of the vector")
plt.ylabel("Time")
plt.title("Comparison of the speed between sorting methods")
plt.legend()

plt.show()
