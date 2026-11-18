// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf12b50, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf12b50 NiIntegersExtraData::GetRTTI
#include "LeafAddressf12b50.h"
extern unsigned char leaf_global;
void* LeafAddressf12b50::Address() { return &leaf_global; }
