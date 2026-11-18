// Source exposure: binary-analysis; no external implementation source reused.
// Static176e6c0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176e6c0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176e6c0*);
    virtual void release(Static176e6c0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176e6c0*);
struct Static176e6c0 {
    void* value;
    Static176e6c0();
    ~Static176e6c0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
