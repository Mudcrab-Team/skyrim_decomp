// Source exposure: binary-analysis; no external implementation source reused.
// Static17748e0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17748e0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17748e0*);
    virtual void release(Static17748e0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17748e0*);
struct Static17748e0 {
    void* value;
    Static17748e0();
    ~Static17748e0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
