#include "CrashEngine/math/vec4.hpp"

namespace crashengine::math {
    template<typename T>
    T Vec4<T>::x() const {
        return this->content[0];
    }

    template<typename T>
    T Vec4<T>::y() const {
        return this->content[1];
    }

    template<typename T>
    T Vec4<T>::z() const {
        return this->content[2];
    }

    template<typename T>
    T Vec4<T>::w() const {
        return this->content[3];
    }
    
    template<typename T>
    std::array<T, 2> Vec4<T>::xy() const {
        return {this->content[0], this->content[1]};
    }

    template<typename T>
    std::array<T, 2> Vec4<T>::xz() const {
        return {this->content[0], this->content[2]};
    }

    template<typename T>
    std::array<T, 2> Vec4<T>::xw() const {
        return {this->content[0], this->content[3]};
    }

    template<typename T>
    std::array<T, 2> Vec4<T>::yz() const {
        return {this->content[1], this->content[2]};
    }

    template<typename T>
    std::array<T, 2> Vec4<T>::yw() const {
        return {this->content[1], this->content[3]};
    }

    template<typename T>
    std::array<T, 2> Vec4<T>::zw() const {
        return {this->content[2], this->content[3]};
    }

    template<typename T>
    std::array<T, 2> Vec4<T>::yx() const {
        return {this->content[1], this->content[0]};
    }

    template<typename T>
    std::array<T, 2> Vec4<T>::zx() const {
        return {this->content[2], this->content[0]};
    }

    template<typename T>
    std::array<T, 2> Vec4<T>::wx() const {
        return {this->content[3], this->content[0]};
    }

    template<typename T>
    std::array<T, 2> Vec4<T>::zy() const {
        return {this->content[2], this->content[1]};
    }

    template<typename T>
    std::array<T, 2> Vec4<T>::wy() const {
        return {this->content[3], this->content[1]};
    }

    template<typename T>
    std::array<T, 2> Vec4<T>::wz() const {
        return {this->content[3], this->content[2]};
    }

    template<typename T>
    std::array<T, 3> Vec4<T>::xyz() const {
        return {this->content[0], this->content[1], this->content[2]};
    }

    template<typename T>
    std::array<T, 3> Vec4<T>::xyw() const {
        return {this->content[0], this->content[1], this->content[3]};
    }

    template<typename T>
    std::array<T, 3> Vec4<T>::xzw() const {
        return {this->content[0], this->content[2], this->content[3]};
    }

    template<typename T>
    std::array<T, 3> Vec4<T>::xzy() const {
        return {this->content[0], this->content[2], this->content[1]};
    }

    template<typename T>
    std::array<T, 3> Vec4<T>::xwy() const {
        return {this->content[0], this->content[3], this->content[1]};
    }

    template<typename T>
    std::array<T, 3> Vec4<T>::xwz() const {
        return {this->content[0], this->content[3], this->content[2]};
    }
    
    template<typename T>
    std::array<T, 3> Vec4<T>::yxz() const {
        return {this->content[1], this->content[0], this->content[2]};
    }

    template<typename T>
    std::array<T, 3> Vec4<T>::yxw() const {
        return {this->content[1], this->content[0], this->content[3]};
    }

    template<typename T>
    std::array<T, 3> Vec4<T>::yzx() const {
        return {this->content[1], this->content[2], this->content[0]};
    }

    template<typename T>
    std::array<T, 3> Vec4<T>::yzw() const {
        return {this->content[1], this->content[2], this->content[3]};
    }

    template<typename T>
    std::array<T, 3> Vec4<T>::ywx() const {
        return {this->content[1], this->content[3], this->content[0]};
    }

    template<typename T>
    std::array<T, 3> Vec4<T>::ywz() const {
        return {this->content[1], this->content[3], this->content[2]};
    }

    template<typename T>
    std::array<T, 3> Vec4<T>::zxy() const {
        return {this->content[2], this->content[0], this->content[1]};
    }

    template<typename T>
    std::array<T, 3> Vec4<T>::zxw() const {
        return {this->content[2], this->content[0], this->content[2]};
    }

    template<typename T>
    std::array<T, 3> Vec4<T>::zyx() const {
        return {this->content[2], this->content[1], this->content[0]};
    }

