#include "AsphericalSurface_LLT.h"
#include "..\Math_LLT.h"
#include "..\BaseTransformation_LLT.h"
#include "..\Light_LLT.h"

double isDerivationAsphere::getDerivation() const&
{
	return derivation;
}

//get radius asphere
real AsphericalSurface_LLT::getRadius()
{
	return mRadiusAsphere;
}

//set radius asphere
void AsphericalSurface_LLT::setRadiusAsphere(real const& radius)
{
	mRadiusAsphere = radius;
}

// get semi height asphere
real AsphericalSurface_LLT::getSemiHeight()
{
	return mSemiHeightAsphere;
}

//set semi height asphere
void AsphericalSurface_LLT::setSemiHeight(real semiHeigth)
{
	mSemiHeightAsphere = semiHeigth;
}

//get point asphere
VectorStructR3 AsphericalSurface_LLT::getPoint()
{
	return mPointAsphere;
}

// set point asphere
void AsphericalSurface_LLT::setPoint(VectorStructR3 point)
{
	mPointAsphere = point;
}


// set direction asphere unit
void AsphericalSurface_LLT::setDirectionUnitAsphere(VectorStructR3 const& direction)
{
	mDirectionAsphereUnit = Math::unitVector(direction);
}

//get direction asphere
VectorStructR3 AsphericalSurface_LLT::getDirection() 
{
	return mDirectionAsphereUnit;
}

//set direction aspere
void AsphericalSurface_LLT::setDirectionAsphere(VectorStructR3 const& direction)
{
	mDirectionAsphere = direction;
}

//get refractive index side A
real AsphericalSurface_LLT::getRefracIndexAsphere_A() const&
{
	return mRefractiveSideA_Asphere;
}

//set refractive index side A
void AsphericalSurface_LLT::setRefractiveIndexSide_A(real const& refractiveIndex)
{
	mRefractiveSideA_Asphere = refractiveIndex;
}

//get refractive index side B
real AsphericalSurface_LLT::getRefracIndexAsphere_B() const&
{
	return mRefractiveSideB_Asphere;
}

//set refractive index side B
void AsphericalSurface_LLT::setRefractiveIndexSide_B(real const& refractiveIndex)
{
	mRefractiveSideB_Asphere = refractiveIndex;
}

//get conic
real AsphericalSurface_LLT::getConic() const&
{
	return mConic;
}

//set conic
void AsphericalSurface_LLT::setConic(real const& conic)
{
	mConic = conic;
}

//get A1
real AsphericalSurface_LLT::getA1() const&
{
	return m_A1;
}

//set A1
void AsphericalSurface_LLT::setA1(real const& A1)
{
	m_A1 = A1;
}

//get A2
real AsphericalSurface_LLT::getA2() const&
{
	return m_A2;
}

//set A2
void AsphericalSurface_LLT::setA2(real const& A2)
{
	m_A2 = A2;
}

//get A3
real AsphericalSurface_LLT::getA3() const&
{
	return m_A3;
}

//set A3
void AsphericalSurface_LLT::setA3(real const& A3)
{
	m_A3 = A3;
}

//get A4
real AsphericalSurface_LLT::getA4() const&
{
	return m_A4;
}

//set A4
void AsphericalSurface_LLT::setA4(real const& A4)
{
	m_A4 = A4;
}

//get A5
real AsphericalSurface_LLT::getA5() const&
{
	return m_A5;
}

//set A5
void AsphericalSurface_LLT::setA5(real const& A5)
{
	m_A5 = A5;
}

//get A6
real AsphericalSurface_LLT::getA6() const&
{
	return m_A6;
}

//set A6
void AsphericalSurface_LLT::setA6(real const& A6)
{
	m_A6 = A6;
}

//get A7
real AsphericalSurface_LLT::getA7() const&
{
	return m_A7;
}

//set A7
void AsphericalSurface_LLT::setA7(real const& A7)
{
	m_A7 = A7;
}

//get A8
real AsphericalSurface_LLT::getA8() const&
{
	return m_A8;
}

//set A8
void AsphericalSurface_LLT::setA8(real const& A8)
{
	m_A8 = A8;
}

//calculate z of an aspherical surface in point Q projected on the aspherical surface

