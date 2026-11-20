// Source exposure: binary-analysis; no external implementation source reused.
// Static17909e0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17909e0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17909e0*);
    virtual void release(Static17909e0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17909e0*);
struct Static17909e0 {
    void* value;
    Static17909e0();
    ~Static17909e0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
