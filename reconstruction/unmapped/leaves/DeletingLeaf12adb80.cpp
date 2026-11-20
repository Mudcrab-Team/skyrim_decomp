// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// 0x12adb80 DeletingLeaf12adb80::~DeletingLeaf12adb80
// CI hash: 0x12adb80 ??_GDeletingLeaf12adb80@@UEAAPEAXI@Z
// Adapted bodies: none
#include "DeletingLeaf12adb80.h"

DeletingLeaf12adb80::DeletingLeaf12adb80(void (*fn)()) : callback(fn) {}
