// Source exposure: binary-analysis; no external implementation source reused.
// Static177e110, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177e110;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177e110*);
    virtual void release(Static177e110*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177e110*);
struct Static177e110 {
    void* value;
    Static177e110();
    ~Static177e110() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
