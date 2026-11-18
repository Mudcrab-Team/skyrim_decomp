// Source exposure: binary-analysis; no external implementation source reused.
// Static177e430, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177e430;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177e430*);
    virtual void release(Static177e430*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177e430*);
struct Static177e430 {
    void* value;
    Static177e430();
    ~Static177e430() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
