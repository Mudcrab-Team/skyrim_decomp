// Source exposure: binary-analysis; no external implementation source reused.
// Static1754220, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1754220;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1754220*);
    virtual void release(Static1754220*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1754220*);
struct Static1754220 {
    void* value;
    Static1754220();
    ~Static1754220() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
