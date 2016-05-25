#include "GRT.h"
#include <iomanip>      // std::setprecision

using namespace GRT;

VectorDouble take_second(VectorDouble input) {
    VectorDouble output;
    output.resize(1);
    output[0] = input[1];
    return output;
}

int main() {
    const UINT N = 3;
    Random random;
    GestureRecognitionPipeline pipeline;
    FeatureApply apply(3, 1, take_second);
    pipeline.addFeatureExtractionModule(apply);

    //Run some dummy data through the feature extraction
    for(UINT i=0; i<100; i++){
        VectorDouble inputVector(N);

        for(UINT j=0; j<N; j++){
            inputVector[j] = random.getRandomNumberUniform(-1,1);
        }

        //Pass the input data through the preprocessing modules in the pipeline
        if( !pipeline.preProcessData( inputVector ) ){
            cout << "ERROR: Failed to compute features!\n";
            return -1;
        }

        //Get the features and print the values
        VectorDouble featureData = pipeline.getFeatureExtractionData();

        cout << "i: " << i << "\t";
        cout << "input vector: ";
        for(UINT j=0; j<N; j++){
            cout << std::fixed << std::setw(7) << inputVector[j] << "\t";
        }
        cout << "feature vector: ";
        for(UINT j=0; j<featureData.size(); j++){
            cout << std::fixed << std::setw(7) << featureData[j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
