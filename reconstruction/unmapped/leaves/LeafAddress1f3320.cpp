// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1f3320, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1f3320 TESTexture::GetDefaultPath
#include "LeafAddress1f3320.h"
extern unsigned char leaf_global;
void* LeafAddress1f3320::Address() { return &leaf_global; }
