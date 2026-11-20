// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PostFlushNotify_vtbl; size 0x18
#pragma once
struct PostFlushNotify_vtbl {
    void (*_dtor_PostFlushNotify)(void);
    bool (*DoOnNotify)(void);
    void (*DoOnFinalize)(void);
};
static_assert(sizeof(PostFlushNotify_vtbl) == 24, "PostFlushNotify_vtbl layout differs from the PDB");
