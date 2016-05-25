/**
 @file
 @author  Ben Zhang <benzh@cs.berkeley.edu>
 @version 1.0

 @brief
 */

#ifndef GRT_FEATURE_APPLY_HEADER
#define GRT_FEATURE_APPLY_HEADER

//Include the main GRT header to get access to the FeatureExtraction base class
#include "../../CoreModules/FeatureExtraction.h"

namespace GRT{

class FeatureApply : public FeatureExtraction {
public:
    using FilterFunction = std::function<VectorDouble(VectorDouble)>;
    /**
     Default constructor. Take a filter function.
     */
    FeatureApply(UINT numInputDim = 1, UINT numOutputDim = 1,
                 const FilterFunction func = nullptr);

    /**
     Copy constructor.

     @param const FeatureApply &rhs: another instance of this class from which
     the data will be copied to this instance
     */
    FeatureApply(const FeatureApply &rhs);

    /**
     Default Destructor
     */
    virtual ~FeatureApply();

    /**
     Sets the equals operator, copies the data from the rhs instance to this.

     @param const FeatureApply &rhs: another instance of this class
     @return a reference to this instance
     */
    FeatureApply& operator=(const FeatureApply &rhs);

    /**
     Sets the FeatureExtraction deepCopyFrom function, overwriting the base
     FeatureExtraction function.  This function is used to deep copy the values
     from the input pointer to this instance of the FeatureExtraction module.
     This function is called by the GestureRecognitionPipeline when the user
     adds a new FeatureExtraction module to the pipeleine.

     @param const FeatureExtraction *featureExtraction: a pointer to another
       instance of this class, the values of that instance will be cloned to
       this instance
     @return returns true if the deep copy was successful, false otherwise
     */
    virtual bool deepCopyFrom(const FeatureExtraction *featureExtraction);

    /**
     Sets the FeatureExtraction computeFeatures function, overwriting the base
     FeatureExtraction function.  This function is called by the
     GestureRecognitionPipeline when any new input data needs to be processed
     (during the prediction phase for example).  This is where you should add
     your main feature extraction code.

     @param const VectorDouble &inputVector: the inputVector that should be
       processed.  Must have the same dimensionality as the FeatureExtraction
       module
     @return returns true if the data was processed, false otherwise
     */
    virtual bool computeFeatures(const VectorDouble &inputVector);

    /**
     Sets the FeatureExtraction reset function, overwriting the base
     FeatureExtraction function. This function is called by the
     GestureRecognitionPipeline when the pipelines main reset() function is
     called. You should add any custom reset code to this function to define how
     your feature extraction module should be reset.

     @return true if the instance was reset, false otherwise
     */
    virtual bool reset();

    bool init(UINT numInputDim, UINT numOutputDim);

    // Tell the compiler we are using the following functions from the MLBase
    // class to stop hidden virtual function warnings
    using MLBase::train;
    using MLBase::train_;
    using MLBase::predict;
    using MLBase::predict_;

protected:
    FilterFunction filter;

    static RegisterFeatureExtractionModule< FeatureApply > registerModule;
};

}//End of namespace GRT

#endif //GRT_KMEANS_FEATURES_HEADER
