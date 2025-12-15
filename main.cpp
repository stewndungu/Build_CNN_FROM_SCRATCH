#include <stdio.h>
#include <iostream>
//#include "include/vec.hpp"
//#include "include/matrix.hpp"
//#include "include/neuron.hpp"
//#include "include/layer.hpp"
#include "include/nn.hpp"
#include <vector>
#include <iostream>


using namespace std;

int main()
{
    //Testing phases during the building of the neuralnetwork. You can delete these
    /*
    Vec myVec;
    Vec myTec;
    myVec.push_back(1.23);
    myVec.push_back(2.5);
    myVec.push_back(1.23);

    myTec.push_back(123);
    myTec.push_back(1.23);
    myTec.push_back(1.23);

    
    

    vector<double>answer = scalar_mult(myVec,4);
    
    cout << dot(myVec,myTec) << "\n";

   
    print(answer);



    Mat matrixA;
    Mat matrixB;

    matrixA = {
        {1,2,3},
        {1,2,3}
    };
    matrixB = {
        {1,2},
        {1,2},
        {1,2}
    };

     vector<vector<double>> matrix2 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    print(multiply(matrixA,matrixB));

    print(transpose(matrix2));



    Layer dense(3, 10,"sigmoid");
Vec x = {1.0, 0.5, -1.2};
Vec y = dense.forward(x);
print(y);
dense.summary();

 Layer D(3, 10,"ReLu");
Vec x1 = {1.0, 0.5, -1.2};
Vec y1 = D.forward(x1);
print(y1);
D.summary();

*/

 
    // 1. SETUP THE NETWORK
    // ---------------------------------------------------------
    // Topology: 2 Inputs -> 4 Hidden Neurons -> 1 Output Neuron
    // Activation: "sigmoid" (easiest for XOR)
    vector<int> topology = {2, 10,1}; 
    NeuralNetwork nn(topology, "sigmoid");

    // ---------------------------------------------------------
    // 2. DEFINE TRAINING DATA (XOR)
    // ---------------------------------------------------------
    std::vector<Vec> inputs = {
        {0.0, 0.0}, {0.0, 1.0}, {1.0, 0.0}, {1.0, 1.0}
    };
    std::vector<Vec> targets = {
        {0.0}, {1.0}, {1.0}, {0.0}
    };

    // ---------------------------------------------------------
    // 3. THE TRAINING LOOP
    // ---------------------------------------------------------
    int epochs = 10000;
    double learning_rate = 0.01;

    std::cout << "Training Started..." << std::endl;

    for (int i = 0; i < epochs; i++) {
        
        // Loop through every training example
        for (size_t j = 0; j < inputs.size(); j++) {
            
            // Step A: Forward Pass (Make a guess)
            // We don't necessarily need to store the result here, 
            // because the NN saves it internally in 'activations'.
            nn.forward(inputs[j]);

            // Step B: Backward Pass (Learn from mistake)
            nn.backward(inputs[j], targets[j], learning_rate);
        }

        // OPTIONAL: Print progress every 1000 epochs
        if (i % 1000 == 0) {
            // Calculate a quick MSE (Mean Squared Error) just to see if it's dropping
            double total_error = 0;
            for(size_t j=0; j<inputs.size(); j++) {
                Vec out = nn.forward(inputs[j]);
                double error = targets[j][0] - out[0];
                total_error += error * error;
            }
            std::cout << "Epoch " << i << " - Error: " << total_error << std::endl;
        }
    }

    std::cout << "Training Finished!" << std::endl;

    // ---------------------------------------------------------
    // 4. VERIFICATION (TESTING)
    // ---------------------------------------------------------
    std::cout << "\nTesting Results:" << std::endl;
    
    for (size_t j = 0; j < inputs.size(); j++) {
        Vec prediction = nn.forward(inputs[j]);
        
        std::cout << "Input: " << inputs[j][0] << ", " << inputs[j][1] 
                  << " | Target: " << targets[j][0]
                  << " | Prediction: " << prediction[0] << std::endl;
    }

    return 0;
}