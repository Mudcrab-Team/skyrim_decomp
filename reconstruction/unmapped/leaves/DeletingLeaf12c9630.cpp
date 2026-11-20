// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// 0x12c9630 DeletingLeaf12c9630::~DeletingLeaf12c9630
// CI hash: 0x12c9630 ??_GDeletingLeaf12c9630@@UEAAPEAXI@Z
// Adapted bodies: none
#include "DeletingLeaf12c9630.h"

DeletingLeaf12c9630::DeletingLeaf12c9630(void (*fn)()) : callback(fn) {}