    template<typename T>
    std::array<T, 3> Vec4<T>::zyw() const {
        return {this->content[2], this->content[1], this->content[3]};
    }

    template<typename T>
    std::array<T, 3> Vec4<T>::zwx() const {
        return {this->content[2], this->content[3], this->content[0]};
    }

    template<typename T>
    std::array<T, 3> Vec4<T>::zwy() const {
        return {this->content[2], this->content[3], this->content[1]};
    }

    template<typename T>
    std::array<T, 3> Vec4<T>::wxy() const {
        return {this->content[3], this->content[0], this->content[1]};
    }

    template<typename T>
    std::array<T, 3> Vec4<T>::wxz() const {
        return {this->content[3], this->content[0], this->content[2]};
    }

    template<typename T>
    std::array<T, 3> Vec4<T>::wyx() const {
        return {this->content[3], this->content[1], this->content[0]};
    }

    template<typename T>
    std::array<T, 3> Vec4<T>::wyz() const {
        return {this->content[3], this->content[1], this->content[2]};
    }

    template<typename T>
    std::array<T, 3> Vec4<T>::wzx() const {
        return {this->content[3], this->content[2], this->content[0]};
    }

    template<typename T>
    std::array<T, 3> Vec4<T>::wzy() const {
        return {this->content[3], this->content[2], this->content[1]};
    }

    template<typename T>
    std::array<T, 4> Vec4<T>::xyzw() const {
        return {this->content[0], this->content[1], this->content[2], this->content[3]};
    }

    template<typename T>
    std::array<T, 4> Vec4<T>::xywz() const {
        return {this->content[0], this->content[1], this->content[3], this->content[2]};
    }

    template<typename T>
    std::array<T, 4> Vec4<T>::xwyz() const {
        return {this->content[0], this->content[3], this->content[1], this->content[2]};
    }

    template<typename T>
    std::array<T, 4> Vec4<T>::xwzy() const {
        return {this->content[0], this->content[3], this->content[2], this->content[1]};
    }

    template<typename T>
    std::array<T, 4> Vec4<T>::xzwy() const {
        return {this->content[0], this->content[2], this->content[3], this->content[1]};
    }

    template<typename T>
    std::array<T, 4> Vec4<T>::xzyw() const {
        return {this->content[0], this->content[2], this->content[1], this->content[3]};
    }

    template<typename T>
    std::array<T, 4> Vec4<T>::yxzw() const {
        return {this->content[1], this->content[0], this->content[2], this->content[3]};
    }

    template<typename T>
    std::array<T, 4> Vec4<T>::yxwz() const {
        return {this->content[1], this->content[0], this->content[3], this->content[2]};
    }

    template<typename T>
    std::array<T, 4> Vec4<T>::yzxw() const {
        return {this->content[1], this->content[2], this->content[0], this->content[3]};
    }

    template<typename T>
    std::array<T, 4> Vec4<T>::yzwx() const {
        return {this->content[1], this->content[2], this->content[3], this->content[0]};
    }

    template<typename T>
    std::array<T, 4> Vec4<T>::ywxz() const {
        return {this->content[1], this->content[3], this->content[0], this->content[2]};
    }

    template<typename T>
    std::array<T, 4> Vec4<T>::ywzx() const {
        return {this->content[1], this->content[3], this->content[2], this->content[0]};
    }

    template<typename T>
    std::array<T, 4> Vec4<T>::zxyw() const {
        return {this->content[2], this->content[0], this->content[1], this->content[3]};
    }

    template<typename T>
    std::array<T, 4> Vec4<T>::zxwy() const {
        return {this->content[2], this->content[0], this->content[3], this->content[1]};
    }

    template<typename T>
    std::array<T, 4> Vec4<T>::zyxw() const {
        return {this->content[2], this->content[1], this->content[0], this->content[3]};
    }

    template<typename T>
    std::array<T, 4> Vec4<T>::zywx() const {
        return {this->content[2], this->content[1], this->content[3], this->content[0]};
    }

    template<typename T>
    std::array<T, 4> Vec4<T>::zwxy() const {
        return {this->content[2], this->content[3], this->content[0], this->content[1]};
    }

