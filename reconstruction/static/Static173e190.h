// Source exposure: binary-analysis; no external implementation source reused.
// Static173e190, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173e190;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173e190*);
    virtual void release(Static173e190*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173e190*);
struct Static173e190 {
    void* value;
    Static173e190();
    ~Static173e190() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
