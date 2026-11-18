// Source exposure: binary-analysis; no external implementation source reused.
// Static177e340, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177e340;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177e340*);
    virtual void release(Static177e340*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177e340*);
struct Static177e340 {
    void* value;
    Static177e340();
    ~Static177e340() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
