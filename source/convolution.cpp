#include <iostream>
#include "convolution.hpp"

using namespace std;
 convolution::convolution (int& num_of_Filters, int& num_of_channels, int& kernelSize, string activationType)
{
    this->weights.resize(num_of_Filters, vector<vector<Vec>>(num_of_channels, vector<Vec>(kernelSize, Vec(kernelSize))));

    this->activationType = activationType;

    int in = num_of_channels * kernelSize * kernelSize;
    
    for(int filter= 0; filter < num_of_Filters; filter++)
    {
        for(int channel=0; channel < num_of_channels; channel++)
        {
            for(int row= 0; row < kernelSize ; row++)
            {
                for(int column = 0; column < kernelSize ; column++)
                {
                    if(activationType == "ReLu")
                    {
                         weights[filter][channel][row][column] = HeAdjusted(in,0.01);
                    }
                    else if(activationType == "sigmoid" || activationType == "tanh_act")
                    {
                         weights[filter][channel][row][column] = Xavier(in);
                    } 
                   
                }
            }
        }
    }


    this->bias.resize(num_of_Filters,0.0);
}

Weights& convolution::getWeights()
{
    return this->weights;
}

Vec& convolution::getBias()
{
    return this->bias;
}

vector<Mat> convolution::forward(const vector<Mat>& input)
{
    if (input.empty() || (input.size() != this->weights[0].size()))
     {
    throw std::runtime_error("Input channels do not match filter channels!");  
    }
    this->last_input = input;
    int num_filters = this->weights.size();
    int num_channels = input.size();
    int in_row = input[0].size();
    int in_column = input[0][0].size();
    int kernel_size = this->weights[0][0].size();

    int out_row = in_row - kernel_size + 1;
    int out_column = in_column - kernel_size + 1;

    vector<Mat> output(num_filters, Mat(out_row,Vec(out_column,0.0)));
    for(int f = 0 ; f < num_filters;f++)
    {
        for(int r = 0; r< out_row; r++)
        {
            for(int c = 0; c< out_column; c++)
            {
                double sum = 0.0;

              
                for(int channel = 0; channel < num_channels;channel++)
                {
                    for (int ky = 0; ky < kernel_size; ky++) {
                        for (int kx = 0; kx < kernel_size; kx++) {
                            sum += input[channel][r + ky][c + kx] * weights[f][channel][ky][kx];
                        }
                     }
                }

                sum += this->bias[f];                        // Add Bias

                // FIX: if-else instead of switch for strings
                if (this->activationType == "ReLu") {
                    sum = ReLu(sum);
                } else if (this->activationType == "Sigmoid") {
                    sum = sigmoid(sum);
                } else if (this->activationType == "tanh_act") {
                    sum = tanh_act(sum);
                } else {
                    sum = sigmoid(sum); // Default
                }
            }
               
            output[f][r][c] = sum;
        }
    }

    this->last_output = output;
     return output;
}

//Needed help heavily on AI for this part
vector<Mat> backward(const vector<Mat>& output_error, double learning_rate)
{
    // 1. Dimensions
    int num_filters = this->weights.size();
    int num_channels = this->weights[0].size();
    int kernel_size = this->weights[0][0].size();
    
    int out_row = output_error[0].size();
    int out_col = output_error[0][0].size();
    int in_row = last_input[0].size();
    int in_col = last_input[0][0].size();

    // Prepare the gradients we need to return (Error for previous layer)
    vector<Mat> input_gradient(num_channels, Mat(in_row, Vec(in_col, 0.0)));
    
    // Temporary storage for weight and bias updates
    Weights weight_gradients = this->weights; // Initialize structure
    // Zero out the weight_gradients
    for(auto& f : weight_gradients) for(auto& c : f) for(auto& r : c) fill(r.begin(), r.end(), 0.0);
    Vec bias_gradients(num_filters, 0.0);

    // ============================================================
    // THE BACKWARD PASS LOOP
    // ============================================================
    for (int f = 0; f < num_filters; f++) {
        
        // --- STEP 1: Activation Derivative ("Clean" the error) ---
        // We calculate the gradient of the loss with respect to the pre-activation sum (delta)
        Mat delta(out_row, Vec(out_col, 0.0));
        for (int r = 0; r < out_row; r++) {
            for (int c = 0; c < out_col; c++) {
                double val = this->last_output[f][r][c];
                
              // Using your specific helper functions from activation.hpp
                if (this->activationType == "ReLU" || this->activationType == "ReLu") {
                    deriv = derivativeRelu(val);
                } 
                else if (this->activationType == "Sigmoid") {
                    deriv = derivativeSigmoid(val);
                }
                else if (this->activationType == "tanh_act") {
                    // Note: using the name from your provided .hpp typo
                    deriv = derivatieTanh_act(val); 
                }
            }
        }

        // --- STEP 2: Bias Gradient (Sum of Deltas) ---
        for (int r = 0; r < out_row; r++) {
            for (int c = 0; c < out_col; c++) {
                bias_gradients[f] += delta[r][c];
            }
        }

        // --- STEP 3: Weight and Input Gradients ---
        for (int ch = 0; ch < num_channels; ch++) {
            for (int r = 0; r < out_row; r++) {
                for (int c = 0; c < out_col; c++) {
                    
                    double error_at_pixel = delta[r][c];

                    // A. Update Weights (Input * Error)
                    for (int ky = 0; ky < kernel_size; ky++) {
                        for (int kx = 0; kx < kernel_size; kx++) {
                            weight_gradients[f][ch][ky][kx] += last_input[ch][r + ky][c + kx] * error_at_pixel;
                        }
                    }

                    // B. Update Input Gradient (Error * Flipped Weights)
                    // This creates the error map to pass to the PREVIOUS layer
                    for (int ky = 0; ky < kernel_size; ky++) {
                        for (int kx = 0; kx < kernel_size; kx++) {
                            // The "Flip" logic is handled by the indices here
                            input_gradient[ch][r + ky][c + kx] += weights[f][ch][ky][kx] * error_at_pixel;
                        }
                    }
                }
            }
        }
    }

    // ============================================================
    // STEP 4: Update Parameters (Gradient Descent)
    // ============================================================
    for (int f = 0; f < num_filters; f++) {
        this->bias[f] -= learning_rate * bias_gradients[f];
        for (int ch = 0; ch < num_channels; ch++) {
            for (int ky = 0; ky < kernel_size; ky++) {
                for (int kx = 0; kx < kernel_size; kx++) {
                    this->weights[f][ch][ky][kx] -= learning_rate * weight_gradients[f][ch][ky][kx];
                }
            }
        }
    }

    return input_gradient;
}


   