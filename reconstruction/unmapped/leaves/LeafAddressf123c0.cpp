// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf123c0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf123c0 NiIntegerExtraData::GetRTTI
#include "LeafAddressf123c0.h"
extern unsigned char leaf_global;
void* LeafAddressf123c0::Address() { return &leaf_global; }
