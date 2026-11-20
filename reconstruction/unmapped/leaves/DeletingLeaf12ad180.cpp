// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// 0x12ad180 DeletingLeaf12ad180::~DeletingLeaf12ad180
// CI hash: 0x12ad180 ??_GDeletingLeaf12ad180@@UEAAPEAXI@Z
// Adapted bodies: none
#include "DeletingLeaf12ad180.h"

DeletingLeaf12ad180::DeletingLeaf12ad180(void (*fn)()) : callback(fn) {}
