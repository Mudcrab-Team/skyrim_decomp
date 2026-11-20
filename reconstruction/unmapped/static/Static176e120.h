// Source exposure: binary-analysis; no external implementation source reused.
// Static176e120, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176e120;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176e120*);
    virtual void release(Static176e120*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176e120*);
struct Static176e120 {
    void* value;
    Static176e120();
    ~Static176e120() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
