// Source exposure: binary-analysis; no external implementation source reused.
// Static1757790, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1757790;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1757790*);
    virtual void release(Static1757790*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1757790*);
struct Static1757790 {
    void* value;
    Static1757790();
    ~Static1757790() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
