// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfd3100, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfd3100 BSXFlags::GetRTTI
#include "LeafAddressfd3100.h"
extern unsigned char leaf_global;
void* LeafAddressfd3100::Address() { return &leaf_global; }
