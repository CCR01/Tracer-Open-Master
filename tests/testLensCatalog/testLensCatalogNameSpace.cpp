#include "testLensCatalogNameSpace.h"

// often use
#include "..\..\oftenUseNamespace\oftenUseNamespace.h"
// absorb
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
// do nothing
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"
// plan surface
#include "..\..\SurfaceElements\PlanElement.h"
// aperture stop
#include "..\..\SurfaceElements\ApertureStopElement.h"

// test one lens with three surfaces;
bool testLensCata::testOneLensThreeSurfaces_startInf_0deg(real wavelength, OpticalSystemElement optSys_HLT, VectorStructR3 positionImageSurface, real rms, real tolerance)
{
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	OpticalSystemElement optSys_HLT_test = optSys_HLT.getDeepCopyOptSysEle();

	MaterialSellmeier1 materialAir;
	materialAir.setParameterAndCalcVd_Ve("Schott", "Air", 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0); // refractive index is 1
	ApertureStopElement AperStop(1.0, { 0.0,0.0, 0.0 }, { 0.0,0.0,1.0 }, materialAir);
	optSys_HLT_test.fillInElementAndInteractionAtPos_i(0, AperStop.clone(), doNothing.clone());

	PlanElement ImageSurface(9999.0, positionImageSurface, { 0.0,0.0,1.0 }, materialAir, materialAir);
	optSys_HLT_test.fillInElementAndInteractionAtPos_i(4, ImageSurface.clone(), absorb.clone());

	// shift achromat
	real pointZ_1 = optSys_HLT_test.getPosAndElement()[1].getElementInOptSys_ptr()->getPointElementValue_Z();
	real pointZ_2 = optSys_HLT_test.getPosAndElement()[2].getElementInOptSys_ptr()->getPointElementValue_Z();
	real pointZ_3 = optSys_HLT_test.getPosAndElement()[3].getElementInOptSys_ptr()->getPointElementValue_Z();

	real shift = 1.0;
	real pointZ_1_new = pointZ_1 + shift;
	real pointZ_2_new = pointZ_2 + shift;
	//real thickness23 = pointZ_3- pointZ_2;
	real pointZ_3_new = pointZ_3 + shift;

	optSys_HLT_test.getPosAndElement()[1].getElementInOptSys_ptr()->setPointElementValue_Z(pointZ_1_new);
	optSys_HLT_test.getPosAndElement()[2].getElementInOptSys_ptr()->setPointElementValue_Z(pointZ_2_new);
	optSys_HLT_test.getPosAndElement()[3].getElementInOptSys_ptr()->setPointElementValue_Z(pointZ_3_new);

	// debug
	oftenUse::print(optSys_HLT_test, 550.0);

	//// ---
	//// debug ->  check single ray tracing
	//VectorStructR3 startPointRay = { 0.0,1.0,0.0 };
	//VectorStructR3 directionRay = { 0.0,0.0,1.0 };
	//VectorStructR3 targetPoint = { 0.0,0.0,0.0 };
	//OpticalSystem_LLT optSys_LLT = optSys_HLT_test.getLLTconversion_doConversion();
	//unsigned int surfaceNum = 99;
	//bool checkSingleRay = oftenUse::checkRayTracing(/*start point ray*/ startPointRay,/*direction ray*/ directionRay,/*target point*/ targetPoint,/*optical system LLT*/ optSys_LLT,/*surface num*/ surfaceNum,/*tolerance*/ tolerance);
	//// ---


	bool checker = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSys_HLT_test, 0.0, 0.0, wavelength, rms, tolerance, compareTOM_Zemax::comEqual);

	return checker;
}

