// Source exposure: binary-analysis; no external implementation source reused.
// Static17428e0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17428e0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17428e0*);
    virtual void release(Static17428e0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17428e0*);
struct Static17428e0 {
    void* value;
    Static17428e0();
    ~Static17428e0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
