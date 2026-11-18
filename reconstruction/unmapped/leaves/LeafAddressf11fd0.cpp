// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf11fd0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf11fd0 NiFogProperty::GetRTTI
#include "LeafAddressf11fd0.h"
extern unsigned char leaf_global;
void* LeafAddressf11fd0::Address() { return &leaf_global; }
