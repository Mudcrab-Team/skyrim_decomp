// Source exposure: binary-analysis; no external implementation source reused.
// Static17c4de0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17c4de0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17c4de0*);
    virtual void release(Static17c4de0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17c4de0*);
struct Static17c4de0 {
    void* value;
    Static17c4de0();
    ~Static17c4de0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
