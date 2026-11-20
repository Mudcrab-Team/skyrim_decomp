// Source exposure: binary-analysis; no external implementation source reused.
// Static177e390, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177e390;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177e390*);
    virtual void release(Static177e390*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177e390*);
struct Static177e390 {
    void* value;
    Static177e390();
    ~Static177e390() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
