// Source exposure: binary-analysis; no external implementation source reused.
// Static17aaca0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17aaca0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17aaca0*);
    virtual void release(Static17aaca0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17aaca0*);
struct Static17aaca0 {
    void* value;
    Static17aaca0();
    ~Static17aaca0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
