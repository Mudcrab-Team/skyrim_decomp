// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// 0x130d880 DeletingLeaf130d880::~DeletingLeaf130d880
// CI hash: 0x130d880 ??_GDeletingLeaf130d880@@UEAAPEAXI@Z
// Adapted bodies: none
#include "DeletingLeaf130d880.h"

DeletingLeaf130d880::DeletingLeaf130d880(void (*fn)()) : callback(fn) {}
