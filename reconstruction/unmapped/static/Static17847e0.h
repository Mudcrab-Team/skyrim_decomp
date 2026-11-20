// Source exposure: binary-analysis; no external implementation source reused.
// Static17847e0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17847e0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17847e0*);
    virtual void release(Static17847e0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17847e0*);
struct Static17847e0 {
    void* value;
    Static17847e0();
    ~Static17847e0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