bool testLensCata::testOneLensThreeSurfaces_start0(real wavelength, OpticalSystemElement optSys_HLT, VectorStructR3 positionImageSurface, real rms, real tolerance)
{
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	OpticalSystemElement optSys_HLT_test = optSys_HLT.getDeepCopyOptSysEle();

	MaterialSellmeier1 materialAir;
	materialAir.setParameterAndCalcVd_Ve("Schott", "Air", 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0); // refractive index is 1
	ApertureStopElement AperStop(1.0, { 0.0,0.0, 10.0 }, { 0.0,0.0,1.0 }, materialAir);
	optSys_HLT_test.fillInElementAndInteractionAtPos_i(0, AperStop.clone(), doNothing.clone());

	PlanElement ImageSurface(9999.0, positionImageSurface, { 0.0,0.0,1.0 }, materialAir, materialAir);
	optSys_HLT_test.fillInElementAndInteractionAtPos_i(4, ImageSurface.clone(), absorb.clone());

	// shift achromat
	real pointZ_1 = optSys_HLT_test.getPosAndElement()[1].getElementInOptSys_ptr()->getPointElementValue_Z();
	real pointZ_2 = optSys_HLT_test.getPosAndElement()[2].getElementInOptSys_ptr()->getPointElementValue_Z();
	real pointZ_3 = optSys_HLT_test.getPosAndElement()[3].getElementInOptSys_ptr()->getPointElementValue_Z();

	real shift = 11.0;
	real pointZ_1_new = pointZ_1 + shift;
	real pointZ_2_new = pointZ_2 + shift;
	real pointZ_3_new = pointZ_3 + shift;

	optSys_HLT_test.getPosAndElement()[1].getElementInOptSys_ptr()->setPointElementValue_Z(pointZ_1_new);
	optSys_HLT_test.getPosAndElement()[2].getElementInOptSys_ptr()->setPointElementValue_Z(pointZ_2_new);
	optSys_HLT_test.getPosAndElement()[3].getElementInOptSys_ptr()->setPointElementValue_Z(pointZ_3_new);

	// debug
	oftenUse::print(optSys_HLT_test, 550.0);

	bool checker = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSys_HLT_test, { 0.0,0.0,0.0 }, wavelength, rms, tolerance, compareTOM_Zemax::comEqual);

	return checker;
}

bool testLensCata::testOneLensFourSurfaces_start0(real wavelength, OpticalSystemElement optSys_HLT, VectorStructR3 positionImageSurface, real rms, real tolerance)
{
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	OpticalSystemElement optSys_HLT_test = optSys_HLT.getDeepCopyOptSysEle();

	MaterialSellmeier1 materialAir;
	materialAir.setParameterAndCalcVd_Ve("Schott", "Air", 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0); // refractive index is 1
	ApertureStopElement AperStop(1.0, { 0.0,0.0, 10.0 }, { 0.0,0.0,1.0 }, materialAir);
	optSys_HLT_test.fillInElementAndInteractionAtPos_i(0, AperStop.clone(), doNothing.clone());

	PlanElement ImageSurface(9999.0, positionImageSurface, { 0.0,0.0,1.0 }, materialAir, materialAir);
	optSys_HLT_test.fillInElementAndInteractionAtPos_i(5, ImageSurface.clone(), absorb.clone());

	// shift achromat
	real pointZ_1 = optSys_HLT_test.getPosAndElement()[1].getElementInOptSys_ptr()->getPointElementValue_Z();
	real pointZ_2 = optSys_HLT_test.getPosAndElement()[2].getElementInOptSys_ptr()->getPointElementValue_Z();
	real pointZ_3 = optSys_HLT_test.getPosAndElement()[3].getElementInOptSys_ptr()->getPointElementValue_Z();
	real pointZ_4 = optSys_HLT_test.getPosAndElement()[4].getElementInOptSys_ptr()->getPointElementValue_Z();

	real shift = 11.0;
	real pointZ_1_new = pointZ_1 + shift;
	real pointZ_2_new = pointZ_2 + shift;
	real pointZ_3_new = pointZ_3 + shift;
	real pointZ_4_new = pointZ_4 + shift;

	optSys_HLT_test.getPosAndElement()[1].getElementInOptSys_ptr()->setPointElementValue_Z(pointZ_1_new);
	optSys_HLT_test.getPosAndElement()[2].getElementInOptSys_ptr()->setPointElementValue_Z(pointZ_2_new);
	optSys_HLT_test.getPosAndElement()[3].getElementInOptSys_ptr()->setPointElementValue_Z(pointZ_3_new);
	optSys_HLT_test.getPosAndElement()[4].getElementInOptSys_ptr()->setPointElementValue_Z(pointZ_4_new);

	// debug
	oftenUse::print(optSys_HLT_test, 550.0);

	bool checker = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSys_HLT_test, { 0.0,0.0,0.0 }, wavelength, rms, tolerance, compareTOM_Zemax::comEqual);

	return checker;
}

