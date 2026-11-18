// Source exposure: binary-analysis; no external implementation source reused.
// Static177e070, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177e070;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177e070*);
    virtual void release(Static177e070*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177e070*);
struct Static177e070 {
    void* value;
    Static177e070();
    ~Static177e070() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
