// Source exposure: binary-analysis; no external implementation source reused.
// Static177e840, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177e840;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177e840*);
    virtual void release(Static177e840*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177e840*);
struct Static177e840 {
    void* value;
    Static177e840();
    ~Static177e840() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
