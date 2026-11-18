// Source exposure: binary-analysis; no external implementation source reused.
// Static177cbd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177cbd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177cbd0*);
    virtual void release(Static177cbd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177cbd0*);
struct Static177cbd0 {
    void* value;
    Static177cbd0();
    ~Static177cbd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