bool testLensCata::testOneLensFourSurfaces_startInf_0deg(real wavelength, OpticalSystemElement optSys_HLT, VectorStructR3 positionImageSurface, real rms, real tolerance)
{
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	OpticalSystemElement optSys_HLT_test = optSys_HLT.getDeepCopyOptSysEle();

	MaterialSellmeier1 materialAir;
	materialAir.setParameterAndCalcVd_Ve("Schott", "Air", 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0); // refractive index is 1
	ApertureStopElement AperStop(1.0, { 0.0,0.0,0.0 }, { 0.0,0.0,1.0 }, materialAir);
	optSys_HLT_test.fillInElementAndInteractionAtPos_i(0, AperStop.clone(), doNothing.clone());

	PlanElement ImageSurface(9999.0, positionImageSurface, { 0.0,0.0,1.0 }, materialAir, materialAir);
	optSys_HLT_test.fillInElementAndInteractionAtPos_i(5, ImageSurface.clone(), absorb.clone());

	// shift achromat
	real pointZ_1 = optSys_HLT_test.getPosAndElement()[1].getElementInOptSys_ptr()->getPointElementValue_Z();
	real pointZ_2 = optSys_HLT_test.getPosAndElement()[2].getElementInOptSys_ptr()->getPointElementValue_Z();
	real pointZ_3 = optSys_HLT_test.getPosAndElement()[3].getElementInOptSys_ptr()->getPointElementValue_Z();
	real pointZ_4 = optSys_HLT_test.getPosAndElement()[4].getElementInOptSys_ptr()->getPointElementValue_Z();

	real shift = 1.0;
	real pointZ_1_new = pointZ_1 + shift;
	real pointZ_2_new = pointZ_2 + shift;
	real pointZ_3_new = pointZ_3 + shift;
	real pointZ_4_new = pointZ_4 + shift;

	optSys_HLT_test.getPosAndElement()[1].getElementInOptSys_ptr()->setPointElementValue_Z(pointZ_1_new);
	optSys_HLT_test.getPosAndElement()[2].getElementInOptSys_ptr()->setPointElementValue_Z(pointZ_2_new);
	optSys_HLT_test.getPosAndElement()[3].getElementInOptSys_ptr()->setPointElementValue_Z(pointZ_3_new);
	optSys_HLT_test.getPosAndElement()[4].getElementInOptSys_ptr()->setPointElementValue_Z(pointZ_4_new);

	// debug
	oftenUse::print(optSys_HLT_test, 550.0);

	bool checker = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSys_HLT_test, 0.0, 0.0, wavelength, rms, tolerance, compareTOM_Zemax::comEqual);

	return checker;
}

bool testLensCata::testOneLensTwoSurfaces_startInf_0deg(real wavelength, OpticalSystemElement optSys_HLT, VectorStructR3 positionImageSurface, real rms, real tolerance)
{
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	OpticalSystemElement optSys_HLT_test = optSys_HLT.getDeepCopyOptSysEle();

	MaterialSellmeier1 materialAir;
	materialAir.setParameterAndCalcVd_Ve("Schott", "Air", 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0); // refractive index is 1
	ApertureStopElement AperStop(1.0, { 0.0,0.0, 0.0 }, { 0.0,0.0,1.0 }, materialAir);
	optSys_HLT_test.fillInElementAndInteractionAtPos_i(0, AperStop.clone(), doNothing.clone());

	PlanElement ImageSurface(9999.0, positionImageSurface, { 0.0,0.0,1.0 }, materialAir, materialAir);
	optSys_HLT_test.fillInElementAndInteractionAtPos_i(3, ImageSurface.clone(), absorb.clone());

	// shift achromat
	real pointZ_1 = optSys_HLT_test.getPosAndElement()[1].getElementInOptSys_ptr()->getPointElementValue_Z();
	real pointZ_2 = optSys_HLT_test.getPosAndElement()[2].getElementInOptSys_ptr()->getPointElementValue_Z();

	real shift = 1.0;
	real pointZ_1_new = pointZ_1 + shift;
	real pointZ_2_new = pointZ_2 + shift;

	optSys_HLT_test.getPosAndElement()[1].getElementInOptSys_ptr()->setPointElementValue_Z(pointZ_1_new);
	optSys_HLT_test.getPosAndElement()[2].getElementInOptSys_ptr()->setPointElementValue_Z(pointZ_2_new);

	// debug
	oftenUse::print(optSys_HLT_test, 550.0);

	bool checker = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSys_HLT_test, 0.0, 0.0, wavelength, rms, tolerance, compareTOM_Zemax::comEqual);


	return checker;
}

