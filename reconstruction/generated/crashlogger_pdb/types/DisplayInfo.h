// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DisplayInfo; size 0xe8
#pragma once

#include "GMatrix3D.h"
struct DisplayInfo {
    double _x;
    double _y;
    double _rotation;
    double _xScale;
    double _yScale;
    double _alpha;
    bool _visible;
    unsigned char _pad31;
    unsigned short _pad32;
    unsigned int _pad34;
    double _z;
    double _xRotation;
    double _yRotation;
    double _zScale;
    double _fov;
    GMatrix3D _viewMatrix3D;
    GMatrix3D _perspMatrix3D;
    unsigned short _flags;  // Flag in the PDB is wider than this slot
    unsigned short _padD2;
    unsigned int _padD4;
};
static_assert(sizeof(DisplayInfo) == 232, "DisplayInfo layout differs from the PDB");
