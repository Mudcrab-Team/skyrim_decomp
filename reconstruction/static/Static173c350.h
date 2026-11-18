// Source exposure: binary-analysis; no external implementation source reused.
// Static173c350, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173c350;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173c350*);
    virtual void release(Static173c350*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173c350*);
struct Static173c350 {
    void* value;
    Static173c350();
    ~Static173c350() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
