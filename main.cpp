#include <iostream>
#include <vector>
using namespace std;

//temperatures are variable type double, real numbers ranging from [60-100] degrees Fahrenheit
vector<double> temperatures = {72.0, 85.1, 95.9, 60.0, 102.3, 62.7, 100.2, 80.7};
vector<double> tree_health  = {90.8, 75.0, 50.1, 95.0,  30.0, 91.2, 30.2, 60.0};


/* prediction function for tree health: predicted_health = m * temperature + b
 - takes parameters double temp, double m (slope), and double b (intercept)
 - returns predicted health value as a double
 */

//defining a predict function, will be used as a calculation function (will be called in training function)
//predicts the tree health value
double predict(double temperature, double m, double b) {
    double predictedHealth = m * temperature + b;
    return predictedHealth;
}

// defining a squared error function, another calculation function that will be used for the training function
double squaredError(double predicted, double actual) {
    double squared = (predicted - actual) * (predicted - actual);
    return squared;
}

// defining the mean squared error function
double calcMSE(const vector<double>& temperatures, const vector<double>& health, double m, double b) {
    double total = 0.0;
    int n = temperatures.size();
    for (int i = 0; i < n; i++) {
        double calculated  = predict(temperatures[i], m, b);
        total += squaredError(calculated, health[i]);
        }

    double MSE = total / n;
    return MSE;
}

//defining a training function, will use all the previous calculation functions, gradient descent
// parameters = temperature, health, slope, intercept, user inputs learning rate and epoch number
void train(const vector<double>& temperatures,const vector<double>& health, double& m, double& b, double learning_rate, int epochs) {
    for (int epoch = 0 ; epoch < epochs ; epoch++) {
        // dm and db values -> partial derivatives (dm is wrt slope and db is wrt y-intercept)
        double dm = 0.0;
        double db = 0.0;
        for (int i = 0; i < temperatures.size(); i++) {
            double guess = predict(temperatures[i], m, b);
            double error = guess - health[i];
            dm += error * temperatures[i];
            db += error;

        }
        // scale dm and db by 2n
        int n = temperatures.size();
        dm *= (2.0/n);
        db *= (2.0/n);


        // update m and b accordingly
        m = m - learning_rate * dm;
        b = b - learning_rate * db;

    }

}
// main calls each function
int main() {
    double m = 0.0;
    double b = 0.0;
    double learning_rate = 0.0001;
    int epochs = 1000000;

    // Train the linear regression model
    train(temperatures, tree_health, m, b, learning_rate, epochs);


    //printing summary of the model

    cout << "Linear Regression Model: Tree Health Prediction" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Training data points: " << temperatures.size() << endl;
    cout << "Input feature: Temperature (Fahrenheit)" << endl;
    cout << "Target value: Tree health score" << endl;
    cout << endl;

    cout << "Final model:" << endl;

    cout << "tree_health = " << m << " * temperature + " << b << endl;
    cout << endl;

    cout << "Interpretation:" << endl;

    if (m < 0) {
        cout << "For each 1 degree Fahrenheit increase in temperature, "
             << "the predicted tree health score decreases by about "
             << -m << " points." << endl;
    } else if (m > 0) {
        cout << "For each 1 degree Fahrenheit increase in temperature, "
             << "the predicted tree health score increases by about "
             << m << " points." << endl;
    } else {
        cout << "Temperature has no effect on the predicted tree health score "
             << "in this model." << endl;
    }

    return 0;
}
