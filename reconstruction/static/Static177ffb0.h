// Source exposure: binary-analysis; no external implementation source reused.
// Static177ffb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177ffb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177ffb0*);
    virtual void release(Static177ffb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177ffb0*);
struct Static177ffb0 {
    void* value;
    Static177ffb0();
    ~Static177ffb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
