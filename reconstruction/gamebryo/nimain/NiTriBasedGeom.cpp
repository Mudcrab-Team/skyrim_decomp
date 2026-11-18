/*
 * Labels: v2
 * Build: sse-steam-1-7-104; RVA 0xf1f420, 33 bytes.
 * Evidence: findings/ghidra-import.md
 * Origin: original reconstruction; member declarations adapted from CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/N/NiRefObject.h, NiObjectNET.h, NiAVObject.h, NiGeometry.h, NiTransform.h and NiBound.h.
 * Source exposure: mixed (binary-analysis and community headers).
 * Drafted by: gpt-6.1-sol
 * Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
 * The constructor alone is compared. Base constructor and destructors are declarations only.
 * Class identity and complete base chain come from executable RTTI; signatures remain inferred.
 * CommonLibSSE-po3@654e55f7979c1733033d5dbef176e43827bac944 include/RE/N/NiTriBasedGeometry.h (GPL-3.0) was also consulted for the hierarchy.
 * Per-unit virtual-interface and pointer-wrapper stand-ins are incomplete; allocation and vtable contents are not claimed.
 */
// MIT License
// 
// Copyright (c) 2018 Ryan-rsm-McKenzie
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// NiRefObject, NiObject, NiObjectNET, NiAVObject, NiGeometry: EXE_RTTI COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiTriBasedGeom: EXE_RTTI
// NiRefObject, NiObject, NiObjectNET, NiAVObject, NiGeometry: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiTriBasedGeom::NiTriBasedGeom, NiGeometry::NiGeometry: GUESS(low)
// Vector3, Matrix3, Transform, Bound: STANDIN GUESS(low)
// referenceCount, name, controllers, extra, extraDataSize, maxSize, parent, parentIndex, collisionObject, local, world, previousWorld, worldBound, flags, userData, fadeAmount, lastUpdatedFrameCounter: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown3c, unknown108, flags02, unknown10a, propertyState, effectState, skinInstance, modelData, unknown130: GUESS(low)
#include "NiTriBasedGeom.h"
NiTriBasedGeom::NiTriBasedGeom() {}