is_Z_ValueAsphere AsphericalSurface_LLT::calc_Z_ValueAsphere(double const& x, double const& y)
{	
	is_Z_ValueAsphere returnIs_Z_ValueAsphere;
	double PointToZ_Achse = pow(x, 2) + pow(y, 2);
	double sqrtTerm = 1.0 - (1.0 + mConic)*pow(1.0 / mRadiusAsphere, 2)*PointToZ_Achse;
	if (sqrtTerm <= 0) //there is no intersection pont
	{
		returnIs_Z_ValueAsphere.yesNo = 0;
	}
	else //there must be an intersection point
	{
					returnIs_Z_ValueAsphere = {
			 (1 / mRadiusAsphere*PointToZ_Achse) / (1.0 + std::sqrt(sqrtTerm)) +
			mPrefix * m_A1 * /*r^2*/ PointToZ_Achse +
			mPrefix * m_A2 * /*r^4*/ pow(PointToZ_Achse, 2) +
			mPrefix * m_A3 * /*r^6*/ pow(PointToZ_Achse, 3) +
			mPrefix * m_A4 * /*r^8*/ pow(PointToZ_Achse, 4) +
			mPrefix * m_A5 * /*r^10*/pow(PointToZ_Achse, 5) +
			mPrefix * m_A6 * /*r^12*/pow(PointToZ_Achse, 6) +
			mPrefix * m_A7 * /*r^14*/pow(PointToZ_Achse, 7) +
			mPrefix * m_A8 * /*r^16*/pow(PointToZ_Achse, 8)
			,
			1 };


	};

	return returnIs_Z_ValueAsphere;
}

// Projection of a point in z direction
VectorStructR3 AsphericalSurface_LLT::Q_projection(double const& x, double const& y, double const& z)
{
	return{ x,y,z };
}



// Calculate rise of asphere in x-direction
isDerivationAsphere AsphericalSurface_LLT::rise_X_AsphericalSurface(double const& x, double const& y)
{
	isDerivationAsphere returnRiseX;
	double PointToZ_Achse = pow(x, 2) + pow(y, 2);
	double sqrtTerm = 1 - pow((1 / mRadiusAsphere), 2)*(mConic + 1)*PointToZ_Achse;
	if (sqrtTerm < 0)
	{
		returnRiseX.yesNo = 0;
	}
	else {

		return{ (-(1 / mRadiusAsphere)*x*std::sqrt(sqrtTerm)) / (pow((1 / mRadiusAsphere),2)*(mConic + 1)*PointToZ_Achse - 1) +
			mPrefix * 2.0 * m_A1*x +
			mPrefix * 4.0 * m_A2*x* PointToZ_Achse +
			mPrefix * 6.0 * m_A3*x*pow(PointToZ_Achse, 2) +
			mPrefix * 8.0 * m_A4*x*pow(PointToZ_Achse, 3) +
			mPrefix * 10.0 * m_A5*x*pow(PointToZ_Achse, 4) +
			mPrefix * 12.0 * m_A6*x*pow(PointToZ_Achse, 5) +
			mPrefix * 14.0 * m_A7*x*pow(PointToZ_Achse, 6) +
			mPrefix * 16.0 * m_A8*x*pow(PointToZ_Achse, 7)
		, 1
		};
	}
}

isDerivationAsphere AsphericalSurface_LLT::rise_Y_AsphericalSurface(double const&  x, double const& y)
{
	isDerivationAsphere returnRiseY;
	double PointToZ_Achse = pow(x, 2) + pow(y, 2);
	double sqrtTerm = 1 - pow((1 / mRadiusAsphere), 2)*(mConic + 1)*PointToZ_Achse;
	if (sqrtTerm < 0)
	{
		returnRiseY.yesNo = 0;
	}
	else {

		return{ (-(1 / mRadiusAsphere)*y*std::sqrt(sqrtTerm)) / (pow((1 / mRadiusAsphere),2)*(mConic + 1)*PointToZ_Achse - 1) +
			mPrefix * 2.0 * m_A1*y +
			mPrefix * 4.0 * m_A2*y*PointToZ_Achse +
			mPrefix * 6.0 * m_A3*y*pow(PointToZ_Achse, 2) +
			mPrefix * 8.0 * m_A4*y*pow(PointToZ_Achse, 3) +
			mPrefix * 10.0 * m_A5*y*pow(PointToZ_Achse, 4) +
			mPrefix * 12.0 * m_A6*y*pow(PointToZ_Achse, 5) +
			mPrefix * 14.0 * m_A7*y*pow(PointToZ_Achse, 6) +
			mPrefix * 16.0 * m_A8*y*pow(PointToZ_Achse, 7)
		,1 };
	}
}

