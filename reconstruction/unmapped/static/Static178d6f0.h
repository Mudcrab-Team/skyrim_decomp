// Source exposure: binary-analysis; no external implementation source reused.
// Static178d6f0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178d6f0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178d6f0*);
    virtual void release(Static178d6f0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178d6f0*);
struct Static178d6f0 {
    void* value;
    Static178d6f0();
    ~Static178d6f0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
