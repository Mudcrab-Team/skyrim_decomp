// Source exposure: binary-analysis; no external implementation source reused.
// Static1789260, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1789260;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1789260*);
    virtual void release(Static1789260*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1789260*);
struct Static1789260 {
    void* value;
    Static1789260();
    ~Static1789260() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