IntersectInformationStruct AsphericalSurface_LLT::calculateIntersection(LightRayStruct const& lightRay)
{	

	IntersectInformationStruct returnIntersectInfos;
	Ray_LLT ray = lightRay.getRay_LLT();
	Light_LLT light = lightRay.getLight_LLT();


	double tolerance = 0.001; // TODO Question: Welche Toleranz ist hier sinnvoll???
	//Matrix3x3AndExist transMatrix = BaseTransformation_LLT::CalcBaseTransformationMatrix(ray.getDirectionRay());
	VectorStructR3 Q1_projectionLocalCoordiSystem;
	double limit = 9e-14; // TODO Question: Welches limit ist hier entscheident???
	double distanceQP = 1.0;
	double steps_T_RayToTangentialPlaneLocalCoordiSystem;
	is_Z_ValueAsphere zValueAsphere;
	VectorStructR3 P1_IntersectionPointRayTangenteLOCALCoordiSystem;
	Matrix3x3AndExist TransformationMatrix = BaseTransformation_LLT::CalcBaseTransformationMatrix(mDirectionAsphereUnit);
	VectorStructR3 transDirectionRay = Math::multiplyMatrix3x3VectorR3(TransformationMatrix.Matrix, ray.getDirectionRayUnit());
	
	// in com
	Ray_LLT transRay = BaseTransformation_LLT::transformRayInNewBase(ray, TransformationMatrix.Matrix, mPointAsphere);
	VectorStructR3 transAspherePoint = { 0.0,0.0,0.0 };
	VectorStructR3 transAsphereDirecUnit = Math::multiplyMatrix3x3VectorR3(TransformationMatrix.Matrix, mDirectionAsphereUnit);
	
	isDerivationAsphere riseXLocalCoodiSystem;
	isDerivationAsphere riseYLocalCoordiSystem;

	//TODO QUESTION: In der folgenden Funktion kommen die ganzen Terme höherer Ordnung der Asphäre zu tragen.
	// Diese sind oft Null. Daraus folgt, dass oft der hintere Teil der Gleichng um z (zValueAsphere) zu berechen garnicht 
	// beachtet werden müssen. --> Kann hier die Gleichung hinsichtlich der Rechengeschwindigkeit optimiert werden? 
	// if (A1 = 0) -> Term muss nicht berechnet werden
	// if (A2 = 0) -> Term muss nicht berechnet werden
	// ...
	// Des Weiteren wäre es schön, wenn die Terme höherer Ordnung (A1 bis A8) immer Null sind, wenn der Benutzer nichts anderes verlangt.
	// --> Wie kann dies eingestellt werden?

	//__________________________________________________________
	// 1. Intersection Point Q0 with the vertex plane of the asphere
	// d = Dx*X+Dy*Y+Dz*Z
	double d_VertexPlaneAsphericalSurface = transAsphereDirecUnit*transAspherePoint;
	// calculate the intersection point of the ray and the vertex plane
	//d = Dx*(Ox+t*Dx)+Dy*(Oy+t*Dy)+Dz*(Oz+t*Dz) => t
	double denominator = transAsphereDirecUnit*transRay.getDirectionRayUnit();
	
	if ( abs(denominator) < tolerance)
	{
		returnIntersectInfos = { { 0.0,0.0,0.0 },{ 0.0,0.0,0.0 },N, 0.0,0.0,0.0,{ 0.0,0.0,0.0 },light}; //'N' there is NO intersection poin
	}
	else
	{
		double nominator = d_VertexPlaneAsphericalSurface - transAsphereDirecUnit.x*transRay.getOriginRay().x - transAsphereDirecUnit.y*transRay.getOriginRay().y - transAsphereDirecUnit.z*transRay.getOriginRay().z;
		if (abs(nominator) < tolerance)
		{
			// ray is in flat!
				// TODO Question: Was soll dann gemacht werden?!?!?! hier hat man ja dann unendlich viele Schnittpunkte 	
			returnIntersectInfos = { { 0.0,0.0,0.0 },{ 0.0,0.0,0.0 },N, 0.0,0.0,0.0,{ 0.0,0.0,0.0 }, light }; //'N' there is NO intersection poin
																											// -> Das ist ja dann eigentlich falsch?! -> es gibt ja viele Schnittpunkte!
		}

		else
		{
			// calculate the stepsT the ray has to walk to the intersection point with the vertex plan of the asphere
			double stepsT = nominator / denominator;
			if (stepsT < 0) //ray would walk in the wrong direction
			{
				returnIntersectInfos = { { 0.0,0.0,0.0 },{ 0.0,0.0,0.0 },N, 0.0,0.0,0.0,{ 0.0,0.0,0.0 }, light }; //'N' there is NO intersection poin
			}
			else
			{	
				// calculate the intersection point Q0 - ray with vertex plane of the asphere 
				VectorStructR3 Q0_vertex_LocalCoordinateSystem = transRay.getOriginRay() + stepsT*transRay.getDirectionRayUnit();
				Q0_vertex_LocalCoordinateSystem.z = 0.0; //to stop rounding error

				// TODO QUESTION siehe unten -> hier soll dann der loop beginnen

				//double stepsQ0LocalToVertexPlane = (d_VertexPlaneAsphericalSurface - mDirectionAsphereUnit*Q0_vertex_LocalCoordinateSystem) / (mDirectionAsphereUnit*mDirectionAsphereUnit);
				int Interations = 1; 
				while (distanceQP > limit)/*TODOQUESTION: Welcher Wert ist hier angemessen*/ //&& Interations < 1000)
				{

					
					// calculate the z value of the asphere for the projected point Q0
					zValueAsphere = calc_Z_ValueAsphere(Q0_vertex_LocalCoordinateSystem.getX(), Q0_vertex_LocalCoordinateSystem.getY());
					
					if (zValueAsphere.yesNo == 0) //there is no intersection point
					{
						distanceQP = limit - 1.0; /*check Value! to go out of "while"*/
						returnIntersectInfos = { { 0.0,0.0,0.0 },{ 0.0,0.0,0.0 },N, 0.0,0.0,0.0,{ 0.0,0.0,0.0 }, light }; //'N' there is NO intersection poin
					}
					else { // there must be an intersection point
					// 2. Approximate solution Q1 on the surface as a z-projection
						Q1_projectionLocalCoordiSystem = { Q0_vertex_LocalCoordinateSystem.x, Q0_vertex_LocalCoordinateSystem.y, zValueAsphere.Z_Value };

						// To calculate the rise of the tangential plan in point Q1(x,y) on the aspherical surface we made a partial derivative of the z=... equation 
						// Calculate rise of asphere in x-direction
						riseXLocalCoodiSystem = rise_X_AsphericalSurface(Q1_projectionLocalCoordiSystem.x, Q1_projectionLocalCoordiSystem.y);
						if (riseXLocalCoodiSystem.yesNo == 0)
						{
							distanceQP = limit - 1.0;
							returnIntersectInfos = { { 0.0,0.0,0.0 },{ 0.0,0.0,0.0 },N, 0.0,0.0,0.0,{ 0.0,0.0,0.0 }, light }; //'N' there is NO intersection poin
						}
						else
						{ 
						// Calculate rise of asphere in y-direction
						riseYLocalCoordiSystem = rise_Y_AsphericalSurface(Q1_projectionLocalCoordiSystem.x, Q1_projectionLocalCoordiSystem.y);
						if (riseYLocalCoordiSystem.yesNo == 0)
						{
							distanceQP = limit - 1.0;
							returnIntersectInfos = { { 0.0,0.0,0.0 },{ 0.0,0.0,0.0 },N, 0.0,0.0,0.0,{ 0.0,0.0,0.0 }, light }; //'N' there is NO intersection poin
						}
						else
						{
						/*With the equation
						z=z0+fx(x0,y0)*(x-x0)+fy(x0,y0)*(y-y0) we get the coordinate form of the tangential plane on the
						aspherical surface in point Q1(x1,y1).
						Next we put the ray: g: (x,y,z)=(xs,ys,zs)+ stepT * (xd,yd,zd) into the tangential plane
						and solve for stepsT.
						So we get:
						*/
						

						//steps_T_RayToTangentialPlane = (ray.getOriginRay().Z - Q1_projectionGlobalCoordindatSystem.Z + mPointAsphere.Z + riseX*(ray.getOriginRay().X - Q1_projection.X + mPointAsphere.X) + riseY*(ray.getOriginRay().Y - Q1_projection.Y + mPointAsphere.Y)) / (ray.getDirectionRayUnit().Z - ray.getDirectionRayUnit().X*riseX - ray.getDirectionRayUnit().Y*riseY);
						steps_T_RayToTangentialPlaneLocalCoordiSystem = (-transRay.getOriginRay().getZ() + Q1_projectionLocalCoordiSystem.getZ() + riseXLocalCoodiSystem.derivation*(transRay.getOriginRay().getX() - Q1_projectionLocalCoordiSystem.getX()) + riseYLocalCoordiSystem.derivation*(transRay.getOriginRay().getY() - Q1_projectionLocalCoordiSystem.getY())) / (-riseXLocalCoodiSystem.derivation*transRay.getDirectionRayUnit().getX() - riseYLocalCoordiSystem.derivation*transRay.getDirectionRayUnit().getY() + transRay.getDirectionRayUnit().getZ());
						// To get the  intersection point between ray and tangential plane we put stepsT into the Ray equation
						P1_IntersectionPointRayTangenteLOCALCoordiSystem = transRay.getOriginRay() + steps_T_RayToTangentialPlaneLocalCoordiSystem * transRay.getDirectionRayUnit();
						
						// Calculate the distance between the intersection point between ray and tangential plane =P1= "P1_IntersectionPointRayTangente" and 
						// approximate solution Q1 on the surface as a z-projection

						distanceQP = Math::distanceTwoVectors(Q1_projectionLocalCoordiSystem, P1_IntersectionPointRayTangenteLOCALCoordiSystem);
						//zValueAsphere = calc_Z_ValueAsphere(P1_IntersectionPointRayTangente.X - mPointAsphere.X, P1_IntersectionPointRayTangente.Y-mPointAsphere.Y);
						Q0_vertex_LocalCoordinateSystem.x = P1_IntersectionPointRayTangenteLOCALCoordiSystem.x;
						Q0_vertex_LocalCoordinateSystem.y = P1_IntersectionPointRayTangenteLOCALCoordiSystem.y;
						
						//Q1_projection = Q_projection(P1_IntersectionPointRayTangente.X - mPointAsphere.X, P1_IntersectionPointRayTangente.Y - mPointAsphere.Y, zValueAsphere.Z_Value);
						//______________________
						++Interations;
						//______________________
						}
					}
					}
				}


				// calculate the intersection point in the global coorindat system
				Matrix3x3AndExist backTransMatrix = BaseTransformation_LLT::calcInversMatrix(TransformationMatrix.Matrix);
				VectorStructR3 IntersectionPointRayAsphereGlobalCoordiSystem = Math::multiplyMatrix3x3VectorR3(backTransMatrix.Matrix, P1_IntersectionPointRayTangenteLOCALCoordiSystem) + mPointAsphere;

				returnIntersectInfos.setIntersectionPoint(IntersectionPointRayAsphereGlobalCoordiSystem);

				//check if intersection point is in aspherical surface
				double shortestDistanceDirection_IntersectionPoint = Math::lengthOfVector(Math::DoCrossProduct(mDirectionAsphereUnit, (IntersectionPointRayAsphereGlobalCoordiSystem - mPointAsphere))) / Math::lengthOfVector(mDirectionAsphereUnit);
				if (mSemiHeightAsphere <= shortestDistanceDirection_IntersectionPoint)
				{
					returnIntersectInfos.setSurface(N);
				}

				else { // intersection point is in aspherical surface

					returnIntersectInfos.setRefractiveIndex_A(mRefractiveSideA_Asphere);
					returnIntersectInfos.setRefractiveIndex_B(mRefractiveSideB_Asphere);
					returnIntersectInfos.setStepsToWalk(Math::distanceTwoVectors(ray.getOriginRay(), IntersectionPointRayAsphereGlobalCoordiSystem));
					returnIntersectInfos.setDirectionRayUnit(ray.getDirectionRayUnit());
					returnIntersectInfos.setLight(light);

					if (ray.getCurrentRefractiveIndex() == mRefractiveSideA_Asphere) //ray comes from side A
					{
						returnIntersectInfos.setSurface(A);
						returnIntersectInfos.setNormalUnitVector(Math::multiplyMatrix3x3VectorR3(backTransMatrix.Matrix, Math::unitVector({ riseXLocalCoodiSystem.getDerivation(),riseYLocalCoordiSystem.getDerivation(),-1 })));
											
					}
					else // ray must come from side B
					{
						returnIntersectInfos.setSurface(B);
						returnIntersectInfos.setNormalUnitVector(-1 * Math::multiplyMatrix3x3VectorR3(backTransMatrix.Matrix, Math::unitVector({ riseXLocalCoodiSystem.getDerivation(),riseYLocalCoordiSystem.getDerivation(),-1 })));
						
					}

				}
			}
		}
	}

	return returnIntersectInfos;
}



