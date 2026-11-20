// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressef3ef0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xef3ef0 NiSourceTexture::GetRTTI
#include "LeafAddressef3ef0.h"
extern unsigned char leaf_global;
void* LeafAddressef3ef0::Address() { return &leaf_global; }
