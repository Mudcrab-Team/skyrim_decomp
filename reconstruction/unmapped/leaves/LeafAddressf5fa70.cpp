// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf5fa70, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf5fa70 NiInterpController::GetRTTI
#include "LeafAddressf5fa70.h"
extern unsigned char leaf_global;
void* LeafAddressf5fa70::Address() { return &leaf_global; }