// calculate the focal lenght of the aspherical surface
double AsphericalSurface_LLT::calcFolcalLengthAsphericalSurface()
{
	// TODO: Das muss ich noch fertig machen^^
	double focalLenAsphericalSurface = 1.0;
	
	return focalLenAsphericalSurface;
	
}

//set and get the prefix of the aspherical lens.
void AsphericalSurface_LLT::setPrefixAsphere(VectorStructR3 V)
{
	if (mDirectionAsphere.getZ() < 0)
	{
		mPrefix = -1;
	}

	else mPrefix = 1;
}

int AsphericalSurface_LLT::getPrefixAsphere()
{
	return mPrefix;
}


// get focal length side A
real AsphericalSurface_LLT::getFocalLength_A()
{
	std::cout << "we can not calculate the focal length of an aspherical length! there will be an mistake" << std::endl;
	return 999;
}
// get focal length side B
real AsphericalSurface_LLT::getFocalLength_B()
{
	std::cout << "we can not calculate the focal length of an aspherical length! there will be an mistake" << std::endl;
	return 999;
}

// get refractive index side A
real AsphericalSurface_LLT::getRefractiveIndex_A()
{
	return mRefractiveSideA_Asphere;
}
// get refractive index side B
real AsphericalSurface_LLT::getRefractiveIndex_B()
{
	return mRefractiveSideB_Asphere;
}

