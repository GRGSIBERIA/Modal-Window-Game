#pragma once
#include <Siv3D.hpp>

namespace mwg
{
	class Quaternion
	{
		s3d::Vec3 v;
		double w;

		inline Quaternion mul(const Quaternion& rhs) const;

	public:
		Quaternion();

		Quaternion(double v1, double v2, double v3, double w);

		Quaternion(const double w, const s3d::Vec3& vecor);

		Quaternion operator*(const Quaternion& rhs) const;

		s3d::Vec3 operator*(const s3d::Vec3& vec) const;

		Quaternion Normalize() const;

		Quaternion Conjugate() const;

		double Length() const;

		static Quaternion AxisAngle(const s3d::Vec3& axis, const double radian);
	};
}