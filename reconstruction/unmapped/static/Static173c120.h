// Source exposure: binary-analysis; no external implementation source reused.
// Static173c120, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173c120;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173c120*);
    virtual void release(Static173c120*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173c120*);
struct Static173c120 {
    void* value;
    Static173c120();
    ~Static173c120() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
