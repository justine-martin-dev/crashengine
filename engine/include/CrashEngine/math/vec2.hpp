#pragma once

#include "CrashEngine/math/vecs.hpp"

namespace crashengine::math {
    template<typename T>
    class Vec2 : public Vec<T, 2> {
        public:
            Vec2();
            Vec2(const std::array<T, 2> &content);
            Vec2(const T &x, const T &y);

            T x() const;
            T y() const;
            std::array<T, 2> xy() const;
            std::array<T, 2> yx() const;

            Vec2<T> &x(const T &value);
            Vec2<T> &y(const T &value);

            Vec2<T> &xy(const T &first, const T &second);
            Vec2<T> &yx(const T &first, const T &second);

            Vec2<T> &xy(const std::array<T, 2> &value);
            Vec2<T> &yx(const std::array<T, 2> &value);
    };
    
    template class Vec2<float>;
    template class Vec2<double>;
    template class Vec2<char>;
    template class Vec2<short>;
    template class Vec2<int>;
    template class Vec2<unsigned char>;
    template class Vec2<unsigned short>;
    template class Vec2<unsigned int>;
}
