// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// 0x13b2860 DeletingLeaf13b2860::~DeletingLeaf13b2860
// CI hash: 0x13b2860 ??_GDeletingLeaf13b2860@@UEAAPEAXI@Z
// Adapted bodies: none
#include "DeletingLeaf13b2860.h"

DeletingLeaf13b2860::DeletingLeaf13b2860(void (*fn)()) : callback(fn) {}
