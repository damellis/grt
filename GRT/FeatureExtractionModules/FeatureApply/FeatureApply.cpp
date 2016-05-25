/**
 @file
 @author  Ben Zhang <benzh@cs.berkeley.edu>
 @version 1.0

 @brief
 */

#include "FeatureApply.h"

namespace GRT{

RegisterFeatureExtractionModule< FeatureApply > FeatureApply::registerModule("Filter");

FeatureApply::FeatureApply(UINT numInputDim, UINT numOutputDim,
                           const FilterFunction func)
        : filter(func) {
    classType = "Filter";
    featureExtractionType = classType;
    debugLog.setProceedingText("[DEBUG Filter]");
    errorLog.setProceedingText("[ERROR Filter]");
    warningLog.setProceedingText("[WARNING Filter]");

    init(numInputDim, numOutputDim);
}

FeatureApply::FeatureApply(const FeatureApply &rhs) {
    classType = "Filter";
    featureExtractionType = classType;
    debugLog.setProceedingText("[DEBUG Filter]");
    errorLog.setProceedingText("[ERROR Filter]");
    warningLog.setProceedingText("[WARNING Filter]");

    *this = rhs;
}

FeatureApply::~FeatureApply() {
}

FeatureApply& FeatureApply::operator=(const FeatureApply &rhs) {
    if (this != &rhs) {
        this->filter = rhs.filter;
        copyBaseVariables( (FeatureExtraction*)&rhs );
    }
    return *this;
}

bool FeatureApply::deepCopyFrom(const FeatureExtraction *featureExtraction) {
    if (featureExtraction == NULL) return false;
    if( this->getFeatureExtractionType() == featureExtraction->getFeatureExtractionType() ){
        // Invoke the equals operator to copy the data from the rhs instance to this instance
        *this = *(FeatureApply*)featureExtraction;
        return true;
    }

    errorLog << "clone(FeatureExtraction *featureExtraction)"
             << "-  FeatureExtraction Types Do Not Match!"
             << endl;
    return false;
}

bool FeatureApply::init(UINT numInputDim, UINT numOutputDim) {
    if (numInputDim == 0 || numOutputDim == 0) {
        errorLog << "init( UINT numDimensions ) - "
                 << "The number of input dimensions must be greater than zero!"
                 << endl;
        return false;
    }
    numInputDimensions = numInputDim;
    numOutputDimensions = numOutputDim;
    return true;
}

bool FeatureApply::computeFeatures(const VectorDouble &inputVector) {
    if (filter != nullptr) {
        featureVector = filter(inputVector);
        featureDataReady = true;
        return true;
    }
    return false;
}

bool FeatureApply::reset() {
    return false;
}

}//End of namespace GRT
