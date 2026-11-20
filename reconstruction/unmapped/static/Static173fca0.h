// Source exposure: binary-analysis; no external implementation source reused.
// Static173fca0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173fca0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173fca0*);
    virtual void release(Static173fca0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173fca0*);
struct Static173fca0 {
    void* value;
    Static173fca0();
    ~Static173fca0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
