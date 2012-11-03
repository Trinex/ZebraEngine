/**
* TypeCast function
*
* @file TypeCast.h
* @author Sebastian Salonen
* @date 20120409 - Initial Release
*/
#ifndef TYPECAST_H
#define TYPECAST_H


namespace Data
{
    
//==============================================================================

template<class X, class Y>
inline Y typeCast(X _from)
{
	union{ X a; Y b;};
	a = _from;

	return b;
};

//==============================================================================

}

#endif