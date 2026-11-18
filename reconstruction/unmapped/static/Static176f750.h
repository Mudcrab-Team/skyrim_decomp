// Source exposure: binary-analysis; no external implementation source reused.
// Static176f750, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176f750;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176f750*);
    virtual void release(Static176f750*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176f750*);
struct Static176f750 {
    void* value;
    Static176f750();
    ~Static176f750() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
