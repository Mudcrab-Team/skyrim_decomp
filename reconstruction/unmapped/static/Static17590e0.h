// Source exposure: binary-analysis; no external implementation source reused.
// Static17590e0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17590e0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17590e0*);
    virtual void release(Static17590e0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17590e0*);
struct Static17590e0 {
    void* value;
    Static17590e0();
    ~Static17590e0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
