import numpy as np
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

# Read file by lines
lines = [line.rstrip('\n') for line in open('out.txt')]

param_list = []

for set in lines:
    param_list.append(set.split())

vLower = []
vUpper = []
vAverage = []
error = []

# Set arrays for plot
for params in param_list:
    vUpper.append(params[0])
    vLower.append(params[1])
    vAverage.append(params[2])
    error.append(params[3])

# Cast to float list
vUpper = list(map(float, vUpper))
vLower = list(map(float, vLower))
vAverage = list(map(float, vAverage))
error = list(map(float, error))

# This locator puts ticks at regular intervals
loc = ticker.MultipleLocator(1)

# Working with 0 figure
plt.figure(0)

# Add functions to plot
line_lower, = plt.plot(vLower,       label='Lower')
line_upper, = plt.plot(vUpper,       label='Upper')
line_average, = plt.plot(vAverage,   label='Average')
plt.legend(handles=[line_lower, line_upper, line_average])

# Set names for axis
plt.xlabel('index')
plt.ylabel('cost')

# Set tick for X axis
plt.xticks(np.arange(0, len(vUpper), step=5))

# Save image
plt.savefig('game_cost.png')

# Working with 1 figure
plt.figure(1)

line_error = plt.plot(error)
plt.xlabel('index')
plt.ylabel('error')

# Set tick for X axis
plt.xticks(np.arange(0, len(error), step=5))

# Save image
plt.savefig('error.png')
