// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// 0x12ad060 DeletingLeaf12ad060::~DeletingLeaf12ad060
// CI hash: 0x12ad060 ??_GDeletingLeaf12ad060@@UEAAPEAXI@Z
// Adapted bodies: none
#include "DeletingLeaf12ad060.h"

DeletingLeaf12ad060::DeletingLeaf12ad060(void (*fn)()) : callback(fn) {}
