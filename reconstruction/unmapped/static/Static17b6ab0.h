// Source exposure: binary-analysis; no external implementation source reused.
// Static17b6ab0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b6ab0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b6ab0*);
    virtual void release(Static17b6ab0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b6ab0*);
struct Static17b6ab0 {
    void* value;
    Static17b6ab0();
    ~Static17b6ab0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
