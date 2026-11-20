// Source exposure: binary-analysis; no external implementation source reused.
// Static1758320, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1758320;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1758320*);
    virtual void release(Static1758320*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1758320*);
struct Static1758320 {
    void* value;
    Static1758320();
    ~Static1758320() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
