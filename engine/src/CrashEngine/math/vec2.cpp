#include "CrashEngine/math/vec2.hpp"

namespace crashengine::math {
    template<typename T>
    Vec2<T>::Vec2() : Vec<T, 2>() {}

    template<typename T>
    Vec2<T>::Vec2(const std::array<T, 2> &content) : Vec<T, 2>(content) {}

    template<typename T>
    Vec2<T>::Vec2(const T &x, const T &y) : Vec<T, 2>({x, y}) {}

    template<typename T>
    T Vec2<T>::x() const {
        return this->content[0];
    }

    template<typename T>
    T Vec2<T>::y() const {
        return this->content[1];
    }

    template<typename T>
    std::array<T, 2> Vec2<T>::xy() const {
        return {this->content[0], this->content[1]};
    }

    template<typename T>
    std::array<T, 2> Vec2<T>::yx() const {
        return {this->content[1], this->content[0]};
    }

    template<typename T>
    Vec2<T> &Vec2<T>::x(const T &value) {
        this->content[0] = value;
        return *this;
    }

    template<typename T>
    Vec2<T> &Vec2<T>::y(const T &value) {
        this->content[1] = value;
        return *this;
    }

    template<typename T>
    Vec2<T> &Vec2<T>::xy(const T &first, const T &second) {
        this->content[0] = first;
        this->content[1] = second;
        return *this;
    }

    template<typename T>
    Vec2<T> &Vec2<T>::yx(const T &first, const T &second) {
        this->content[1] = first;
        this->content[0] = second;
        return *this;
    }

    template<typename T>
    Vec2<T> &Vec2<T>::xy(const std::array<T, 2> &value) {
        this->xy(value[0], value[1]);
        return *this;
    }

    template<typename T>
    Vec2<T> &Vec2<T>::yx(const std::array<T, 2> &value) {
        this->yx(value[0], value[1]);
        return *this;
    }
}
