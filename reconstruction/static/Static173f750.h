// Source exposure: binary-analysis; no external implementation source reused.
// Static173f750, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173f750;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173f750*);
    virtual void release(Static173f750*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173f750*);
struct Static173f750 {
    void* value;
    Static173f750();
    ~Static173f750() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
