// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfd8f90, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfd8f90 BSWindModifier::GetRTTI
#include "LeafAddressfd8f90.h"
extern unsigned char leaf_global;
void* LeafAddressfd8f90::Address() { return &leaf_global; }
