// Source exposure: binary-analysis; no external implementation source reused.
// Static177c8b0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177c8b0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177c8b0*);
    virtual void release(Static177c8b0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177c8b0*);
struct Static177c8b0 {
    void* value;
    Static177c8b0();
    ~Static177c8b0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
