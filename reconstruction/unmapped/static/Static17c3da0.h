// Source exposure: binary-analysis; no external implementation source reused.
// Static17c3da0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17c3da0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17c3da0*);
    virtual void release(Static17c3da0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17c3da0*);
struct Static17c3da0 {
    void* value;
    Static17c3da0();
    ~Static17c3da0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
