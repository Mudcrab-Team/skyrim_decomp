// Source exposure: binary-analysis; no external implementation source reused.
// Static17b75c0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b75c0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b75c0*);
    virtual void release(Static17b75c0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b75c0*);
struct Static17b75c0 {
    void* value;
    Static17b75c0();
    ~Static17b75c0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
