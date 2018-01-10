#include "RotateVector.hpp"

MObject cma::RotateVector::inVector;
MObject cma::RotateVector::rotate;
MObject cma::RotateVector::outVector;
MObject cma::RotateVector::length;

cma::RotateVector::RotateVector(){}

cma::RotateVector::~RotateVector(){}

void * cma::RotateVector::creator(void){
    return new RotateVector;
}

MStatus cma::RotateVector::initialize(void){
    try{

    }
    catch(MStatusException & e){
        
    }
}

MStatus compute(const MPlug & plug,	MDataBlock & data) override{
    MStatus ret;
	try {
		if (plug == this->outPoint) {
			MDataHandle ground, ray_from, ray_vector;
			_getInputValue(data, &ground, &ray_from, &ray_vector);

			VectorF ray_from_v(ray_from.asFloat3());
			VectorF ray_vector_v(ray_vector.asFloat3());

			bool is_cross = false;
			double distance = _getLengthToCrossPoint(ground.asMesh(), ray_from_v, ray_vector_v, &is_cross);
			
			VectorF ray_cross(ray_vector_v * distance + ray_from_v);

			_setOutputValue(data, ray_cross.x, ray_cross.y, ray_cross.z);
			data.setClean(plug);
		}
	}
	catch (MStatusException e) {
		std::cerr << e.toString() << std::endl;
	}
	return MStatus::kSuccess;
}

