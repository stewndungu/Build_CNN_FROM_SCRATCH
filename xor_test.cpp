#include <stdio.h>
#include "include/nn.hpp"
#include <vector>
#include <iostream>
#include <fstream>


using namespace std;


int main()
{
    string filename;
    cout<< "Please enter the filename of the saved model weights"<< "\n";
    cin >> filename;

   vector<int> dummy_topo = {2, 1}; 
NeuralNetwork nn(dummy_topo, "sigmoid", "ReLu");

// This will wipe the 2-1 structure and replace it with 
// the 2-700-1 structure found in your text file.
nn.load(filename);

  


    // ---------------------------------------------------------
    // 2. DEFINE TRAINING DATA (XOR)
    // ---------------------------------------------------------
    std::vector<Vec> inputs = {
   
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
    {0.0, 0.0}, {0.0, 1.0}, {1.0, 0.0}, {1.0, 1.0},
     // Set 1
    {0.0, 0.0}, {0.0, 1.0}, {1.0, 0.0}, {1.0, 1.0},
    // Set 2
    {0.0, 0.0}, {0.0, 1.0}, {1.0, 0.0}, {1.0, 1.0},
    // Set 3
    {0.0, 0.0}, {0.0, 1.0}, {1.0, 0.0}, {1.0, 1.0}
};
    std::vector<Vec> targets = {
    
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
    {0.0}, {1.0}, {1.0}, {0.0},
    // Set 1
    {0.0}, {1.0}, {1.0}, {0.0},
    // Set 2
    {0.0}, {1.0}, {1.0}, {0.0},
    // Set 3
    {0.0}, {1.0}, {1.0}, {0.0}
};

    std::cout << "\nTesting Results:" << std::endl;
    
    for (size_t j = 0; j < inputs.size(); j++) {
        Vec prediction = nn.forward(inputs[j]);
        
        std::cout << "Input: " << inputs[j][0] << ", " << inputs[j][1] 
                  << " | Target: " << targets[j][0]
                  << " | Prediction: " << prediction[0] << std::endl;
    }



    return 0;
}