void AsphericalSurface_LLT::plot2D(cv::Mat image, unsigned int scale, unsigned int thickness, unsigned int lineType)
{
	// TODO: make the 2D Plot
}

AsphericalSurface_LLT::AsphericalSurface_LLT(AsphericalSurface_LLT &source)
{
	if (this == &source)
	{
		return;
	}

	mRadiusAsphere = source.mRadiusAsphere;
	mSemiHeightAsphere = source.mSemiHeightAsphere;
	mPointAsphere = source.mPointAsphere;
	mDirectionAsphereUnit = source.mDirectionAsphereUnit;
	mDirectionAsphere = source.mDirectionAsphere;
	mRefractiveSideA_Asphere = source.mRefractiveSideA_Asphere;
	mRefractiveSideB_Asphere = source.mRefractiveSideB_Asphere;
	mConic = source.mConic;
	m_A1 = source.m_A1;
	m_A2 = source.m_A2;
	m_A3 = source.m_A3;
	m_A4 = source.m_A4;
	m_A5 = source.m_A5;
	m_A6 = source.m_A6;
	m_A7 = source.m_A7;
	m_A8 = source.m_A8;

	mPrefix = source.mPrefix;

	// TODO: Also copy the spherical informaltion to plot!
	// SphericalSurfaceQwt* SphericalSurface_Qwt_Ptr = new SphericalSurfaceQwt(mRadius, mSemiHeight, mDirection, mPointSphere);
}

