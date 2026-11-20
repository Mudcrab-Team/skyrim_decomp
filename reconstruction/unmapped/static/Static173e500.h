// Source exposure: binary-analysis; no external implementation source reused.
// Static173e500, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173e500;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173e500*);
    virtual void release(Static173e500*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173e500*);
struct Static173e500 {
    void* value;
    Static173e500();
    ~Static173e500() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
