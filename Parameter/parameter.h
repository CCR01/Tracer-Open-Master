////////////////////////////////////////////////////////////
/// \file parameter.h
/// \brief include file for class Parameter
///  \date 07.04.2017
///  \author Tobias Haist  (haist@ito.uni-stuttgart.de)
///  Institute of Applied Optics, University of Stuttgart ITO 
///  Paffenwaldring 9
///  70569 Stuttgart
///  Germany
/// 

#ifndef PARAMETER_HPP 
#define PARAMETER_HPP

#include "..\basicdefinition\basicdefinitions.h"

#include <iostream>

enum typeModifier { typeModifierFixed, typeModifierVariable, typeModifierPickup };

enum localStart { radiusStart, positionStart, randomStart };

////////////////////////////////////////////////////////////
///  \brief Parameter manages changeable Parameters (e.g. for optimization)
////////////////////////////////////////////////////////////
///  
///  The template class stores the actual or mean value together with the allowed
///  variation (given as a standard deviation) and allowed minimum and
///  maximum value. This is used e.g. for tolerancing and optimization
///
///  The parameters minimum, maximum, stdDev in principle only make sense
///  for numerical parameters.
///  However, we also will have the case that parameters can vary
///  based on some discrete values (e.g. internal index number in glass catalog)
///  out of a list of certain parameters.
///  the main application is responsible to make the translation in this case
///  from integer values to certain usable parameters.
///  (If this is necessary at not only a few places in the code, we might
///   add in the future an additional helper class to handle this translation)
///
///  class should be instantiated for real(double), int, string
///
///  \date 07.4.2017
///  \author Tobias Haist  (haist@ito.uni-stuttgart.de)
////////////////////////////////////////////////////////////
template <class Type>
class Parameter {

public:
	Parameter();                          ///< std ctor
	explicit Parameter(Type x);           ///< construction with global coordinates

	void set(Type x);                     ///< set Value to x 
	Type getValue() const;                     ///< get the Value
	void setMinimum(Type x);              ///< set the minimum value to x 
	Type getMinimum() const;              ///< get the minimum Value
	void setMaximum(Type x);              ///< set the maximum value to x 
	Type getMaximum() const;              ///< get the maximum Value
	void setStdDev(Type x);               ///< set the standard deviation of Value
	Type getStdDev() const;               ///< get the standard deviation of Value
	void setModifier(typeModifier x);     ///< set the modifier
	typeModifier getModifier() const;     ///< get the modifier
	void swap(Parameter& para1);          ///< swap functionality

protected:
	Type mValue;			///< (mean) value of parameter
	Type mMin;			///< minimum allowed value of paramter
	Type mMax;			///< maximum allowed value of paramter
	Type mStdDev;			///< standard deviation of parameter (for tolerancing)
	typeModifier mModifier;       ///< is this a variable or fixed or pickup
};

#include "parameter.tpp"

#endif
