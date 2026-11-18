// Source exposure: binary-analysis; no external implementation source reused.
// Static177e1b0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177e1b0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177e1b0*);
    virtual void release(Static177e1b0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177e1b0*);
struct Static177e1b0 {
    void* value;
    Static177e1b0();
    ~Static177e1b0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
