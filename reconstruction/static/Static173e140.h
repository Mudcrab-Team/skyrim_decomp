// Source exposure: binary-analysis; no external implementation source reused.
// Static173e140, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173e140;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173e140*);
    virtual void release(Static173e140*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173e140*);
struct Static173e140 {
    void* value;
    Static173e140();
    ~Static173e140() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
