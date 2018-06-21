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
														_maxTermnLoad(maxTermnLoad)
	{_terminalLoad = 0;};
	Terminal(const Terminal& otherTerminal): _termnType(otherTerminal.get_termnType()),
											_maxTermnLoad(otherTerminal.get_maxTermnLoad())
	{_terminalLoad = 0;};

	~Terminal(){};

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

template<typename T>
bool Terminal<T>::addPlane(Airplane<T> *newAirplane) {
	if(this->hasPlane(newAirplane->getName())) {
		cout << "The plane is already registered: " << newAirplane->getName() << endl;
		return false;
	}
	else if (_terminalLoad + newAirplane->getLoad() > _maxTermnLoad) {
			cout << "Not enough free space for: " << newAirplane->getName() << endl;
			return false;
		}
	else{
		_vecAirplanes.push_back(newAirplane);
		_terminalLoad += newAirplane->getLoad();
		return true;
	}
}

template<typename T>
bool Terminal<T>::delPlane(Airplane<T> *newAirplane) {
	string name = newAirplane->getName();
	bool planeRegistered = false;
	typename vector<Airplane<T>*>::iterator it = _vecAirplanes.begin();
	for(; it != _vecAirplanes.end(); it++)
		if((*it)->isEqual(name)){
			planeRegistered = true;
			break;
		}
	if(!planeRegistered){
		cout << "The plane was not registered: " << newAirplane->getName() << endl;
		return false;
	}
	else if (_terminalLoad < newAirplane->getLoad()){
		cout << "Not enough allocated objects for: " << newAirplane->getName() << endl;
		return false;
	}
	else{
		_vecAirplanes.erase(it);
		_terminalLoad -= newAirplane->getLoad();
		return true;
	}
}

template<typename T>
bool Terminal<T>::hasPlane(const string &name) const {
	for(typename vector< Airplane<T>* >::const_iterator cit = _vecAirplanes.begin(); cit != _vecAirplanes.end(); cit++)
		if((*cit)->isEqual(name))
			return true;
	return false;
}

template<typename T>
void Terminal<T>::print() const {
	if(_vecAirplanes.empty()) return;
	typename vector< Airplane<T>*>::const_iterator cit = _vecAirplanes.begin();
	while(cit != _vecAirplanes.end())
		cout << (*cit++)->getName() << endl;
}

template<typename T>
void Terminal<T>::beginSession() {
	string line, mode, name;
	T load;
	bool funcReturn = true;
	while(!cin.eof()){
		getline(cin, line);
		std::stringstream ss(line);
		ss >> mode >> name >> load;
		Airplane<T>* newAirplane = new Airplane<T>(name, load);
		if(mode == A)
			funcReturn = addPlane(newAirplane);
		else if(mode == D)
			funcReturn = delPlane(newAirplane);
		else if(mode == PRINT)
			print();
		if(!funcReturn)
			cout << "Unknown error occurred while handling: " << name << endl;
	}
}


#endif