AsphericalSurface_LLT& AsphericalSurface_LLT::operator=(AsphericalSurface_LLT& source)
{
	if (this == &source)
	{
		return *this;
	}


	mRadiusAsphere = source.mRadiusAsphere;
	mSemiHeightAsphere = source.mSemiHeightAsphere;
	mPointAsphere = source.mPointAsphere;
	mDirectionAsphereUnit = source.mDirectionAsphereUnit;
	mDirectionAsphere = source.mDirectionAsphere;
	mRefractiveSideA_Asphere = source.mRefractiveSideA_Asphere;
	mRefractiveSideB_Asphere = source.mRefractiveSideB_Asphere;
	mConic = source.mConic;
	m_A1 = source.m_A1;
	m_A2 = source.m_A2;
	m_A3 = source.m_A3;
	m_A4 = source.m_A4;
	m_A5 = source.m_A5;
	m_A6 = source.m_A6;
	m_A7 = source.m_A7;
	m_A8 = source.m_A8;

	mPrefix = source.mPrefix;

	return *this;
}

std::shared_ptr<SurfaceIntersectionRay_LLT> AsphericalSurface_LLT::clone()
{
	std::shared_ptr<SurfaceIntersectionRay_LLT> ashpericalSurface_LLT(new AsphericalSurface_LLT(*this));

	return ashpericalSurface_LLT;
}

