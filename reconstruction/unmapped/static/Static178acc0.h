// Source exposure: binary-analysis; no external implementation source reused.
// Static178acc0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178acc0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178acc0*);
    virtual void release(Static178acc0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178acc0*);
struct Static178acc0 {
    void* value;
    Static178acc0();
    ~Static178acc0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
