// Source exposure: binary-analysis; no external implementation source reused.
// Static17888e0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17888e0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17888e0*);
    virtual void release(Static17888e0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17888e0*);
struct Static17888e0 {
    void* value;
    Static17888e0();
    ~Static17888e0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
