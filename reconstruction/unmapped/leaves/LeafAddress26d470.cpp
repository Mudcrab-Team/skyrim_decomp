// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress26d470, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x26d470 BSDynamicTriShape::GetRTTI
#include "LeafAddress26d470.h"
extern unsigned char leaf_global;
void* LeafAddress26d470::Address() { return &leaf_global; }
