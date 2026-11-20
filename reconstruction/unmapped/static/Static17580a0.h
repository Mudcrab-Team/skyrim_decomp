// Source exposure: binary-analysis; no external implementation source reused.
// Static17580a0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17580a0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17580a0*);
    virtual void release(Static17580a0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17580a0*);
struct Static17580a0 {
    void* value;
    Static17580a0();
    ~Static17580a0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
