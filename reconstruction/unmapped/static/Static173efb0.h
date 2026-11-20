// Source exposure: binary-analysis; no external implementation source reused.
// Static173efb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173efb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173efb0*);
    virtual void release(Static173efb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173efb0*);
struct Static173efb0 {
    void* value;
    Static173efb0();
    ~Static173efb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
