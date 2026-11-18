// Source exposure: binary-analysis; no external implementation source reused.
// Static178d7e0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178d7e0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178d7e0*);
    virtual void release(Static178d7e0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178d7e0*);
struct Static178d7e0 {
    void* value;
    Static178d7e0();
    ~Static178d7e0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
