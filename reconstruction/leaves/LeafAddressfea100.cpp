// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfea100, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfea100 BSPortalSharedNode::GetRTTI
#include "LeafAddressfea100.h"
extern unsigned char leaf_global;
void* LeafAddressfea100::Address() { return &leaf_global; }
