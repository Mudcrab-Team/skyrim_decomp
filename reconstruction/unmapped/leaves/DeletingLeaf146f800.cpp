// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// 0x146f800 DeletingLeaf146f800::~DeletingLeaf146f800
// CI hash: 0x146f800 ??_GDeletingLeaf146f800@@UEAAPEAXI@Z
// Adapted bodies: none
#include "DeletingLeaf146f800.h"

DeletingLeaf146f800::DeletingLeaf146f800(void (*fn)()) : callback(fn) {}
