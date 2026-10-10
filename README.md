# Linear Regression in C++

A C++ machine learning mini-project that implements linear regression from scratch using gradient descent.

## Overview

This project trains a simple linear regression model to predict a simulated tree health score based on ambient temperature.

The model fits a line in the form:

tree_health = m * temperature + b

where:

- `m` is the slope
- `b` is the intercept
- `temperature` is the input feature
- `tree_health` is the predicted output

The purpose of this project is to understand how linear regression works without relying on machine learning libraries.
 
## Motivation

I built this project to connect concepts from computer science, calculus, statistics, and linear algebra. Instead of using a library, I implemented the core pieces manually in C++ so I could better understand how a model learns by minimizing error.

## Features

- Implements linear regression from scratch
- Uses gradient descent to optimize model parameters
- Calculates Mean Squared Error
- Uses C++ functions to separate prediction, error calculation, and training
- Prints the learned equation and interpretation after training

## Dataset 

The dataset in this project is simulated and used for learning purposes only. The temperature and tree-health values are illustrative and are not intended to represent validated environmental research.

## How it works

The project is organized around four main functions:

- `predict(temperature, m, b)` calculates the predicted tree health value.
- `squaredError(predicted, actual)` calculates the squared error for one prediction.
- `calcMSE(temperatures, health, m, b)` calculates the mean squared error across the dataset.
- `train(temperatures, health, m, b, learning_rate, epochs)` updates `m` and `b` using gradient descent.


## Build and Run

### Option 1: Compile with g++

```bash
g++ main.cpp -o regression
./regression
```

### Option 2: Build with CMake

```bash
mkdir build
cd build
cmake ..
make
./machinelearning
```

## Sample Output

```text
Linear Regression Model: Tree Health Prediction
------------------------------------------------
Training data points: 8
Input feature: Temperature (Fahrenheit)
Target value: Tree health score

Final model:
tree_health = -1.54106 * temperature + 192.205

Interpretation:
For each 1 degree Fahrenheit increase in temperature, the predicted tree health score decreases by about 1.54106 points.
```

## What I Learned

This project helped me understand the connection between machine learning and mathematics. I practiced implementing a cost function, calculating prediction error, and using gradient descent to update model parameters over multiple iterations.

Writing the model in C++ helped me focus on the algorithm itself rather than relying on a prebuilt machine learning library.

## Future Improvements

- Load data from a CSV file
- Add unit tests for the prediction and error functions
- Track Mean Squared Error during training
- Add a visualization of the regression line
- Compare this C++ implementation with a Python scikit-learn version
- Use a real environmental dataset
