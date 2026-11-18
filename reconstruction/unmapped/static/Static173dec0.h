// Source exposure: binary-analysis; no external implementation source reused.
// Static173dec0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173dec0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173dec0*);
    virtual void release(Static173dec0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173dec0*);
struct Static173dec0 {
    void* value;
    Static173dec0();
    ~Static173dec0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
