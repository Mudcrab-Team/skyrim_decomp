// Source exposure: binary-analysis; no external implementation source reused.
// Static17738f0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17738f0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17738f0*);
    virtual void release(Static17738f0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17738f0*);
struct Static17738f0 {
    void* value;
    Static17738f0();
    ~Static17738f0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