bool testLensCata::testOneLensTwoSurfaces_startInf_0deg(/*size aperture stop*/ real sizeAperStop, real wavelength, OpticalSystemElement optSys_HLT, VectorStructR3 positionImageSurface, real rms, real tolerance)
{
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	OpticalSystemElement optSys_HLT_test = optSys_HLT.getDeepCopyOptSysEle();

	MaterialSellmeier1 materialAir;
	materialAir.setParameterAndCalcVd_Ve("Schott", "Air", 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0); // refractive index is 1
	ApertureStopElement AperStop(sizeAperStop, { 0.0,0.0, 0.0 }, { 0.0,0.0,1.0 }, materialAir);
	optSys_HLT_test.fillInElementAndInteractionAtPos_i(0, AperStop.clone(), doNothing.clone());

	PlanElement ImageSurface(9999.0, positionImageSurface, { 0.0,0.0,1.0 }, materialAir, materialAir);
	optSys_HLT_test.fillInElementAndInteractionAtPos_i(3, ImageSurface.clone(), absorb.clone());

	// shift achromat
	real pointZ_1 = optSys_HLT_test.getPosAndElement()[1].getElementInOptSys_ptr()->getPointElementValue_Z();
	real pointZ_2 = optSys_HLT_test.getPosAndElement()[2].getElementInOptSys_ptr()->getPointElementValue_Z();

	real shift = 1.0;
	real pointZ_1_new = pointZ_1 + shift;
	real pointZ_2_new = pointZ_2 + shift;

	optSys_HLT_test.getPosAndElement()[1].getElementInOptSys_ptr()->setPointElementValue_Z(pointZ_1_new);
	optSys_HLT_test.getPosAndElement()[2].getElementInOptSys_ptr()->setPointElementValue_Z(pointZ_2_new);

	// debug
	oftenUse::print(optSys_HLT_test, 550.0);

	bool checker = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSys_HLT_test, 0.0, 0.0, wavelength, rms, tolerance, compareTOM_Zemax::comEqual);


	return checker;
}

bool testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*size aperture stop*/ real sizeAperStop, real wavelength, OpticalSystemElement optSys_HLT, VectorStructR3 positionImageSurface, real rms, real tolerance)
{
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	OpticalSystemElement optSys_HLT_test = optSys_HLT.getDeepCopyOptSysEle();

	MaterialSellmeier1 materialAir;
	materialAir.setParameterAndCalcVd_Ve("Schott", "Air", 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0); // refractive index is 1
	ApertureStopElement AperStop(sizeAperStop, { 0.0,0.0, 0.0 }, { 0.0,0.0,1.0 }, materialAir);
	optSys_HLT_test.fillInElementAndInteractionAtPos_i(0, AperStop.clone(), doNothing.clone());

	PlanElement ImageSurface(9999.0, positionImageSurface, { 0.0,0.0,1.0 }, materialAir, materialAir);
	optSys_HLT_test.fillInElementAndInteractionAtPos_i(4, ImageSurface.clone(), absorb.clone());

	// shift achromat
	real pointZ_1 = optSys_HLT_test.getPosAndElement()[1].getElementInOptSys_ptr()->getPointElementValue_Z();
	real pointZ_2 = optSys_HLT_test.getPosAndElement()[2].getElementInOptSys_ptr()->getPointElementValue_Z();
	real pointZ_3 = optSys_HLT_test.getPosAndElement()[3].getElementInOptSys_ptr()->getPointElementValue_Z();

	real shift = 1.0;
	real pointZ_1_new = pointZ_1 + shift;
	real pointZ_2_new = pointZ_2 + shift;
	//real thickness23 = pointZ_3- pointZ_2;
	real pointZ_3_new = pointZ_3 + shift;

	optSys_HLT_test.getPosAndElement()[1].getElementInOptSys_ptr()->setPointElementValue_Z(pointZ_1_new);
	optSys_HLT_test.getPosAndElement()[2].getElementInOptSys_ptr()->setPointElementValue_Z(pointZ_2_new);
	optSys_HLT_test.getPosAndElement()[3].getElementInOptSys_ptr()->setPointElementValue_Z(pointZ_3_new);

	// debug
	oftenUse::print(optSys_HLT_test, 550.0);

	//// ---
	//// debug ->  check single ray tracing
	//VectorStructR3 startPointRay = { 0.0,1.0,0.0 };
	//VectorStructR3 directionRay = { 0.0,0.0,1.0 };
	//VectorStructR3 targetPoint = { 0.0,0.0,0.0 };
	//OpticalSystem_LLT optSys_LLT = optSys_HLT_test.getLLTconversion_doConversion();
	//unsigned int surfaceNum = 99;
	//bool checkSingleRay = oftenUse::checkRayTracing(/*start point ray*/ startPointRay,/*direction ray*/ directionRay,/*target point*/ targetPoint,/*optical system LLT*/ optSys_LLT,/*surface num*/ surfaceNum,/*tolerance*/ tolerance);
	//// ---


	bool checker = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSys_HLT_test, 0.0, 0.0, wavelength, rms, tolerance, compareTOM_Zemax::comEqual);

	return checker;
}

