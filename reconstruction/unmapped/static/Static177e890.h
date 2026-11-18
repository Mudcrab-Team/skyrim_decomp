// Source exposure: binary-analysis; no external implementation source reused.
// Static177e890, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177e890;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177e890*);
    virtual void release(Static177e890*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177e890*);
struct Static177e890 {
    void* value;
    Static177e890();
    ~Static177e890() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
