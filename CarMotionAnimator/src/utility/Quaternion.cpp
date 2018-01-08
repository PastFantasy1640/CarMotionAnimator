#include "Quaternion.hpp"

cma::Quaternion::Quaternion()
    : w(0), x(0), y(0), z(0){}

cma::Quaternion::Quaternion(const double w, const double x, const double y, const double z)
     : w(w), x(x), y(y), z(z) {}
     
cma::Quaternion::Quaternion(const double x, const double y, const double z)
    : w(0), x(x), y(y), z(z) {}

template<typename T> cma::Quaternion::Quaternion(const Vector<T> & v)
    : w(0), x(static_cast<double>(v.x)), y(static_cast<double>(v.y)), z(static_cast<double>(v.z)) {}

Quaternion conjugate(void) && const{
    return Quaternion(this->w, -this->x, -this->y, -this->z);
}

Quaternion operator*(const Quaternion & right) && const{
    return Quaternion(
        this->w * right.w - this->x * right.x - this->y * right.y - this->z * right.z,
        this->w * right.x + this->x * right.w + this->y * right.z - this->z * right.y,
        this->w * right.y + this->y * right.w + this->z * right.x - this->x * right.z,
        this->w * right.z + this->z * right.w + this->x * right.y - this->y * right.x
    );
}