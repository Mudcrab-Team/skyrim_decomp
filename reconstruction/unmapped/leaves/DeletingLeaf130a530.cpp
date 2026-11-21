// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// 0x130a530 DeletingLeaf130a530::~DeletingLeaf130a530
// CI hash: 0x130a530 ??_GDeletingLeaf130a530@@UEAAPEAXI@Z
// Adapted bodies: none
#include "DeletingLeaf130a530.h"

DeletingLeaf130a530::DeletingLeaf130a530(void (*fn)()) : callback(fn) {}
