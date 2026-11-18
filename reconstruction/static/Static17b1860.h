// Source exposure: binary-analysis; no external implementation source reused.
// Static17b1860, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b1860;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b1860*);
    virtual void release(Static17b1860*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b1860*);
struct Static17b1860 {
    void* value;
    Static17b1860();
    ~Static17b1860() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
