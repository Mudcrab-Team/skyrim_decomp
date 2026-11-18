// Source exposure: binary-analysis; no external implementation source reused.
// Static17c58e0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17c58e0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17c58e0*);
    virtual void release(Static17c58e0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17c58e0*);
struct Static17c58e0 {
    void* value;
    Static17c58e0();
    ~Static17c58e0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
