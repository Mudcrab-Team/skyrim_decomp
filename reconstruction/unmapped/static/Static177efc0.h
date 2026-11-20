// Source exposure: binary-analysis; no external implementation source reused.
// Static177efc0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177efc0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177efc0*);
    virtual void release(Static177efc0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177efc0*);
struct Static177efc0 {
    void* value;
    Static177efc0();
    ~Static177efc0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
