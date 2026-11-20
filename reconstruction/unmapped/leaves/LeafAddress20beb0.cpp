// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress20beb0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x20beb0 NiProperty::GetRTTI
#include "LeafAddress20beb0.h"
extern unsigned char leaf_global;
void* LeafAddress20beb0::Address() { return &leaf_global; }
