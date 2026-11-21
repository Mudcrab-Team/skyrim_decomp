// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// 0x13b5600 DeletingLeaf13b5600::~DeletingLeaf13b5600
// CI hash: 0x13b5600 ??_GDeletingLeaf13b5600@@UEAAPEAXI@Z
// Adapted bodies: none
#include "DeletingLeaf13b5600.h"

DeletingLeaf13b5600::DeletingLeaf13b5600(void (*fn)()) : callback(fn) {}
