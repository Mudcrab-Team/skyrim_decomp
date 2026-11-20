// Source exposure: binary-analysis; no external implementation source reused.
// Static17c5e30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17c5e30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17c5e30*);
    virtual void release(Static17c5e30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17c5e30*);
struct Static17c5e30 {
    void* value;
    Static17c5e30();
    ~Static17c5e30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
