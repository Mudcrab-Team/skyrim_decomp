// Source exposure: binary-analysis; no external implementation source reused.
// Static17aafc0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17aafc0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17aafc0*);
    virtual void release(Static17aafc0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17aafc0*);
struct Static17aafc0 {
    void* value;
    Static17aafc0();
    ~Static17aafc0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
