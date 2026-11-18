// Source exposure: binary-analysis; no external implementation source reused.
// Static177c3b0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177c3b0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177c3b0*);
    virtual void release(Static177c3b0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177c3b0*);
struct Static177c3b0 {
    void* value;
    Static177c3b0();
    ~Static177c3b0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
