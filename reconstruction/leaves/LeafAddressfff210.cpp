// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfff210, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfff210 BSInvMarker::GetRTTI
#include "LeafAddressfff210.h"
extern unsigned char leaf_global;
void* LeafAddressfff210::Address() { return &leaf_global; }