void AsphericalSurface_LLT::setRadius(real radius)
{
	mRadiusAsphere = radius;
}
void AsphericalSurface_LLT::setPosition(VectorStructR3 position)
{
	mPointAsphere = position;
}

//get the pointer of the qwt curve
AsphericalSurfaceQwt* AsphericalSurface_LLT::getPointerPlot()
{
	return AsphericalSurfaceQwt_Ptr;
}

//get QPolygonF of the surface
QPolygonF*  AsphericalSurface_LLT::getQPolygonFCurve()
{
	return &pointsofASphericalSurface;
}

AsphericalSurfaceQwt::AsphericalSurfaceQwt(double radius, double semiHeight, VectorStructR3  point, VectorStructR3  direction, double  conic,
	double  A1, double  A2, double  A3, double  A4, double  A5, double  A6, double  A7, double  A8)
{
	setStyle(QwtPlotCurve::Lines);
	setPen(QColor(255, 0, 0), 2);
	setSamples(points(radius, semiHeight, point, direction, conic, A1, A2, A3, A4, A5, A6, A7, A8));
}

QPolygonF AsphericalSurfaceQwt::points(double radius, double semiHeight, VectorStructR3  point, VectorStructR3  direction, double  conic,
	double  A1, double  A2, double  A3, double  A4, double  A5, double  A6, double  A7, double  A8)
{


	unsigned int wide = 1600;
	unsigned int height = 1000;
	// distance to left border
	unsigned int boarterLeft = 50;
	unsigned int scale = 20;

	real prefix = 1.0;
	if (direction.getZ() < 0)
	{
		prefix = -1.0;
	}

	double curvature = prefix * 1 / radius;



	//sampling
	const int numSamples = 10000;

	real y_Direction = direction.getY();
	if (direction.getZ() < 0)
	{
		y_Direction = -direction.getY();
	}

	VectorStructR2 dir2D_Unit = Math::unitVec2D({ direction.getZ(), y_Direction });
	VectorStructR2 point2D{ point.getZ(), y_Direction };
	VectorStructR2 orto2D_Unit = Math::calcOrtoVec2D_Unit({ direction.getZ(), y_Direction });

	// center of sphere in global coordinat system of trace master
	VectorStructR2 centerSphere = point2D + radius * dir2D_Unit;

	// calculate relevant distance to plot according to semiHeight
	double dX_total = radius - (std::sqrt(std::pow(radius, 2) - std::pow(semiHeight, 2)));

	double Xmin = point2D.getX();
	double Xmax = (point2D + dir2D_Unit * dX_total).getX();

	if (Xmin == Xmax) // spherical lens is rotated about plus/minus 90?
	{
		Xmin = point2D.getY();
		Xmax = (point2D + dir2D_Unit * dX_total).getY();
	}

	// calculate staps (deltaX)
	double distanceXminXmax = std::abs(std::abs(Xmax) - std::abs(Xmin));
	double deltaX = distanceXminXmax / numSamples;
	double deltaY = semiHeight / numSamples;

	// the first point to plot is always the apex of the sphere
	VectorStructR2 startPoint2D = point2D;

	double xPlotStartPos = boarterLeft + startPoint2D.getX() * scale;
	double yPlotStartPos = height / 2 - startPoint2D.getY() * scale;

	// the start point is in the beginning the same
	double xPlotStartNeg = xPlotStartPos;
	double yPlotStartNeg = yPlotStartPos;

	double mPrefix = 1;
	if (direction.getZ() < 0)
	{
		mPrefix = -1.0;
	}


	for (int i = numSamples; i > 0; i--)
	{

		double Y_Steps = i * deltaY + deltaY;

		double PointToZ_Achse = pow(0, 2) + pow(Y_Steps, 2);
		double sqrtTerm = 1.0 - (1.0 + conic)*pow(1.0 / radius, 2)*PointToZ_Achse;

		double z =
			(1 / radius * PointToZ_Achse) / (1.0 + std::sqrt(sqrtTerm)) +
			mPrefix * A1 * /*r^2*/ PointToZ_Achse +
			mPrefix * A2 * /*r^4*/ pow(PointToZ_Achse, 2) +
			mPrefix * A3 * /*r^6*/ pow(PointToZ_Achse, 3) +
			mPrefix * A4 * /*r^8*/ pow(PointToZ_Achse, 4) +
			mPrefix * A5 * /*r^10*/pow(PointToZ_Achse, 5) +
			mPrefix * A6 * /*r^12*/pow(PointToZ_Achse, 6) +
			mPrefix * A7 * /*r^14*/pow(PointToZ_Achse, 7) +
			mPrefix * A8 * /*r^16*/pow(PointToZ_Achse, 8);

		VectorStructR2 newPointNeg = point2D + dir2D_Unit * z - orto2D_Unit * Y_Steps;

		double xPlotEndNeg = boarterLeft + newPointNeg.getX() * scale;

		double yPlotEndNeg = height / 2 - newPointNeg.getY() * scale;

		xPlotStartNeg = xPlotEndNeg;
		yPlotStartNeg = yPlotEndNeg;

		AsphericalSurfacePoints << QPointF(xPlotStartNeg, yPlotStartNeg);
		AsphericalSurfacePoints << QPointF(xPlotEndNeg, yPlotEndNeg);

	}

	for (int i = 0; i < numSamples; i++)
	{

		double Y_Steps = i * deltaY + deltaY;

		double PointToZ_Achse = pow(0, 2) + pow(Y_Steps, 2);
		double sqrtTerm = 1.0 - (1.0 + conic)*pow(1.0 / radius, 2)*PointToZ_Achse;

		double z =
			(1 / radius * PointToZ_Achse) / (1.0 + std::sqrt(sqrtTerm)) +
			mPrefix * A1 * /*r^2*/ PointToZ_Achse +
			mPrefix * A2 * /*r^4*/ pow(PointToZ_Achse, 2) +
			mPrefix * A3 * /*r^6*/ pow(PointToZ_Achse, 3) +
			mPrefix * A4 * /*r^8*/ pow(PointToZ_Achse, 4) +
			mPrefix * A5 * /*r^10*/pow(PointToZ_Achse, 5) +
			mPrefix * A6 * /*r^12*/pow(PointToZ_Achse, 6) +
			mPrefix * A7 * /*r^14*/pow(PointToZ_Achse, 7) +
			mPrefix * A8 * /*r^16*/pow(PointToZ_Achse, 8);

		VectorStructR2 newPointPos = point2D + dir2D_Unit * z + orto2D_Unit * Y_Steps;



		double xPlotEndPos = boarterLeft + newPointPos.getX() * scale;

		double yPlotEndPos = height / 2 - newPointPos.getY() * scale;

		xPlotStartPos = xPlotEndPos;
		yPlotStartPos = yPlotEndPos;

		AsphericalSurfacePoints << QPointF(xPlotStartPos, yPlotStartPos);



	}

	return AsphericalSurfacePoints;

}