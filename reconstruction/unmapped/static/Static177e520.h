// Source exposure: binary-analysis; no external implementation source reused.
// Static177e520, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177e520;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177e520*);
    virtual void release(Static177e520*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177e520*);
struct Static177e520 {
    void* value;
    Static177e520();
    ~Static177e520() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
