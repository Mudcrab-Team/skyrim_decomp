// Source exposure: binary-analysis; no external implementation source reused.
// Static177e700, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177e700;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177e700*);
    virtual void release(Static177e700*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177e700*);
struct Static177e700 {
    void* value;
    Static177e700();
    ~Static177e700() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
