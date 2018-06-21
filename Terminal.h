#ifndef TERMINAL_H
#define TERMINAL_H
 
#include <iostream>
#include <sstream>
#include <vector>
#include "Airplane.h"

#define A "A"
#define D "D"
#define PRINT "PRINT"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;


template<typename T>
class Terminal
{
private:
	string					_termnType;
	const T					_maxTermnLoad;
	vector< Airplane<T>* >	_vecAirplanes;
	T						_terminalLoad;

public:
	Terminal(const string& termnType, T maxTermnLoad ): _termnType(termnType),
														_maxTermnLoad(maxTermnLoad){};
	Terminal(const Terminal& otherTerminal): _termnType(otherTerminal.get_termnType()),
											_maxTermnLoad(otherTerminal.get_maxTermnLoad()){};

	~Terminal();

	void beginSession();

	bool addPlane( Airplane<T>* newAirplane );
	bool delPlane( Airplane<T>* newAirplane );
	bool hasPlane( const string& name ) const;

	const string &get_termnType() const {
		return _termnType;
	}

	const T get_maxTermnLoad() const {
		return _maxTermnLoad;
	}

	void print() const;
};


//*********************************************************************
//********************** YOUR CODE STARTS HERE ************************
//*********************************************************************


#endif