    template<typename T>
    std::array<T, 4> Vec4<T>::zwyx() const {
        return {this->content[2], this->content[3], this->content[1], this->content[0]};
    }

    template<typename T>
    std::array<T, 4> Vec4<T>::wxyz() const {
        return {this->content[3], this->content[0], this->content[1], this->content[2]};
    }

    template<typename T>
    std::array<T, 4> Vec4<T>::wxzy() const {
        return {this->content[3], this->content[0], this->content[2], this->content[1]};
    }

    template<typename T>
    std::array<T, 4> Vec4<T>::wyxz() const {
        return {this->content[3], this->content[1], this->content[0], this->content[2]};
    }

    template<typename T>
    std::array<T, 4> Vec4<T>::wyzx() const {
        return {this->content[3], this->content[1], this->content[2], this->content[0]};
    }

    template<typename T>
    std::array<T, 4> Vec4<T>::wzxy() const {
        return {this->content[3], this->content[2], this->content[0], this->content[1]};
    }

    template<typename T>
    std::array<T, 4> Vec4<T>::wzyx() const {
        return {this->content[3], this->content[2], this->content[1], this->content[0]};
    }
    

    template<typename T>
    Vec4<T> &Vec4<T>::x(const T &value) {
        this->content[0] = value;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::y(const T &value) {
        this->content[1] = value;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::z(const T &value) {
        this->content[2] = value;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::w(const T &value) {
        this->content[3] = value;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::xy(const T &first, const T &second) {
        this->content[0] = first;
        this->content[1] = second;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::xz(const T &first, const T &second) {
        this->content[0] = first;
        this->content[2] = second;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::xw(const T &first, const T &second) {
        this->content[0] = first;
        this->content[3] = second;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::yz(const T &first, const T &second) {
        this->content[1] = first;
        this->content[2] = second;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::yw(const T &first, const T &second) {
        this->content[1] = first;
        this->content[3] = second;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::zw(const T &first, const T &second) {
        this->content[2] = first;
        this->content[3] = second;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::yx(const T &first, const T &second) {
        this->content[1] = first;
        this->content[0] = second;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::zx(const T &first, const T &second) {
        this->content[2] = first;
        this->content[0] = second;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::wx(const T &first, const T &second) {
        this->content[3] = first;
        this->content[0] = second;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::zy(const T &first, const T &second) {
        this->content[2] = first;
        this->content[1] = second;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::wy(const T &first, const T &second) {
        this->content[3] = first;
        this->content[1] = second;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::wz(const T &first, const T &second) {
        this->content[3] = first;
        this->content[2] = second;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::xyz(const T &first, const T &second, const T &third) {
        this->content[0] = first;
        this->content[1] = second;
        this->content[2] = third;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::xyw(const T &first, const T &second, const T &third) {
        this->content[0] = first;
        this->content[1] = second;
        this->content[3] = third;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::xzw(const T &first, const T &second, const T &third) {
        this->content[0] = first;
        this->content[2] = second;
        this->content[3] = third;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::xzy(const T &first, const T &second, const T &third) {
        this->content[0] = first;
        this->content[2] = second;
        this->content[1] = third;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::xwy(const T &first, const T &second, const T &third) {
        this->content[0] = first;
        this->content[3] = second;
        this->content[1] = third;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::xwz(const T &first, const T &second, const T &third) {
        this->content[0] = first;
        this->content[3] = second;
        this->content[2] = third;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::yxz(const T &first, const T &second, const T &third) {
        this->content[1] = first;
        this->content[0] = second;
        this->content[2] = third;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::yxw(const T &first, const T &second, const T &third) {
        this->content[1] = first;
        this->content[0] = second;
        this->content[3] = third;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::yzx(const T &first, const T &second, const T &third) {
        this->content[1] = first;
        this->content[2] = second;
        this->content[0] = third;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::yzw(const T &first, const T &second, const T &third) {
        this->content[1] = first;
        this->content[2] = second;
        this->content[3] = third;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::ywx(const T &first, const T &second, const T &third) {
        this->content[1] = first;
        this->content[3] = second;
        this->content[0] = third;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::ywz(const T &first, const T &second, const T &third) {
        this->content[1] = first;
        this->content[3] = second;
        this->content[2] = third;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::zxy(const T &first, const T &second, const T &third) {
        this->content[2] = first;
        this->content[0] = second;
        this->content[1] = third;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::zxw(const T &first, const T &second, const T &third) {
        this->content[2] = first;
        this->content[0] = second;
        this->content[3] = third;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::zyx(const T &first, const T &second, const T &third) {
        this->content[2] = first;
        this->content[1] = second;
        this->content[0] = third;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::zyw(const T &first, const T &second, const T &third) {
        this->content[2] = first;
        this->content[1] = second;
        this->content[3] = third;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::zwx(const T &first, const T &second, const T &third) {
        this->content[2] = first;
        this->content[3] = second;
        this->content[0] = third;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::zwy(const T &first, const T &second, const T &third) {
        this->content[2] = first;
        this->content[3] = second;
        this->content[1] = third;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::wxy(const T &first, const T &second, const T &third) {
        this->content[3] = first;
        this->content[0] = second;
        this->content[1] = third;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::wxz(const T &first, const T &second, const T &third) {
        this->content[3] = first;
        this->content[0] = second;
        this->content[2] = third;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::wyx(const T &first, const T &second, const T &third) {
        this->content[3] = first;
        this->content[1] = second;
        this->content[0] = third;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::wyz(const T &first, const T &second, const T &third) {
        this->content[3] = first;
        this->content[1] = second;
        this->content[2] = third;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::wzx(const T &first, const T &second, const T &third) {
        this->content[3] = first;
        this->content[2] = second;
        this->content[0] = third;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::wzy(const T &first, const T &second, const T &third) {
        this->content[3] = first;
        this->content[2] = second;
        this->content[1] = third;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::xyzw(const T &first, const T &second, const T &third, const T &fourth) {
        this->content[0] = first;
        this->content[1] = second;
        this->content[2] = third;
        this->content[3] = fourth;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::xywz(const T &first, const T &second, const T &third, const T &fourth) {
        this->content[0] = first;
        this->content[1] = second;
        this->content[3] = third;
        this->content[2] = fourth;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::xwyz(const T &first, const T &second, const T &third, const T &fourth) {
        this->content[0] = first;
        this->content[3] = second;
        this->content[1] = third;
        this->content[2] = fourth;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::xwzy(const T &first, const T &second, const T &third, const T &fourth) {
        this->content[0] = first;
        this->content[3] = second;
        this->content[2] = third;
        this->content[1] = fourth;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::xzwy(const T &first, const T &second, const T &third, const T &fourth) {
        this->content[0] = first;
        this->content[2] = second;
        this->content[3] = third;
        this->content[1] = fourth;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::xzyw(const T &first, const T &second, const T &third, const T &fourth) {
        this->content[0] = first;
        this->content[2] = second;
        this->content[1] = third;
        this->content[3] = fourth;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::yxzw(const T &first, const T &second, const T &third, const T &fourth) {
        this->content[1] = first;
        this->content[0] = second;
        this->content[2] = third;
        this->content[3] = fourth;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::yxwz(const T &first, const T &second, const T &third, const T &fourth) {
        this->content[1] = first;
        this->content[0] = second;
        this->content[3] = third;
        this->content[2] = fourth;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::yzxw(const T &first, const T &second, const T &third, const T &fourth) {
        this->content[1] = first;
        this->content[2] = second;
        this->content[0] = third;
        this->content[3] = fourth;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::yzwx(const T &first, const T &second, const T &third, const T &fourth) {
        this->content[1] = first;
        this->content[2] = second;
        this->content[3] = third;
        this->content[0] = fourth;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::ywxz(const T &first, const T &second, const T &third, const T &fourth) {
        this->content[1] = first;
        this->content[3] = second;
        this->content[0] = third;
        this->content[2] = fourth;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::ywzx(const T &first, const T &second, const T &third, const T &fourth) {
        this->content[1] = first;
        this->content[3] = second;
        this->content[2] = third;
        this->content[0] = fourth;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::zxyw(const T &first, const T &second, const T &third, const T &fourth) {
        this->content[2] = first;
        this->content[0] = second;
        this->content[1] = third;
        this->content[3] = fourth;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::zxwy(const T &first, const T &second, const T &third, const T &fourth) {
        this->content[2] = first;
        this->content[0] = second;
        this->content[3] = third;
        this->content[1] = fourth;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::zyxw(const T &first, const T &second, const T &third, const T &fourth) {
        this->content[2] = first;
        this->content[1] = second;
        this->content[0] = third;
        this->content[3] = fourth;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::zywx(const T &first, const T &second, const T &third, const T &fourth) {
        this->content[2] = first;
        this->content[1] = second;
        this->content[3] = third;
        this->content[0] = fourth;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::zwxy(const T &first, const T &second, const T &third, const T &fourth) {
        this->content[2] = first;
        this->content[3] = second;
        this->content[0] = third;
        this->content[1] = fourth;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::zwyx(const T &first, const T &second, const T &third, const T &fourth) {
        this->content[2] = first;
        this->content[3] = second;
        this->content[1] = third;
        this->content[0] = fourth;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::wxyz(const T &first, const T &second, const T &third, const T &fourth) {
        this->content[3] = first;
        this->content[0] = second;
        this->content[1] = third;
        this->content[2] = fourth;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::wxzy(const T &first, const T &second, const T &third, const T &fourth) {
        this->content[3] = first;
        this->content[0] = second;
        this->content[2] = third;
        this->content[1] = fourth;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::wyxz(const T &first, const T &second, const T &third, const T &fourth) {
        this->content[3] = first;
        this->content[1] = second;
        this->content[0] = third;
        this->content[2] = fourth;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::wyzx(const T &first, const T &second, const T &third, const T &fourth) {
        this->content[3] = first;
        this->content[1] = second;
        this->content[2] = third;
        this->content[0] = fourth;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::wzxy(const T &first, const T &second, const T &third, const T &fourth) {
        this->content[3] = first;
        this->content[2] = second;
        this->content[0] = third;
        this->content[1] = fourth;
        return *this;
    }
    
    template<typename T>
    Vec4<T> &Vec4<T>::wzyx(const T &first, const T &second, const T &third, const T &fourth) {
        this->content[3] = first;
        this->content[2] = second;
        this->content[1] = third;
        this->content[0] = fourth;  
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::xy(const std::array<T, 2> &value) {
        this->xy(value[0], value[1]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::xz(const std::array<T, 2> &value) {
        this->xz(value[0], value[1]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::xw(const std::array<T, 2> &value) {
        this->xw(value[0], value[1]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::yz(const std::array<T, 2> &value) {
        this->yz(value[0], value[1]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::yw(const std::array<T, 2> &value) {
        this->yw(value[0], value[1]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::zw(const std::array<T, 2> &value) {
        this->zw(value[0], value[1]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::yx(const std::array<T, 2> &value) {
        this->yx(value[0], value[1]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::zx(const std::array<T, 2> &value) {
        this->zx(value[0], value[1]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::wx(const std::array<T, 2> &value) {
        this->wx(value[0], value[1]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::zy(const std::array<T, 2> &value) {
        this->zy(value[0], value[1]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::wy(const std::array<T, 2> &value) {
        this->wy(value[0], value[1]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::wz(const std::array<T, 2> &value) {
        this->wz(value[0], value[1]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::xyz(const std::array<T, 3> &value) {
        this->xyz(value[0], value[1], value[2]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::xyw(const std::array<T, 3> &value) {
        this->xyw(value[0], value[1], value[2]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::xzw(const std::array<T, 3> &value) {
        this->xzw(value[0], value[1], value[2]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::xzy(const std::array<T, 3> &value) {
        this->xzy(value[0], value[1], value[2]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::xwy(const std::array<T, 3> &value) {
        this->xwy(value[0], value[1], value[2]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::xwz(const std::array<T, 3> &value) {
        this->xwz(value[0], value[1], value[2]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::yxz(const std::array<T, 3> &value) {
        this->yxz(value[0], value[1], value[2]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::yxw(const std::array<T, 3> &value) {
        this->yxw(value[0], value[1], value[2]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::yzx(const std::array<T, 3> &value) {
        this->yzx(value[0], value[1], value[2]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::yzw(const std::array<T, 3> &value) {
        this->yzw(value[0], value[1], value[2]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::ywx(const std::array<T, 3> &value) {
        this->ywx(value[0], value[1], value[2]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::ywz(const std::array<T, 3> &value) {
        this->ywz(value[0], value[1], value[2]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::zxy(const std::array<T, 3> &value) {
        this->zxy(value[0], value[1], value[2]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::zxw(const std::array<T, 3> &value) {
        this->zxw(value[0], value[1], value[2]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::zyx(const std::array<T, 3> &value) {
        this->zyx(value[0], value[1], value[2]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::zyw(const std::array<T, 3> &value) {
        this->zyw(value[0], value[1], value[2]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::zwx(const std::array<T, 3> &value) {
        this->zwx(value[0], value[1], value[2]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::zwy(const std::array<T, 3> &value) {
        this->zwy(value[0], value[1], value[2]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::wxy(const std::array<T, 3> &value) {
        this->wxy(value[0], value[1], value[2]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::wxz(const std::array<T, 3> &value) {
        this->wxz(value[0], value[1], value[2]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::wyx(const std::array<T, 3> &value) {
        this->wyx(value[0], value[1], value[2]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::wyz(const std::array<T, 3> &value) {
        this->wyz(value[0], value[1], value[2]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::wzx(const std::array<T, 3> &value) {
        this->wzx(value[0], value[1], value[2]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::wzy(const std::array<T, 3> &value) {
        this->wzy(value[0], value[1], value[2]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::xyzw(const std::array<T, 4> &value) {
        this->xyzw(value[0], value[1], value[2], value[3]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::xywz(const std::array<T, 4> &value) {
        this->xywz(value[0], value[1], value[2], value[3]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::xwyz(const std::array<T, 4> &value) {
        this->xwyz(value[0], value[1], value[2], value[3]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::xwzy(const std::array<T, 4> &value) {
        this->xwzy(value[0], value[1], value[2], value[3]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::xzwy(const std::array<T, 4> &value) {
        this->xzwy(value[0], value[1], value[2], value[3]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::xzyw(const std::array<T, 4> &value) {
        this->xzyw(value[0], value[1], value[2], value[3]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::yxzw(const std::array<T, 4> &value) {
        this->yxzw(value[0], value[1], value[2], value[3]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::yxwz(const std::array<T, 4> &value) {
        this->yxwz(value[0], value[1], value[2], value[3]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::yzxw(const std::array<T, 4> &value) {
        this->yzxw(value[0], value[1], value[2], value[3]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::yzwx(const std::array<T, 4> &value) {
        this->yzwx(value[0], value[1], value[2], value[3]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::ywxz(const std::array<T, 4> &value) {
        this->ywxz(value[0], value[1], value[2], value[3]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::ywzx(const std::array<T, 4> &value) {
        this->ywzx(value[0], value[1], value[2], value[3]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::zxyw(const std::array<T, 4> &value) {
        this->zxyw(value[0], value[1], value[2], value[3]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::zxwy(const std::array<T, 4> &value) {
        this->zxwy(value[0], value[1], value[2], value[3]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::zyxw(const std::array<T, 4> &value) {
        this->zyxw(value[0], value[1], value[2], value[3]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::zywx(const std::array<T, 4> &value) {
        this->zywx(value[0], value[1], value[2], value[3]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::zwxy(const std::array<T, 4> &value) {
        this->zwxy(value[0], value[1], value[2], value[3]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::zwyx(const std::array<T, 4> &value) {
        this->zwyx(value[0], value[1], value[2], value[3]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::wxyz(const std::array<T, 4> &value) {
        this->wxyz(value[0], value[1], value[2], value[3]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::wxzy(const std::array<T, 4> &value) {
        this->wxzy(value[0], value[1], value[2], value[3]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::wyxz(const std::array<T, 4> &value) {
        this->wyxz(value[0], value[1], value[2], value[3]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::wyzx(const std::array<T, 4> &value) {
        this->wyzx(value[0], value[1], value[2], value[3]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::wzxy(const std::array<T, 4> &value) {
        this->wzxy(value[0], value[1], value[2], value[3]);
        return *this;
    }

    template<typename T>
    Vec4<T> &Vec4<T>::wzyx(const std::array<T, 4> &value) {
        this->wzyx(value[0], value[1], value[2], value[3]);
        return *this;
    }
}
