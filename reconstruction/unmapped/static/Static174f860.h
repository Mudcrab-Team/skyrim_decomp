// Source exposure: binary-analysis; no external implementation source reused.
// Static174f860, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174f860;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174f860*);
    virtual void release(Static174f860*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174f860*);
struct Static174f860 {
    void* value;
    Static174f860();
    ~Static174f860() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
