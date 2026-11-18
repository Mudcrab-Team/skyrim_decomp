// Source exposure: binary-analysis; no external implementation source reused.
// Static177e930, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177e930;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177e930*);
    virtual void release(Static177e930*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177e930*);
struct Static177e930 {
    void* value;
    Static177e930();
    ~Static177e930() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
