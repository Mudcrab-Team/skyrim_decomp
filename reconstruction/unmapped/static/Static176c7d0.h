// Source exposure: binary-analysis; no external implementation source reused.
// Static176c7d0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176c7d0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176c7d0*);
    virtual void release(Static176c7d0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176c7d0*);
struct Static176c7d0 {
    void* value;
    Static176c7d0();
    ~Static176c7d0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
