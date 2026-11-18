// Source exposure: binary-analysis; no external implementation source reused.
// Static17421e0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17421e0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17421e0*);
    virtual void release(Static17421e0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17421e0*);
struct Static17421e0 {
    void* value;
    Static17421e0();
    ~Static17421e0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
