// Source exposure: binary-analysis; no external implementation source reused.
// Static173d600, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173d600;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173d600*);
    virtual void release(Static173d600*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173d600*);
struct Static173d600 {
    void* value;
    Static173d600();
    ~Static173d600() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
