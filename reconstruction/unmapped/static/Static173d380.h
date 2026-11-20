// Source exposure: binary-analysis; no external implementation source reused.
// Static173d380, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173d380;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173d380*);
    virtual void release(Static173d380*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173d380*);
struct Static173d380 {
    void* value;
    Static173d380();
    ~Static173d380() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
