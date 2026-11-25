// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// bhkRigidBodyT: CRASHLOGGER_PDB(59818@2026.10.24)
// bhkRigidBodyT::Func58_140DDB730: CRASHLOGGER_PDB(59818@2026.10.24)
// Globals: GUESS(low); placeholder name
#pragma once

namespace f3m_00925920 {
struct FrameMethods;
struct Transform;
struct Vector4;



struct __declspec(align(16)) Vector4 { float x,y,z,w; };
struct Transform {
    Vector4 rotation[3], translation;
    void Func00924b40(const Vector4*);
};
struct bhkRigidBodyT;
struct FrameMethods {
    void* preceding[51];
    void (*translation)(bhkRigidBodyT*,Vector4*);
    void (*rotation)(bhkRigidBodyT*,Vector4*);
};
struct bhkRigidBodyT {
    FrameMethods* methods;
    Transform* Func58_140DDB730(Transform*);
};
}

struct Globals
{
};
