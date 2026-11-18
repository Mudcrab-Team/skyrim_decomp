// Source exposure: binary-analysis; no external implementation source reused.
// Static17afb40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17afb40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17afb40*);
    virtual void release(Static17afb40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17afb40*);
struct Static17afb40 {
    void* value;
    Static17afb40();
    ~Static17afb40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
