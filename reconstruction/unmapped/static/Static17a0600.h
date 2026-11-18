// Source exposure: binary-analysis; no external implementation source reused.
// Static17a0600, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17a0600;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17a0600*);
    virtual void release(Static17a0600*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17a0600*);
struct Static17a0600 {
    void* value;
    Static17a0600();
    ~Static17a0600() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
