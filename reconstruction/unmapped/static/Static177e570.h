// Source exposure: binary-analysis; no external implementation source reused.
// Static177e570, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177e570;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177e570*);
    virtual void release(Static177e570*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177e570*);
struct Static177e570 {
    void* value;
    Static177e570();
    ~Static177e570() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
