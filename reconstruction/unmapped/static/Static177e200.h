// Source exposure: binary-analysis; no external implementation source reused.
// Static177e200, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177e200;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177e200*);
    virtual void release(Static177e200*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177e200*);
struct Static177e200 {
    void* value;
    Static177e200();
    ~Static177e200() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
