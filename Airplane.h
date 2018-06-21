#ifndef AIRPLANE_H
#define AIRPLANE_H
 
#include <string>

using std::string;

template<typename T> class Airplane
{
	private:
		const string _name;
		T			 _load;

	public:
		Airplane( const string& name, const T& load ) : _name(name), _load(load) {};
		Airplane( const Airplane& otherAirplane ) :_name(otherAirplane.getName()),
												   _load(otherAirplane.getLoad()){};

		~Airplane(){};

		bool	isEqual( const string& name ) const;
		bool	isEqual( const Airplane& otherAirplane ) const;
		string	getName() const;
		T		getLoad() const;

};




//*********************************************************************
//********************** YOUR CODE STARTS HERE ************************
//*********************************************************************

template<typename T>
string Airplane<T>::getName() const {
    return _name;
}

template<typename T>
T Airplane<T>::getLoad() const {
    return _load;
}

template<typename T>
bool Airplane<T>::isEqual(const string &name) const {
    return _name == name;
}

template<typename T>
bool Airplane<T>::isEqual(const Airplane &otherAirplane) const {
    return _name == otherAirplane.getName();
}


#endif
