#pragma once
#include "Quaternion.h"

#include "Mode.h"
#include "Scale.h"
#include "Key.h"
#include "Chord.h"

namespace bom
{
	/**
	* Key -> Chord -> Mode -> Scale の順番で解釈する
	*/

	/**
	* 音を制御するためのマネージャクラス
	*/
	class ModalManager
	{
		const Quaternion identity = Quaternion::AxisAngle(s3d::Vec3(Cos(Math::Pi / 6.0), Sin(Math::Pi / 6.0), Sin(Math::Pi / 128.0)), Math::Pi / 6.0).Normalize();



	public:
		
	};
}