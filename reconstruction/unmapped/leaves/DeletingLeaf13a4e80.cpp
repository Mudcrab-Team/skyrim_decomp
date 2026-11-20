// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// 0x13a4e80 DeletingLeaf13a4e80::~DeletingLeaf13a4e80
// CI hash: 0x13a4e80 ??_GDeletingLeaf13a4e80@@UEAAPEAXI@Z
// Adapted bodies: none
#include "DeletingLeaf13a4e80.h"

DeletingLeaf13a4e80::DeletingLeaf13a4e80(void (*fn)()) : callback(fn) {}
