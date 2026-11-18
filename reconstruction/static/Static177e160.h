// Source exposure: binary-analysis; no external implementation source reused.
// Static177e160, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177e160;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177e160*);
    virtual void release(Static177e160*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177e160*);
struct Static177e160 {
    void* value;
    Static177e160();
    ~Static177e160() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
