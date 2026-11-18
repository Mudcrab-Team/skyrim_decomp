// Source exposure: binary-analysis; no external implementation source reused.
// Static177e020, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177e020;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177e020*);
    virtual void release(Static177e020*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177e020*);
struct Static177e020 {
    void* value;
    Static177e020();
    ~Static177e020() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
