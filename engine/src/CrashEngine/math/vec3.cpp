#include "CrashEngine/math/vec3.hpp"

namespace crashengine::math {
    template<typename T>
    Vec3<T>::Vec3() : Vec<T, 3>() {}

    template<typename T>
    Vec3<T>::Vec3(const std::array<T, 3> &content) : Vec<T, 3>(content) {}

    template<typename T>
    Vec3<T>::Vec3(const T &x, const T &y, const T &z) : Vec<T, 3>({x, y, z}) {}
    /**********************
     *** VEC3 SWIZZLING ***
     **********************/

    template<typename T>
    T Vec3<T>::x() const {
        return this->content[0];
    }

    template<typename T>
    T Vec3<T>::y() const {
        return this->content[1];
    }

    template<typename T>
    T Vec3<T>::z() const {
        return this->content[2];
    }
    
    template<typename T>
    std::array<T, 2> Vec3<T>::xy() const {
        return {this->content[0], this->content[1]};
    }

    template<typename T>
    std::array<T, 2> Vec3<T>::yz() const {
        return {this->content[1], this->content[2]};
    }

    template<typename T>
    std::array<T, 2> Vec3<T>::xz() const {
        return {this->content[0], this->content[2]};
    }
    
    template<typename T>
    std::array<T, 2> Vec3<T>::yx() const {
        return {this->content[1], this->content[0]};
    }

    template<typename T>
    std::array<T, 2> Vec3<T>::zy() const {
        return {this->content[2], this->content[1]};
    }

    template<typename T>
    std::array<T, 2> Vec3<T>::zx() const {
        return {this->content[2], this->content[0]};
    }

    template<typename T>
    std::array<T, 3> Vec3<T>::xyz() const {
        return {this->content[0], this->content[1], this->content[2]};
    }

    template<typename T>
    std::array<T, 3> Vec3<T>::yzx() const {
        return {this->content[1], this->content[2], this->content[0]};
    }

    template<typename T>
    std::array<T, 3> Vec3<T>::zxy() const {
        return {this->content[2], this->content[0], this->content[1]};
    }

    template<typename T>
    std::array<T, 3> Vec3<T>::zyx() const {
        return {this->content[2], this->content[1], this->content[0]};
    }

    template<typename T>
    std::array<T, 3> Vec3<T>::xzy() const {
        return {this->content[0], this->content[2], this->content[1]};
    }
    
    template<typename T>
    std::array<T, 3> Vec3<T>::yxz() const {
        return {this->content[1], this->content[0], this->content[2]};
    }

    template<typename T>
    Vec3<T> &Vec3<T>::x(const T &value) {
        this->content[0] = value;
        return *this;
    }
    
    template<typename T>
    Vec3<T> &Vec3<T>::y(const T &value) {
        this->content[1] = value;
        return *this;
    }

    template<typename T>
    Vec3<T> &Vec3<T>::z(const T &value) {
        this->content[2] = value;
        return *this;
    }

    template<typename T>
    Vec3<T> &Vec3<T>::xy(const T &first, const T &second) {
        this->content[0] = first;
        this->content[1] = second;
        return *this;
    }

    template<typename T>
    Vec3<T> &Vec3<T>::yz(const T &first, const T &second) {
        this->content[1] = first;
        this->content[2] = second;
        return *this;
    }

    template<typename T>
    Vec3<T> &Vec3<T>::xz(const T &first, const T &second) {
        this->content[0] = first;
        this->content[2] = second;
        return *this;
    }

    template<typename T>
    Vec3<T> &Vec3<T>::yx(const T &first, const T &second) {
        this->content[1] = first;
        this->content[0] = second;
        return *this;
    }

    template<typename T>
    Vec3<T> &Vec3<T>::zy(const T &first, const T &second) {
        this->content[2] = first;
        this->content[1] = second;
        return *this;
    }

    template<typename T>
    Vec3<T> &Vec3<T>::zx(const T &first, const T &second) {
        this->content[2] = first;
        this->content[0] = second;
        return *this;
    }

    template<typename T>
    Vec3<T> &Vec3<T>::xyz(const T &first, const T &second, const T &third) {
        this->content[0] = first;
        this->content[1] = second;
        this->content[2] = third;
        return *this;
    }

    template<typename T>
    Vec3<T> &Vec3<T>::yzx(const T &first, const T &second, const T &third) {
        this->content[1] = first;
        this->content[2] = second;
        this->content[0] = third;
        return *this;
    }

    template<typename T>
    Vec3<T> &Vec3<T>::zxy(const T &first, const T &second, const T &third) {
        this->content[2] = first;
        this->content[0] = second;
        this->content[1] = third;
        return *this;
    }

    template<typename T>
    Vec3<T> &Vec3<T>::zyx(const T &first, const T &second, const T &third) {
        this->content[2] = first;
        this->content[1] = second;
        this->content[0] = third;
        return *this;
    }

    template<typename T>
    Vec3<T> &Vec3<T>::xzy(const T &first, const T &second, const T &third) {
        this->content[0] = first;
        this->content[2] = second;
        this->content[1] = third;
        return *this;
    }

    template<typename T>
    Vec3<T> &Vec3<T>::yxz(const T &first, const T &second, const T &third) {
        this->content[1] = first;
        this->content[0] = second;
        this->content[2] = third;
        return *this;
    }

    template<typename T>
    Vec3<T> &Vec3<T>::xy(const std::array<T, 2> &value) {
        this->xy(value[0], value[1]);
        return *this;
    }
    template<typename T>
    Vec3<T> &Vec3<T>::yz(const std::array<T, 2> &value) {
        this->yz(value[0], value[1]);
        return *this;
    }

    template<typename T>
    Vec3<T> &Vec3<T>::xz(const std::array<T, 2> &value) {
        this->xz(value[0], value[1]);
        return *this;
    }

    template<typename T>
    Vec3<T> &Vec3<T>::yx(const std::array<T, 2> &value) {
        this->yx(value[0], value[1]);
        return *this;
    }

    template<typename T>
    Vec3<T> &Vec3<T>::zy(const std::array<T, 2> &value) {
        this->zy(value[0], value[1]);
        return *this;
    }

    template<typename T>
    Vec3<T> &Vec3<T>::zx(const std::array<T, 2> &value) {
        this->zx(value[0], value[1]);
        return *this;
    }

    template<typename T>
    Vec3<T> &Vec3<T>::xyz(const std::array<T, 3> &value) {
        this->xyz(value[0], value[1], value[2]);
        return *this;
    }

    template<typename T>
    Vec3<T> &Vec3<T>::yzx(const std::array<T, 3> &value) {
        this->yzx(value[0], value[1], value[2]);
        return *this;
    }

    template<typename T>
    Vec3<T> &Vec3<T>::zxy(const std::array<T, 3> &value) {
        this->zxy(value[0], value[1], value[2]);
        return *this;
    }

    template<typename T>
    Vec3<T> &Vec3<T>::zyx(const std::array<T, 3> &value) {
        this->zyx(value[0], value[1], value[2]);
        return *this;
    }

    template<typename T>
    Vec3<T> &Vec3<T>::xzy(const std::array<T, 3> &value) {
        this->xzy(value[0], value[1], value[2]);
        return *this;
    }

    template<typename T>
    Vec3<T> &Vec3<T>::yxz(const std::array<T, 3> &value) {
        this->yxz(value[0], value[1], value[2]);
        return *this;
    }
}
