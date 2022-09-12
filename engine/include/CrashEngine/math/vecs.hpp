#pragma once

#include <array>
#include <ostream>

#include  "CrashEngine/utiliy.hpp"

namespace crashengine::math {
    template<typename T, int components>
    class Vec {
        protected:
            size_t                    componentAmount;
            DataType                  dataType; 
            std::array<T, components> content;
        
        public:
            Vec();
            Vec(const std::array<T, components> &content);
            Vec(const Vec<T, components> &o);

            T &operator[](const size_t &index);
            T  operator[](const size_t &index) const;

            size_t                    getComponentAmount() const;
            DataType                  getDataType() const;
            std::array<T, components> getContent() const;

            T getSum() const;
            T getNorm() const;

            T dot(const Vec<T, components> &o) const;
            Vec<T, components> cross(const Vec<T, components> &o) const;

            Vec<T, components> &normalize();
            Vec<T, components>  getNormalized() const;

            Vec<T, components> &operator*=(const T &scalar);
            Vec<T, components> &operator/=(const T &scalar);
            Vec<T, components> &operator+=(const T &scalar);
            Vec<T, components> &operator-=(const T &scalar);

            Vec<T, components> operator*(const T &scalar) const;
            Vec<T, components> operator/(const T &scalar) const;
            Vec<T, components> operator+(const T &scalar) const;
            Vec<T, components> operator-(const T &scalar) const;

            Vec<T, components> &operator*=(const Vec<T, components> &o);
            Vec<T, components> &operator/=(const Vec<T, components> &o);
            Vec<T, components> &operator+=(const Vec<T, components> &o);
            Vec<T, components> &operator-=(const Vec<T, components> &o);

            Vec<T, components> operator*(const Vec<T, components> &o) const;
            Vec<T, components> operator/(const Vec<T, components> &o) const;
            Vec<T, components> operator+(const Vec<T, components> &o) const;
            Vec<T, components> operator-(const Vec<T, components> &o) const;

            std::ostream &operator<<(std::ostream &os);
    };

    template class Vec<float,          2>;
    template class Vec<double,         2>;
    template class Vec<char,           2>;
    template class Vec<short,          2>;
    template class Vec<int,            2>;
    template class Vec<unsigned char,  2>;
    template class Vec<unsigned short, 2>;
    template class Vec<unsigned int,   2>;

    template class Vec<float,          3>;
    template class Vec<double,         3>;
    template class Vec<char,           3>;
    template class Vec<short,          3>;
    template class Vec<int,            3>;
    template class Vec<unsigned char,  3>;
    template class Vec<unsigned short, 3>;
    template class Vec<unsigned int,   3>;

    template class Vec<float,          4>;
    template class Vec<double,         4>;
    template class Vec<char,           4>;
    template class Vec<short,          4>;
    template class Vec<int,            4>;
    template class Vec<unsigned char,  4>;
    template class Vec<unsigned short, 4>;
    template class Vec<unsigned int,   4>;
}
