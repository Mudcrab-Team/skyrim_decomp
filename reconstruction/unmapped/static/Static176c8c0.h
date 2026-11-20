// Source exposure: binary-analysis; no external implementation source reused.
// Static176c8c0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176c8c0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176c8c0*);
    virtual void release(Static176c8c0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176c8c0*);
struct Static176c8c0 {
    void* value;
    Static176c8c0();
    ~Static176c8c0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
