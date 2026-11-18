// Source exposure: binary-analysis; no external implementation source reused.
// Static177fbf0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177fbf0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177fbf0*);
    virtual void release(Static177fbf0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177fbf0*);
struct Static177fbf0 {
    void* value;
    Static177fbf0();
    ~Static177fbf0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
