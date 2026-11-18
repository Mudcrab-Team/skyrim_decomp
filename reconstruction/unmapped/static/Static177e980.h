// Source exposure: binary-analysis; no external implementation source reused.
// Static177e980, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177e980;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177e980*);
    virtual void release(Static177e980*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177e980*);
struct Static177e980 {
    void* value;
    Static177e980();
    ~Static177e980() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
