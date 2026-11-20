// Source exposure: binary-analysis; no external implementation source reused.
// Static17500d0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17500d0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17500d0*);
    virtual void release(Static17500d0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17500d0*);
struct Static17500d0 {
    void* value;
    Static17500d0();
    ~Static17500d0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
