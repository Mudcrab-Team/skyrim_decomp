// Source exposure: binary-analysis; no external implementation source reused.
// Static178edf0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178edf0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178edf0*);
    virtual void release(Static178edf0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178edf0*);
struct Static178edf0 {
    void* value;
    Static178edf0();
    ~Static178edf0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
