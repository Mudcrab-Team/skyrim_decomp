// Source exposure: binary-analysis; no external implementation reused.
// LeafAddresscd7010, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xcd7010 BSXAudio2Audio::GetSystemName
#include "LeafAddresscd7010.h"
extern unsigned char leaf_global;
void* LeafAddresscd7010::Address() { return &leaf_global; }
