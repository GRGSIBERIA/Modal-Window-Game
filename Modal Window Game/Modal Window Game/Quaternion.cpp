#include "Quaternion.h"
using namespace mwg;

inline Quaternion mwg::Quaternion::mul(const Quaternion & rhs) const
{
	return Quaternion(w * rhs.w - v.dot(rhs.v), w * rhs.v + v * rhs.w + v.cross(rhs.v));
}

mwg::Quaternion::Quaternion()
	: v(0.0, 0.0, 0.0), w(0.0)
{
}

mwg::Quaternion::Quaternion(double v1, double v2, double v3, double w)
	: v(v1, v2, v3), w(w)
{
}

mwg::Quaternion::Quaternion(const double w, const s3d::Vec3& v)
	: v(v), w(w)
{
}

mwg::Quaternion mwg::Quaternion::operator*(const Quaternion & rhs) const
{
	return mul(rhs).Normalize();
}

s3d::Vec3 mwg::Quaternion::operator*(const s3d::Vec3 & vec) const
{
	const auto q = mul(Quaternion(0.0, vec)).mul(Conjugate());
	return q.v;
}

Quaternion mwg::Quaternion::Normalize() const
{
	auto q = Quaternion(w, v);
	auto l = 1.0 / Length();
	q.v *= l;
	q.w *= l;
	return q;
}

Quaternion mwg::Quaternion::Conjugate() const
{
	return Quaternion(w, -v);
}

double mwg::Quaternion::Length() const
{
	return s3d::Sqrt(v.x * v.x + v.y * v.y + v.z * v.z + w * w);
}

Quaternion mwg::Quaternion::AxisAngle(const s3d::Vec3 & axis, const double radian)
{
	const auto c = cos(radian * 0.5);
	const auto s = sin(radian * 0.5);
	return Quaternion(c, axis.normalized() * s).Normalize();
}
