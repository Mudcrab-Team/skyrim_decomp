// Source exposure: binary-analysis; no external implementation source reused.
// Static177e480, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177e480;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177e480*);
    virtual void release(Static177e480*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177e480*);
struct Static177e480 {
    void* value;
    Static177e480();
    ~Static177e480() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
