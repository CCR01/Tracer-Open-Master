#include "RayFan.h"
#include "..\LowLevelTracing\Interaction\Absorb_LLT.h"


double RayFan::calcMaxX(std::vector<VectorStructR3> vector)
{
	double maxX;
	std::vector<double> vectorX;
	for (unsigned int k = 0; k < vector.size(); k++)
	{
		vectorX.push_back(vector.at(k).getX());

	}
	maxX = Math::maxValueOfVactor(vectorX);

	return maxX;
}
double RayFan::calcMaxY(std::vector<VectorStructR3> vector)
{
	double maxY;
	std::vector<double> vectorY;
	for (unsigned int k = 0; k < vector.size(); k++)
	{
		vectorY.push_back(vector.at(k).getY());

	}
	maxY = Math::maxValueOfVactor(vectorY);
	return maxY;
}

QVector<double> RayFan::getXX()
{
	return X_Values_X_Plane;
}
QVector<double> RayFan::getXY()
{
	return Y_Values_X_Plane;
}
QVector<double> RayFan::getYX()
{
	return X_Values_Y_Plane;
}
QVector<double> RayFan::getYY()
{
	return Y_Values_Y_Plane;
}
QPolygonF RayFan::getRayFanXPlanePoints()
{
	return Ray_Image_X_Plane_Qwt;
}
QPolygonF RayFan::getRayFanYPlanePoints()
{
	return Ray_Image_Y_Plane_Qwt;
}


void RayFan::calcMatrixRayFanPlane()
{
	
	    //single ray tracing of the optical system without the entrance pupil
	    SequentialRayTracing seqTrace_X_Plane(mOptSys);
		// do sequential ray tracing with a vector of many LightRay to the optical system without the entrance pupil
		seqTrace_X_Plane.seqRayTracingWithVectorOfLightRays(mLightRayX);
		//single ray tracing of the optical system without the entrance pupil 
		SequentialRayTracing seqTraceWithEntrancePupil_X_Plane(mOptSysWithEntrancePupil);
		// do sequential ray tracing with a vector of many LightRay to the optical system with the entrance pupil
		seqTraceWithEntrancePupil_X_Plane.seqRayTracingWithVectorOfLightRays(mLightRayX);

		//same but to the Y Plane parameters
		SequentialRayTracing seqTrace_Y_Plane(mOptSys);
		seqTrace_Y_Plane.seqRayTracingWithVectorOfLightRays(mLightRayY);
		SequentialRayTracing seqTraceWithEntrancePupil_Y_Plane(mOptSysWithEntrancePupil);
		seqTraceWithEntrancePupil_Y_Plane.seqRayTracingWithVectorOfLightRays(mLightRayY);

	    //extract intersection points vector from system with entrance pupil
		double maxRayXValueXPlan = calcMaxX(seqTraceWithEntrancePupil_X_Plane.getAllInterPointsAtSurf_i_notFiltered(mPosEnPupilInOptSys));
		double maxRayXValueYPlane = calcMaxX(seqTraceWithEntrancePupil_Y_Plane.getAllInterPointsAtSurf_i_notFiltered(mPosEnPupilInOptSys));
		
		double maxRayYValueXPlan = calcMaxY(seqTraceWithEntrancePupil_X_Plane.getAllInterPointsAtSurf_i_notFiltered(mPosImageSurface));
		double maxRayYValueYPlane = calcMaxY(seqTraceWithEntrancePupil_Y_Plane.getAllInterPointsAtSurf_i_notFiltered(mPosImageSurface));


		//fill vector X information of the Ray Fan plot
		//The X values are the normalized entrance pupil coordinate in tangential & sagittal planes
		for (unsigned int i = 1; i < seqTraceWithEntrancePupil_X_Plane.getAllInterPointsAtSurf_i_notFiltered(mPosEnPupilInOptSys).size(); i++)
		{
		//The position of the curve in the X axis is obtained as the difference between the coordinate of the ray and the coordinate of the chief ray in the entrance pupil position at the corresponding plane
			double X_XPlane = seqTraceWithEntrancePupil_X_Plane.getAllInterPointsAtSurf_i_notFiltered(mPosEnPupilInOptSys).at(i).getX()/ maxRayXValueXPlan;
			X_Values_X_Plane.push_back(X_XPlane);
			
			double X_YPlane = seqTraceWithEntrancePupil_X_Plane.getAllInterPointsAtSurf_i_notFiltered(mPosEnPupilInOptSys).at(i).getY()/ maxRayXValueYPlane;
			X_Values_Y_Plane.push_back(X_YPlane);
			
		}

		//fill vector Y information of the Ray Fan plot
		// the Y values are the the ray aberration: the distance, orthogonal to the optical axis, between  a paraxial ray and its corresponding real ray 
		for (unsigned int j = 1; j < seqTrace_X_Plane.getAllInterPointsAtSurf_i_notFiltered(mPosImageSurface).size(); j++)
		{		
				//the position of the curve in the Y axis is obtained as the difference between the coordinate of the ray and the coordinate of the chief ray at the corresponding plane in the image surface position
				double deltaX =  seqTrace_X_Plane.getAllInterPointsAtSurf_i_notFiltered(mPosImageSurface).at(j).getX();
				Y_Values_X_Plane.push_back(deltaX);
		
				double deltaY = seqTrace_Y_Plane.getAllInterPointsAtSurf_i_notFiltered(mPosImageSurface).at(j).getY();
				Y_Values_Y_Plane.push_back(deltaY);
					
		}
		
		
		//fill the vectors with the corresponding coordinates
		for (unsigned int k = 0; k < X_Values_X_Plane.size(); k++)
		{
			QPointF pointMeridional;
			pointMeridional.setX(X_Values_X_Plane[k]);
			pointMeridional.setY(Y_Values_X_Plane[k]);
			Ray_Image_X_Plane_Qwt.push_back(pointMeridional);

			QPointF pointSagittal;
			pointSagittal.setX(X_Values_X_Plane[k]);
			pointSagittal.setY(Y_Values_X_Plane[k]);
			Ray_Image_Y_Plane_Qwt.push_back(pointSagittal);

		}
		
	}



int RayFan::calcPosEnPupil_Z()
{
	unsigned int i = 0.0;
	unsigned int size = mOptSys.getPosAndInteractingSurface().size();
	//
	
	for (i; i < size; ++i)
	{
		real Z = mOptSys.getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr()->getPoint().getZ();
		if (Z >= mEntrancePupil->getPoint().getZ())
		{
			return mOptSys.getPosAndInteractingSurface()[i].getPosition();
		}
	}

	return i;
}


