// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// 0x13b6840 DeletingLeaf13b6840::~DeletingLeaf13b6840
// CI hash: 0x13b6840 ??_GDeletingLeaf13b6840@@UEAAPEAXI@Z
// Adapted bodies: none
#include "DeletingLeaf13b6840.h"

DeletingLeaf13b6840::DeletingLeaf13b6840(void (*fn)()) : callback(fn) {}
