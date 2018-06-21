//
// Created by alonj on 6/21/18.
//

#include "Terminal.h"


template<typename T>
bool Terminal<T>::addPlane(Airplane<T> *newAirplane) {
    if(this->hasPlane(newAirplane->getName()))
        return false;
    else
        _vecAirplanes.push_back(newAirplane);
}

template<typename T>
bool Terminal<T>::delPlane(Airplane<T> *newAirplane) {
    string name = newAirplane->getName();
    for(vector<Airplane<T>*>::iterator it = _vecAirplanes.begin(); it != _vecAirplanes.end(); it++)
        if((*it)->isEqual(name)){
        _vecAirplanes.erase(it);
        return true;
    }
    return false;
}

template<typename T>
bool Terminal<T>::hasPlane(const string &name) const {
    for(vector< Airplane<T>* >::const_iterator cit = _vecAirplanes.begin(); cit != _vecAirplanes.end(); cit++)
        if((*cit)->isEqual(name))
            return true;
    return false;
}