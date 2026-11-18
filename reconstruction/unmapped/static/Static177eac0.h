// Source exposure: binary-analysis; no external implementation source reused.
// Static177eac0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177eac0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177eac0*);
    virtual void release(Static177eac0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177eac0*);
struct Static177eac0 {
    void* value;
    Static177eac0();
    ~Static177eac0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
