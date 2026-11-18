// Source exposure: binary-analysis; no external implementation source reused.
// Static173c580, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173c580;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173c580*);
    virtual void release(Static173c580*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173c580*);
struct Static173c580 {
    void* value;
    Static173c580();
    ~Static173c580() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
