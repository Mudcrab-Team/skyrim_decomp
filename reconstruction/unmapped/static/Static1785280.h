// Source exposure: binary-analysis; no external implementation source reused.
// Static1785280, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1785280;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1785280*);
    virtual void release(Static1785280*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1785280*);
struct Static1785280 {
    void* value;
    Static1785280();
    ~Static1785280() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
