// Source exposure: binary-analysis; no external implementation source reused.
// Static178c8d0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178c8d0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178c8d0*);
    virtual void release(Static178c8d0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178c8d0*);
struct Static178c8d0 {
    void* value;
    Static178c8d0();
    ~Static178c8d0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
