// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1e85e0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1e85e0 TESIcon::GetDefaultPath
#include "LeafAddress1e85e0.h"
extern unsigned char leaf_global;
void* LeafAddress1e85e0::Address() { return &leaf_global; }
