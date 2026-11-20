// Source exposure: binary-analysis; no external implementation source reused.
// Static176e8f0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176e8f0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176e8f0*);
    virtual void release(Static176e8f0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176e8f0*);
struct Static176e8f0 {
    void* value;
    Static176e8f0();
    ~Static176e8f0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
