// Source exposure: binary-analysis; no external implementation source reused.
// Static1749280, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1749280;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1749280*);
    virtual void release(Static1749280*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1749280*);
struct Static1749280 {
    void* value;
    Static1749280();
    ~Static1749280() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
