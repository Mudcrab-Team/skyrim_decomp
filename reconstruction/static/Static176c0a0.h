// Source exposure: binary-analysis; no external implementation source reused.
// Static176c0a0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176c0a0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176c0a0*);
    virtual void release(Static176c0a0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176c0a0*);
struct Static176c0a0 {
    void* value;
    Static176c0a0();
    ~Static176c0a0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
