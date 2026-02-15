# Build_CNN_FROM_SCRATCH
A beginner trial to make a small neural network from scratch

## The Plan
- Build the building blocks of a neuron (11-15-2025 to 11-22-2025)
    - Matrix (multiply,random,etc)
    - Vector (add, subtracting,random,etc)
- Build Full fledge neuron + layers with forward pass (11/23/25 to 11/29)
    - Activation (functions inside hpp & cpp)
    - Neuron
    - Layer
- Build backpropogation + neural network class (11/30/25 - 12/21)
    - Neural Network (function inside hpp & cpp)
    - save & load weights into txt
    - backpropogation
    - learning rate adaptation 
    - xor_test.cpp for checking
    - Batch size training
- Build convolution function & pgm file loading (12/21/25 - 12/23)
- Build convo2D class (12/29- 02/15/26)
    - 3D array 
    - Forwards Pass
        -Explanation: In this function, you will notice that there are 6 loops inside. Which is alot. But hey, this is just a beginners redition and trying to learn. So the main idea is this. When we are doing convolutions of an image, we have these key terms" Filter,Kernel & channel. The filter is what the convolution is looking for: edges(vertical/horizontal), certain areas, etc. The Kernel is the actual matrix with the certain numbers to look for those features. Then the channel is the R G B. The red, blue and green of a photo. We have three images for those channels. 

            Now when it runs, it is first supposed to go to the feature you are looking for first. Meaning it will only change after all the channels are looked at. Then it will start at the top most area (row& column) of each channel(split images for each major color). Then we create a variable sum.

            You then maybe wondering, Why are we creating a variable sum. Well to move on to the next step which is max pooling. We need to condense the data of each kernel shift(with each input is multiplied by weights(kernel) then goes into sum). So we take a sum of all the numbers that were convoled using the kernel to get a single number. Then adding a bias. Which is then saved in an output matrix after it was activated. THe output matrix is usually called a feature map. The feature map will be smaller than the original size of the image.  

            Because we are adding the red, green, & blue sums together, we expect one feature map. Also the sum resets after going through the kernel for a region of each channel.

    - Backward Pass
        -Explanation: Okay, so now we move to Backpropagation. First, we take the Error Map (from the next layer) and compare it to our saved last_output. We apply the Derivative of the Activation: if a pixel was 0 in the forward pass, we crush its error to 0 now. This gives us the Cleaned Error Map.

        Next, to fix the Weights, we don't look at the kernel weights yet. Instead, we take the Cleaned Error Map and convolve it with the saved Input. This tells us which weights contributed to the error.

        To fix the Bias, we simply sum up all the values in the Cleaned Error Map ,because the bias touched every pixel equally.

        Finally, to tell the previous layer how much it messed up, NOW we use the kernel weights. We flip the kernels 180 degrees and convolve them with the Cleaned Error Map. This creates the new error map for the layer before us.
- Build Max pooling (2/16/26 -)
