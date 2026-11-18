// Source exposure: binary-analysis; no external implementation source reused.
// Static177e3e0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177e3e0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177e3e0*);
    virtual void release(Static177e3e0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177e3e0*);
struct Static177e3e0 {
    void* value;
    Static177e3e0();
    ~Static177e3e0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
