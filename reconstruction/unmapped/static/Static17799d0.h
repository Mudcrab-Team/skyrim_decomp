// Source exposure: binary-analysis; no external implementation source reused.
// Static17799d0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17799d0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17799d0*);
    virtual void release(Static17799d0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17799d0*);
struct Static17799d0 {
    void* value;
    Static17799d0();
    ~Static17799d0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
