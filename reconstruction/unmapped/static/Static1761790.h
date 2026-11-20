// Source exposure: binary-analysis; no external implementation source reused.
// Static1761790, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1761790;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1761790*);
    virtual void release(Static1761790*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1761790*);
struct Static1761790 {
    void* value;
    Static1761790();
    ~Static1761790() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
