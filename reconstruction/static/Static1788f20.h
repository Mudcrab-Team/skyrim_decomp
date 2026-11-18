// Source exposure: binary-analysis; no external implementation source reused.
// Static1788f20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1788f20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1788f20*);
    virtual void release(Static1788f20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1788f20*);
struct Static1788f20 {
    void* value;
    Static1788f20();
    ~Static1788f20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
