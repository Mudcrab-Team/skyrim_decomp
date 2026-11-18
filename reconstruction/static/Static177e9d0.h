// Source exposure: binary-analysis; no external implementation source reused.
// Static177e9d0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177e9d0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177e9d0*);
    virtual void release(Static177e9d0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177e9d0*);
struct Static177e9d0 {
    void* value;
    Static177e9d0();
    ~Static177e9d0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
