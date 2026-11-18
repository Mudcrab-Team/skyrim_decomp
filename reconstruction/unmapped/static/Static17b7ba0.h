// Source exposure: binary-analysis; no external implementation source reused.
// Static17b7ba0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b7ba0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b7ba0*);
    virtual void release(Static17b7ba0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b7ba0*);
struct Static17b7ba0 {
    void* value;
    Static17b7ba0();
    ~Static17b7ba0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
