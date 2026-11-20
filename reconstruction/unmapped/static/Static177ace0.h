// Source exposure: binary-analysis; no external implementation source reused.
// Static177ace0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177ace0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177ace0*);
    virtual void release(Static177ace0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177ace0*);
struct Static177ace0 {
    void* value;
    Static177ace0();
    ~Static177ace0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
