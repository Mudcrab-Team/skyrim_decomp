// Source exposure: binary-analysis; no external implementation source reused.
// Static176e800, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176e800;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176e800*);
    virtual void release(Static176e800*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176e800*);
struct Static176e800 {
    void* value;
    Static176e800();
    ~Static176e800() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
