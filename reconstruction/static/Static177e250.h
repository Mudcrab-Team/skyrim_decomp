// Source exposure: binary-analysis; no external implementation source reused.
// Static177e250, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177e250;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177e250*);
    virtual void release(Static177e250*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177e250*);
struct Static177e250 {
    void* value;
    Static177e250();
    ~Static177e250() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
