// Source exposure: binary-analysis; no external implementation source reused.
// Static173ce70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173ce70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173ce70*);
    virtual void release(Static173ce70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173ce70*);
struct Static173ce70 {
    void* value;
    Static173ce70();
    ~Static173ce70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
