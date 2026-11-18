// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress20bea0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x20bea0 NiAlphaProperty::GetRTTI
#include "LeafAddress20bea0.h"
extern unsigned char leaf_global;
void* LeafAddress20bea0::Address() { return &leaf_global; }
