#include <stdio.h>
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
    vector<int> topology = {2,700,1}; 
    NeuralNetwork nn(topology,"sigmoid", "ReLu");


     string answer;
     int epochs = 70;
    cout<< "Do you want to load any old saved weights? Say yay or nay"<<endl;
   
    cin>> answer;
if(answer == "yay") 
{
    cout<< "Please enter the adjusted epochs? Enter a number"<<endl;
    cin >> epochs;
}

    // ---------------------------------------------------------
    // 2. DEFINE TRAINING DATA (XOR)
    // ---------------------------------------------------------
    std::vector<Vec> inputs = {
    // Set 1
    {0.0, 0.0}, {0.0, 1.0}, {1.0, 0.0}, {1.0, 1.0},
    // Set 2
    {0.0, 0.0}, {0.0, 1.0}, {1.0, 0.0}, {1.0, 1.0},
    // Set 3
    {0.0, 0.0}, {0.0, 1.0}, {1.0, 0.0}, {1.0, 1.0},
    // Set 4
    {0.0, 0.0}, {0.0, 1.0}, {1.0, 0.0}, {1.0, 1.0},
    // Set 5
    {0.0, 0.0}, {0.0, 1.0}, {1.0, 0.0}, {1.0, 1.0},
    // Set 6
    {0.0, 0.0}, {0.0, 1.0}, {1.0, 0.0}, {1.0, 1.0},
    // Set 7
    {0.0, 0.0}, {0.0, 1.0}, {1.0, 0.0}, {1.0, 1.0},
    // Set 8
    {0.0, 0.0}, {0.0, 1.0}, {1.0, 0.0}, {1.0, 1.0},
    // Set 9
    {0.0, 0.0}, {0.0, 1.0}, {1.0, 0.0}, {1.0, 1.0},
    // Set 10
    {0.0, 0.0}, {0.0, 1.0}, {1.0, 0.0}, {1.0, 1.0}
};
    std::vector<Vec> targets = {
    // Set 1
    {0.0}, {1.0}, {1.0}, {0.0},
    // Set 2
    {0.0}, {1.0}, {1.0}, {0.0},
    // Set 3
    {0.0}, {1.0}, {1.0}, {0.0},
    // Set 4
    {0.0}, {1.0}, {1.0}, {0.0},
    // Set 5
    {0.0}, {1.0}, {1.0}, {0.0},
    // Set 6
    {0.0}, {1.0}, {1.0}, {0.0},
    // Set 7
    {0.0}, {1.0}, {1.0}, {0.0},
    // Set 8
    {0.0}, {1.0}, {1.0}, {0.0},
    // Set 9
    {0.0}, {1.0}, {1.0}, {0.0},
    // Set 10
    {0.0}, {1.0}, {1.0}, {0.0}
};

    // ---------------------------------------------------------
    // 3. THE TRAINING LOOP
    // ---------------------------------------------------------
   
    double learning_rate = 0.1;
    double min_lr = 0.009;

    std::cout << "Training Started..." << std::endl;

    for (int i = 0; i < epochs; i++) {
         if (i > 0 && i % 50 == 0 && learning_rate > min_lr) 
         {
            learning_rate *= 0.99;
                
             // Safety check: Don't let it dip even slightly below the floor
             if (learning_rate < min_lr) 
            {
              learning_rate = min_lr;
            }
         }
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
        if (i % 1 == 0) {
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

    nn.save("trained_xor_model.txt");
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