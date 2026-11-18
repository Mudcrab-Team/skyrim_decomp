// Source exposure: binary-analysis; no external implementation source reused.
// Static173d6a0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173d6a0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173d6a0*);
    virtual void release(Static173d6a0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173d6a0*);
struct Static173d6a0 {
    void* value;
    Static173d6a0();
    ~Static173d6a0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
