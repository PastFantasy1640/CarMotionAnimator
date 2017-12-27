#include "FollowGround.hpp"

#include <maya/MItMeshPolygon.h>
#include <maya/MFnMesh.h>
#include <maya/MPointArray.h>
#include <maya/MIntArray.h>

#include "exception/MStatusException.hpp"

const MTypeId cma::FollowGround::id(cma::FollowGround::kFollowGroundID);
MObject cma::FollowGround::inMesh;
MObject cma::FollowGround::rayVector;
MObject cma::FollowGround::rayPoint;
MObject cma::FollowGround::outPoint;

////////////////////////////////////////
// FollowGround
////////////////////////////////////////
cma::FollowGround::FollowGround() { }


////////////////////////////////////////
// ~FollowGround
////////////////////////////////////////
cma::FollowGround::~FollowGround() { }


////////////////////////////////////////
// creator
////////////////////////////////////////
void * cma::FollowGround::creator(void) {
	return new FollowGround;
}


////////////////////////////////////////
// initialize
////////////////////////////////////////
MStatus cma::FollowGround::initialize(void) {

	//アトリビュートの追加
	try {
		_addAttr_outPoint();
		_addAttr_inMesh();
		_addAttr_rayVector();
		_addAttr_rayPoint();
	}
	catch (const MStatusException & e) {
		std::cerr << e.toString() << std::endl;
		return e.stat;
	}
	
	return MStatus::kSuccess;
}


////////////////////////////////////////
// compute
////////////////////////////////////////
MStatus cma::FollowGround::compute(const MPlug & plug, MDataBlock & data) {
	MStatus ret;
	try {
		if (plug == this->outPoint) {
			//入力アトリビュート値取得
			MDataHandle ground, ray_from, ray_vector;
			_getInputValue(data, &ground, &ray_from, &ray_vector);

			bool is_cross = false;
			_getLengthToCrossPoint(ground.asMesh(), VectorF(ray_from.asFloat3()), VectorF(ray_vector.asFloat3()), &is_cross);


			

			_setOutputValue(data, 0.0, 0.0f, 0.0f);
			data.setClean(plug);
		}
	}
	catch (MStatusException e) {
		std::cerr << e.toString() << std::endl;
	}
	return MStatus::kSuccess;
}

void cma::FollowGround::_getInputValue(MDataBlock & data, MDataHandle * ground, MDataHandle * ray_from, MDataHandle * ray_vector) {
	MStatus ret;
	*ground = data.inputValue(inMesh, &ret);
	MStatusException::throwIfError(ret, "groundメッシュの取得に失敗", "cma::FollowGround::_getInputValue");
	*ray_from = data.inputValue(rayPoint, &ret);
	MStatusException::throwIfError(ret, "レイ始点の取得に失敗", "cma::FollowGround::_getInputValue");
	*ray_vector = data.inputValue(rayVector, &ret);
	MStatusException::throwIfError(ret, "レイベクトルの取得に失敗", "cma::FollowGround::_getInputValue");
}

void cma::FollowGround::_setOutputValue(MDataBlock & data, const float x, const float y, const float z) {
	MStatus ret;
	MDataHandle outputHandle = data.outputValue(outPoint, &ret);
	MStatusException::throwIfError(ret, "outPointの取得に失敗", "cma::FollowGround::_setOutputValue");	
	outputHandle.set(x,y,z);
}

double cma::FollowGround::_getLengthToCrossPoint(const MObject & ground, const VectorF ray_point, const VectorF ray_vector, bool * is_cross, const double max_distance) {
	MStatus ret;

	MItMeshPolygon face_iter(ground, &ret);
	MStatusException::throwIfError(ret, "ポリゴンフェースイテレータの取得に失敗", "cma::FollowGround::_getLengthToCrossPoint");

	MFnMesh ground_mesh(ground, &ret);
	MStatusException::throwIfError(ret, "ポリゴンフェースの取得に失敗", "cma::FollowGround::_getLengthToCrossPoint");

	MPointArray points;
	MIntArray vertexes;
	int triangle_num;
	constexpr double epsilon = 0.00001;
	auto isEqual = [epsilon](double a, double b) -> bool {
		return (epsilon > (a - b) && -epsilon < (a - b));
	};

	for (; !face_iter.isDone(); face_iter.next()) {
		//三角面の数を取得
		ret = face_iter.numTriangles(triangle_num);
		MStatusException::throwIfError(ret, "三角面数の取得に失敗", "cma::FollowGround::_getLengthToCrossPoint");

		for (int idx = 0; idx < triangle_num; idx++) {
			//三角面を取得
			face_iter.getTriangle(idx, points, vertexes);
			MStatusException::throwIfError(ret, "三角フェースデータの取得に失敗", "cma::FollowGround::_getLengthToCrossPoint");
			
			//チェック関数
			//check()


		}

	}

	return 0.0;
}

/*
lobal proc vector[] getDownsidePolygons(string $ground_object, vector $points[], vector $rays[]){    
    int $i,$n;
    int $face_num[] = `polyEvaluate -face ($ground_object)`;    //頂点数
    float $epsilon = 0.000001;
    
    vector $ret[];
        
    for($i = 0; $i < $face_num[0]; $i++){
        $plist = `polyListComponentConversion -fromFace -toVertex ($ground_object + ".f[" + $i + "]")`;
        string $vertexes[] = `filterExpand -sm 31 $plist`;
        if(size($vertexes) != 3) error "三角化を行ってください";
        
        vector $vec[3] = {
            float3ToVector(`xform -query -ws -t $vertexes[0]`),
            float3ToVector(`xform -query -ws -t $vertexes[1]`),
            float3ToVector(`xform -query -ws -t $vertexes[2]`)};
                
        vector $edge1 = $vec[1] - $vec[0];
        vector $edge2 = $vec[2] - $vec[0];
        
        $n = 0;
        for($n = 0;$n < size($points); $n++){
            vector $ray = $rays[$n];
            
            vector $invRay = -1 * $ray;
            float $denominator = det($edge1, $edge2, $invRay);
            
            if(!(-$epsilon < $denominator && $denominator < $epsilon)){
                //レイが平面と平行ではない
                vector $d = $points[$n] - $vec[0];
                float $u = det($d, $edge2, $invRay) / $denominator;
                
                if((0 <= $u) && ($u <= 1)){
                    float $v = det($edge1, $d, $invRay) / $denominator;
                    
                    if((0 <= $v) && ($u + $v <= 1.0)){
                        float $t = det($edge1, $edge2, $d) / $denominator;
                        if($t >= 0){
                            //交差している
                            $ret[$n] = $ray * $t;
                        }
                    } 
                }
            }
        }
    }
    return $ret;
}*/