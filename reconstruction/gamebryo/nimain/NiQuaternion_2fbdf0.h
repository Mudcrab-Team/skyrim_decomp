// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// NiQuaternion: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// NiQuaternion::ToRotation: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
#pragma once
#include <math.h>

namespace f3m_008e2480 {
struct NiMatrix3;
struct NiPoint3;

struct ThreeByThreeMatrix { float m[3][3]; };


class NiPoint3
{
public:
	NiPoint3& operator*= (float fScalar)
	{
		x = x * fScalar;
		y = y * fScalar;
		z = z * fScalar;
		return *this;
	}
	float x, y, z;
};

class NiMatrix3
{
public:
	void SetCol(unsigned int uiCol, float f0, float f1, float f2)
	{
		m_pEntry[0][uiCol] = f0;
		m_pEntry[1][uiCol] = f1;
		m_pEntry[2][uiCol] = f2;
	}
	float m_pEntry[3][3];
};

class NiTransform
{
public:
	NiMatrix3 m_Rotate;
	NiPoint3 m_Translate;
	float m_fScale;
};

class NiQuaternion
{
public:
	NiQuaternion() { }
	void SetW(float w) { m_fW = w; }
	void SetX(float x) { m_fX = x; }
	void SetY(float y) { m_fY = y; }
	void SetZ(float z) { m_fZ = z; }
	void Normalize()
	{
		float fNorm = m_fW * m_fW + m_fX * m_fX + m_fY * m_fY + m_fZ * m_fZ;
		float fScale = 1.0f / (float)sqrt(fNorm);
		m_fW *= fScale;
		m_fX *= fScale;
		m_fY *= fScale;
		m_fZ *= fScale;
	}
	void ToRotation(NiMatrix3& kRot) const;

	float m_fW, m_fX, m_fY, m_fZ;
};

}
