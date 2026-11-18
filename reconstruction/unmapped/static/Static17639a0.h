// Source exposure: binary-analysis; no external implementation source reused.
// Static17639a0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17639a0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17639a0*);
    virtual void release(Static17639a0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17639a0*);
struct Static17639a0 {
    void* value;
    Static17639a0();
    ~Static17639a0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