bool testLensCata::testOneLensFourSurfaces_startInf_0deg(/*size aperture stop*/ real sizeAperStop, real wavelength, OpticalSystemElement optSys_HLT, VectorStructR3 positionImageSurface, real rms, real tolerance)
{
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	OpticalSystemElement optSys_HLT_test = optSys_HLT.getDeepCopyOptSysEle();

	MaterialSellmeier1 materialAir;
	materialAir.setParameterAndCalcVd_Ve("Schott", "Air", 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0); // refractive index is 1
	ApertureStopElement AperStop(sizeAperStop, { 0.0,0.0,0.0 }, { 0.0,0.0,1.0 }, materialAir);
	optSys_HLT_test.fillInElementAndInteractionAtPos_i(0, AperStop.clone(), doNothing.clone());

	PlanElement ImageSurface(9999.0, positionImageSurface, { 0.0,0.0,1.0 }, materialAir, materialAir);
	optSys_HLT_test.fillInElementAndInteractionAtPos_i(5, ImageSurface.clone(), absorb.clone());

	// shift achromat
	real pointZ_1 = optSys_HLT_test.getPosAndElement()[1].getElementInOptSys_ptr()->getPointElementValue_Z();
	real pointZ_2 = optSys_HLT_test.getPosAndElement()[2].getElementInOptSys_ptr()->getPointElementValue_Z();
	real pointZ_3 = optSys_HLT_test.getPosAndElement()[3].getElementInOptSys_ptr()->getPointElementValue_Z();
	real pointZ_4 = optSys_HLT_test.getPosAndElement()[4].getElementInOptSys_ptr()->getPointElementValue_Z();

	real shift = 1.0;
	real pointZ_1_new = pointZ_1 + shift;
	real pointZ_2_new = pointZ_2 + shift;
	real pointZ_3_new = pointZ_3 + shift;
	real pointZ_4_new = pointZ_4 + shift;

	optSys_HLT_test.getPosAndElement()[1].getElementInOptSys_ptr()->setPointElementValue_Z(pointZ_1_new);
	optSys_HLT_test.getPosAndElement()[2].getElementInOptSys_ptr()->setPointElementValue_Z(pointZ_2_new);
	optSys_HLT_test.getPosAndElement()[3].getElementInOptSys_ptr()->setPointElementValue_Z(pointZ_3_new);
	optSys_HLT_test.getPosAndElement()[4].getElementInOptSys_ptr()->setPointElementValue_Z(pointZ_4_new);

	// debug
	oftenUse::print(optSys_HLT_test, 550.0);

	bool checker = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSys_HLT_test, 0.0, 0.0, wavelength, rms, tolerance, compareTOM_Zemax::comEqual);

	return checker;
}