#pragma comment(user, "CarMotionAnimator Plug-in Header")
/////////////////////////////////////////////////////
//NodeIDs.hpp
//
//Copyright (c) 2017 Shotaro Shirao
//
//This software is released under the MIT License.
//http://opensource.org/licenses/mit-license.php
/////////////////////////////////////////////////////

#pragma once
#ifndef CMA_NODEIDS_HPP_
#define CMA_NODEIDS_HPP_

namespace cma {

/**
 * ノードIDの管理名前空間
 * @see MPxNode http://download.autodesk.com/us/maya/2011help/api/class_m_px_node.html
 */
namespace NodeIDs{
	//////////////////////////////
	// PUBLIC MEMBER CONSTANT
	//////////////////////////////

	enum { 

	    /** FollowGroundノードのID
         * @see cma::FollowGround
	     */        
        kFollowGroundID = 0x70000,

        /** RotateVectorノードのID
         * @see cma::RotateVector
         */
         kRotateVectorID = 0x70001,
    }; 
}
#endif //end of include guard
