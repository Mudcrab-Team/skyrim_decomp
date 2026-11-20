// Source exposure: binary-analysis; no external implementation source reused.
// Static177e610, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177e610;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177e610*);
    virtual void release(Static177e610*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177e610*);
struct Static177e610 {
    void* value;
    Static177e610();
    ~Static177e610() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
