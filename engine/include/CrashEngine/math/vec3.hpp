#pragma once

#include "CrashEngine/math/vecs.hpp"

namespace crashengine::math {
    template<typename T>
    class Vec3 : public Vec<T, 3> {
        public:
            Vec3();
            Vec3(const std::array<T, 3> &content);
            Vec3(const T &x, const T &y, const T &z);
    
            T x() const;
            T y() const;
            T z() const;
            std::array<T, 2> xy() const;
            std::array<T, 2> yz() const;
            std::array<T, 2> xz() const;
            std::array<T, 2> yx() const;
            std::array<T, 2> zy() const;
            std::array<T, 2> zx() const;
            std::array<T, 3> xyz() const;
            std::array<T, 3> yzx() const;
            std::array<T, 3> zxy() const;
            std::array<T, 3> zyx() const;
            std::array<T, 3> xzy() const;
            std::array<T, 3> yxz() const;

            Vec3<T> &x(const T &value);
            Vec3<T> &y(const T &value);
            Vec3<T> &z(const T &value);
            Vec3<T> &xy(const T &first, const T &second);
            Vec3<T> &yz(const T &first, const T &second);
            Vec3<T> &xz(const T &first, const T &second);
            Vec3<T> &yx(const T &first, const T &second);
            Vec3<T> &zy(const T &first, const T &second);
            Vec3<T> &zx(const T &first, const T &second);
            Vec3<T> &xyz(const T &first, const T &second, const T &third);
            Vec3<T> &yzx(const T &first, const T &second, const T &third);
            Vec3<T> &zxy(const T &first, const T &second, const T &third);
            Vec3<T> &zyx(const T &first, const T &second, const T &third);
            Vec3<T> &xzy(const T &first, const T &second, const T &third);
            Vec3<T> &yxz(const T &first, const T &second, const T &third);

            Vec3<T> &xy(const std::array<T, 2> &value);
            Vec3<T> &yz(const std::array<T, 2> &value);
            Vec3<T> &xz(const std::array<T, 2> &value);
            Vec3<T> &yx(const std::array<T, 2> &value);
            Vec3<T> &zy(const std::array<T, 2> &value);
            Vec3<T> &zx(const std::array<T, 2> &value);
            Vec3<T> &xyz(const std::array<T, 3> &value);
            Vec3<T> &yzx(const std::array<T, 3> &value);
            Vec3<T> &zxy(const std::array<T, 3> &value);
            Vec3<T> &zyx(const std::array<T, 3> &value);
            Vec3<T> &xzy(const std::array<T, 3> &value);
            Vec3<T> &yxz(const std::array<T, 3> &value);
    };

    template class Vec3<float>;
    template class Vec3<double>;
    template class Vec3<char>;
    template class Vec3<short>;
    template class Vec3<int>;
    template class Vec3<unsigned char>;
    template class Vec3<unsigned short>;
    template class Vec3<unsigned int>;
}
