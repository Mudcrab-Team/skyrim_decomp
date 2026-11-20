// Source exposure: binary-analysis; no external implementation source reused.
// Static178bed0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178bed0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178bed0*);
    virtual void release(Static178bed0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178bed0*);
struct Static178bed0 {
    void* value;
    Static178bed0();
    ~Static178bed0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
