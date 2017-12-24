#include "SortVertexID.hpp"
#include <maya/MArgList.h>
#include <maya/MGlobal.h>

cma::SortVertexID::SortVertexID() {
	std::cout << "Constructor" << std::endl;
}

cma::SortVertexID::~SortVertexID() {
	std::cout << "Decstructor" << std::endl;
}

MStatus cma::SortVertexID::doIt(const MArgList & args) {

	MGlobal::executeCommand("print(\"Hello Maya CMD\\n\");");

	return MStatus::kSuccess;
}

void * cma::SortVertexID::creator(void) {
	return new SortVertexID;
}
