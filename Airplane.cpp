//
// Created by alonj on 6/21/18.
//

#include "Airplane.h"

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
    return (_name == name);
}

template<typename T>
bool Airplane<T>::isEqual(const Airplane &otherAirplane) const {
    return _name == otherAirplane.getName();
}
