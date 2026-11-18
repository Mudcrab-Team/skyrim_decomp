// Source exposure: binary-analysis; no external implementation source reused.
// Static176e9e0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176e9e0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176e9e0*);
    virtual void release(Static176e9e0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176e9e0*);
struct Static176e9e0 {
    void* value;
    Static176e9e0();
    ~Static176e9e0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
