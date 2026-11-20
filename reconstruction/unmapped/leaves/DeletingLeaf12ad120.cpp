// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// 0x12ad120 DeletingLeaf12ad120::~DeletingLeaf12ad120
// CI hash: 0x12ad120 ??_GDeletingLeaf12ad120@@UEAAPEAXI@Z
// Adapted bodies: none
#include "DeletingLeaf12ad120.h"

DeletingLeaf12ad120::DeletingLeaf12ad120(void (*fn)()) : callback(fn) {}
