// Source exposure: binary-analysis; no external implementation source reused.
// Static17b3530, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b3530;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b3530*);
    virtual void release(Static17b3530*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b3530*);
struct Static17b3530 {
    void* value;
    Static17b3530();
    ~Static17b3530() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
