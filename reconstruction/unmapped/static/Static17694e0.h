// Source exposure: binary-analysis; no external implementation source reused.
// Static17694e0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17694e0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17694e0*);
    virtual void release(Static17694e0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17694e0*);
struct Static17694e0 {
    void* value;
    Static17694e0();
    ~Static17694e0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
