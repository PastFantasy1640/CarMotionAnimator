/////////////////////////////////////////////////////
//SortVertexID.hpp
//
//Copyright (c) 2017 Shotaro Shirao
//
//This software is released under the MIT License.
//http://opensource.org/licenses/mit-license.php
/////////////////////////////////////////////////////

#pragma once
#ifndef CMA_SORTVERTEXID_HPP_
#define CMA_SORTVERTEXID_HPP_

#include <maya/MPxCommand.h>

namespace cma {

/** SortVertexID CLASS
 * 頂点IDを適正な結果を出せるようにソートを掛ける
 */
class SortVertexID : public MPxCommand{
public:
	//////////////////////////////
	// PUBLIC MEMBER CONSTANT
	//////////////////////////////
	static const MString cmd_name_;

	//////////////////////////////
	// PUBLIC MEMBER VALIABLES
	//////////////////////////////
	
	
	//////////////////////////////
	// PUBLIC MEMBER FUNCTION
	//////////////////////////////

	/** Constructor
	 */	
	SortVertexID();

	/** Destructor
	 */
	~SortVertexID();

	MStatus doIt(const MArgList & args);

	static void *creator(void);

protected:

private:

};

};

#endif //end of include guard
