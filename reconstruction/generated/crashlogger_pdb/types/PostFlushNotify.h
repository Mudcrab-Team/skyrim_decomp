// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PostFlushNotify; size 0x18
#pragma once

struct PostFlushNotify_vtbl;
struct PostFlushNotify {
    PostFlushNotify_vtbl* __vftable;
    unsigned int state;
    unsigned char undefined_c[4];
    PostFlushNotify* next;
};
static_assert(sizeof(PostFlushNotify) == 24, "PostFlushNotify layout differs from the PDB");
