// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// 0x130a490 DeletingLeaf130a490::~DeletingLeaf130a490
// CI hash: 0x130a490 ??_GDeletingLeaf130a490@@UEAAPEAXI@Z
// Adapted bodies: none
#include "DeletingLeaf130a490.h"

DeletingLeaf130a490::DeletingLeaf130a490(void (*fn)()) : callback(fn) {}
