// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1553940, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1553940 BSSkyShaderProperty::GetRTTI
#include "LeafAddress1553940.h"
extern unsigned char leaf_global;
void* LeafAddress1553940::Address() { return &leaf_global; }
