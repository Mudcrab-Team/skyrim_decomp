// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf5b6a0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf5b6a0 NiMultiTargetTransformController::GetRTTI
#include "LeafAddressf5b6a0.h"
extern unsigned char leaf_global;
void* LeafAddressf5b6a0::Address() { return &leaf_global; }
