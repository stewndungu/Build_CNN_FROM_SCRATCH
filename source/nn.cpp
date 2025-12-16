#include "../include/nn.hpp"
#include "../include/vec.hpp"
#include <iostream>
#include "../include/layer.hpp"
#include <string>
#include "../include/activation.hpp"

using namespace std;


NeuralNetwork::NeuralNetwork(const vector<int>& layer_sizes, string first_activation, string second_activation)
{
    if(layer_sizes.size() > 1)
    {
     int input_size_for_layer = layer_sizes[0]; 
     int num_neurons_in_layer = layer_sizes[1];   
     this->Layers.push_back(Layer(input_size_for_layer, num_neurons_in_layer,first_activation));
    }
    for (size_t i = 2; i < layer_sizes.size(); ++i) 
    {
        
        int input_size_for_layer = layer_sizes[i - 1]; 

      
        int num_neurons_in_layer = layer_sizes[i];      

        this->Layers.push_back(Layer(input_size_for_layer, num_neurons_in_layer,second_activation));
    }
}

Vec NeuralNetwork::forward( Vec& x) 
{
    Vec answer=x;

    for( auto& layer : this->Layers)
    {
        answer = (layer.forward(answer));
    }

    return answer;

}

// needed some help from AI with this part and made some tweaks along the way
void NeuralNetwork::backward(const Vec& x, const Vec& target, double lr){
    
    int num_layers = Layers.size();
    
    // 1. Create a storage container for dZ (gradients) for EVERY layer.
    //    We size it to 'num_layers' so we can access index [0] to [num_layers-1].
    std::vector<Vec> all_gradients(num_layers);

    // ============================================================
    // STEP 1: CALCULATE OUTPUT LAYER GRADIENTS (The End)
    // ============================================================
    int last_idx = num_layers - 1;
    
    // Use your getters to retrieve state
    Layer& output_layer = Layers[last_idx];
    const Vec& output_predictions = output_layer.getOutput();
    string activation_type = output_layer.getActivation(); // e.g. "sigmoid"

    Vec dZ_output;
    for(size_t i = 0; i < output_predictions.size(); i++) {
        double a = output_predictions[i];
        double y = target[i];

        // 1. Error = Prediction - Target
        double error = a - y;

        // 2. Derivative (Assuming Sigmoid for this example)
        // If type == "sigmoid", derivative is a * (1 - a)
        double derivative = 1.0; 
        if(activation_type == "sigmoid") {
            derivative = derivativeSigmoid(a);
        } else if (activation_type == "ReLu") {
            // ReLU derivative is 1 if a > 0, else 0
            derivative = derivativeRelu(a);
        }
        
        // 3. Store dZ
        dZ_output.push_back(error * derivative);
    }
    
    // Save this into our gradients list
    all_gradients[last_idx] = dZ_output;


    // ============================================================
    // STEP 2: BACKPROPAGATE ERROR TO HIDDEN LAYERS (The Loop)
    // ============================================================
    // We start from the second-to-last layer and walk down to 0
    
    for(int i = last_idx - 1; i >= 0; i--) {
        
        Layer& current_layer = Layers[i];
        Layer& next_layer    = Layers[i + 1]; // The layer ahead of us
        
        const Vec& current_outputs = current_layer.getOutput();
        const Vec& next_gradients  = all_gradients[i + 1]; // dZ from layer ahead
        
        Vec dZ_hidden;
        
        // Loop through every neuron 'j' in the CURRENT layer
        for(size_t j = 0; j < current_outputs.size(); j++) {
            
            double error_sum = 0.0;
            
            // "Pull" the error back from the NEXT layer's neurons
             std::vector<Neuron>& next_neurons = next_layer.getNeurons();
            
            for(size_t k = 0; k < next_neurons.size(); k++) {
                // We need the weight that connects Current(j) -> Next(k)
                // In your class: Next(k) holds the weights for its inputs
                // So we look at weight index [j] of neuron [k]
                
                // Note: using your getter "getWeights()"
                // Since it returns a reference, we can access [j]
                double w = next_neurons[k].getWeights()[j]; 
                
                error_sum += next_gradients[k] * w;
            }
            
            // Calculate Derivative for current neuron
            double a = current_outputs[j];
            double derivative = 1.0;
            if(current_layer.getActivation() == "sigmoid") {
                derivative = derivativeSigmoid(a);
            } else if (current_layer.getActivation() == "ReLu") {
                derivative = derivativeRelu (a);
            }
            
            dZ_hidden.push_back(error_sum * derivative);
        }
        
        all_gradients[i] = dZ_hidden;
    }


    // ============================================================
    // STEP 3: UPDATE WEIGHTS & BIASES (The Fix)
    // ============================================================
    // Now we have dZ for every layer. We can update parameters.
    
    for(int i = 0; i < num_layers; i++) {
        
        // DYNAMIC INPUT LOGIC:
        // If i == 0, the input was 'x' (the raw image/data)
        // If i > 0, the input was the previous layer's output
        const Vec& input = (i == 0) ? x : Layers[i - 1].getOutput();
        
        Vec& dZ = all_gradients[i];
        
        // Use a non-const reference to neurons so we can modify them
        
        
        // Let's assume you add this to Layer.hpp:
        // vector<Neuron>& getNeurons() { return neurons; } 
        
        vector<Neuron>& layer_neurons = Layers[i].getNeurons(); 
        
        for(size_t j = 0; j < layer_neurons.size(); j++) {
            
            // 1. Update Bias
            double old_bias = layer_neurons[j].getBias();
            double bias_change = dZ[j] * lr;
            layer_neurons[j].setBias(old_bias - bias_change);
            
            // 2. Update Weights
            // The weights in this neuron correspond to the 'input' vector
            for(size_t k = 0; k < input.size(); k++) {
                
                // Get old weight (we need a way to read it first)
                // Your getWeights() returns reference, so we can use it.
                double old_weight = layer_neurons[j].getWeights()[k];
                
                double weight_change = dZ[j] * input[k] * lr;
                
                // Use your setter
                layer_neurons[j].setWeights(k, old_weight - weight_change);
            }
        }
    }

    
}


