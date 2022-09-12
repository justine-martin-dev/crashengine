#include "CrashEngine/math/vecs.hpp"

#include <cmath>
#include <iostream>

namespace crashengine::math {
    template<typename T, int components>
    Vec<T, components>::Vec() : componentAmount(components), dataType(crashengine::getDataType(T())), content() {}

    template<typename T, int components>
    Vec<T, components>::Vec(const std::array<T, components> &content) : componentAmount(components),
                                                                        dataType(crashengine::getDataType(T())), content(content) {}

    template<typename T, int components>
    Vec<T, components>::Vec(const Vec<T, components> &o) {
        for (size_t i = 0; i < components; ++i) {
            this->content[i] = o[i];
        }
    }

    template<typename T, int components>
    T& Vec<T, components>::operator[](const size_t &index) {
        return this->content[index];
    }

    template<typename T, int components>
    T Vec<T, components>::operator[](const size_t &index) const {
        return this->content[index];
    }

    template<typename T, int components>
    size_t Vec<T, components>::getComponentAmount() const {
        return this->componentAmount;
    }

    template<typename T, int components>
    DataType Vec<T, components>::getDataType() const {
        return this->dataType;
    }

    template<typename T, int components>
    std::array<T, components> Vec<T, components>::getContent() const {
        return this->content;
    }

    template<typename T, int components>
    T Vec<T, components>::getSum() const {
        T acc(0);

        for (size_t i = 0; i < components; ++i) {
            acc += this->content[i];
        }

        return acc;
    }

    template<typename T, int components>
    T Vec<T, components>::getNorm() const {
        T acc(0);

        for (size_t i = 0; i < components; ++i) {
            acc += std::pow(this->content[i], 2);
        }

        return sqrt(acc);
    }

    template<typename T, int components>
    T Vec<T, components>::dot(const Vec<T, components> &o) const {
        T acc(0);

        for (size_t i = 0; i < components; ++i) {
            acc += this->content[i] * o.content[i];
        }

        return acc;
    }

    template<typename T, int components>
    Vec<T, components> Vec<T, components>::cross(const Vec<T, components> &o) const {
        std::cout << "[ERROR] : CROSS PRODUCT IS UNIMPLEMENTED UNTIL MATRICES ARE IMPLEMENTED THEMSELVES" << std::endl;
        return Vec<T, components>(*this);
    }

    template<typename T, int components>
    Vec<T, components> &Vec<T, components>::normalize() {
        T norm = this->getNorm();

        for (size_t i = 0; i < components; ++i) {
            this->content[i] /= norm;
        }

        return *this;
    }

    template<typename T, int components>
    Vec<T, components> Vec<T, components>::getNormalized() const {
        Vec<T, components> newVec(*this);
    
        return newVec.normalize();
    }

    template<typename T, int components>
    Vec<T, components> &Vec<T, components>::operator*=(const T &scalar) {
        for (size_t i = 0; i < components; ++i) {
            this->content[i] *= scalar;
        }

        return *this;
    }

    template<typename T, int components>
    Vec<T, components> &Vec<T, components>::operator/=(const T &scalar) {
        for (size_t i = 0; i < components; ++i) {
            this->content[i] /= scalar;
        }

        return *this;
    }

    template<typename T, int components>
    Vec<T, components> &Vec<T, components>::operator+=(const T &scalar) {
        for (size_t i = 0; i < components; ++i) {
            this->content[i] += scalar;
        }

        return *this;
    }

    template<typename T, int components>
    Vec<T, components> &Vec<T, components>::operator-=(const T &scalar) {
        for (size_t i = 0; i < components; ++i) {
            this->content[i] -= scalar;
        }

        return *this;
    }

    template<typename T, int components>
    Vec<T, components> Vec<T, components>::operator*(const T &scalar) const {
        Vec<T, components> newVec(*this);
        newVec *= scalar;

        return newVec;
    }

    template<typename T, int components>
    Vec<T, components> Vec<T, components>::operator/(const T &scalar) const {
        Vec<T, components> newVec(*this);
        newVec /= scalar;

        return newVec;
    }

    template<typename T, int components>
    Vec<T, components> Vec<T, components>::operator+(const T &scalar) const {
        Vec<T, components> newVec(*this);
        newVec += scalar;

        return newVec;
    }

    template<typename T, int components>
    Vec<T, components> Vec<T, components>::operator-(const T &scalar) const {
        Vec<T, components> newVec(*this);
        newVec -= scalar;

        return newVec;
    }

    template<typename T, int components>
    Vec<T, components> &Vec<T, components>::operator*=(const Vec<T, components> &o) {
        for (size_t i = 0; i < components; ++i) {
            this->content[i] *= o.content[i];
        }

        return *this;
    }

    template<typename T, int components>
    Vec<T, components> &Vec<T, components>::operator/=(const Vec<T, components> &o) {
        for (size_t i = 0; i < components; ++i) {
            this->content[i] /= o.content[i];
        }

        return *this;
    }

    template<typename T, int components>
    Vec<T, components> &Vec<T, components>::operator+=(const Vec<T, components> &o) {
        for (size_t i = 0; i < components; ++i) {
            this->content[i] += o.content[i];
        }

        return *this;
    }

    template<typename T, int components>
    Vec<T, components> &Vec<T, components>::operator-=(const Vec<T, components> &o) {
        for (size_t i = 0; i < components; ++i) {
            this->content[i] -= o.content[i];
        }

        return *this;
    }

    template<typename T, int components>
    Vec<T, components> Vec<T, components>::operator*(const Vec<T, components> &o) const {
        Vec<T, components> newVec(*this);

        for (size_t i = 0; i < components; ++i) {
            newVec[i] *= o[i];
        }

        return newVec;
    }

    template<typename T, int components>
    Vec<T, components> Vec<T, components>::operator/(const Vec<T, components> &o) const {
        Vec<T, components> newVec(*this);

        for (size_t i = 0; i < components; ++i) {
            newVec[i] /= o[i];
        }

        return newVec;
    }

    template<typename T, int components>
    Vec<T, components> Vec<T, components>::operator+(const Vec<T, components> &o) const {
        Vec<T, components> newVec(*this);

        for (size_t i = 0; i < components; ++i) {
            newVec[i] += o[i];
        }

        return newVec;
    }

    template<typename T, int components>
    Vec<T, components> Vec<T, components>::operator-(const Vec<T, components> &o) const {
        Vec<T, components> newVec(*this);

        for (size_t i = 0; i < components; ++i) {
            newVec[i] -= o[i];
        }

        return newVec;
    }

    template<typename T, int components>
    std::ostream &Vec<T, components>::operator<<(std::ostream &os) {
        std::string s("Vec<type=");

        s += getDataTypeName(this->dataType);

        s += std::string(", components=");
        s += std::to_string(components);
        s += std::string(">{");

        for (size_t i = 0; i < components; ++i) {
            s += std::to_string(this->content[i]);
            s += std::string(", ");
        }

        s.substr(0, s.length()-2);
        s += std::string("}");

        os << s;

        return os;
    }
}
