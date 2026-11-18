// Source exposure: binary-analysis; no external implementation source reused.
// Static1789c10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1789c10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1789c10*);
    virtual void release(Static1789c10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1789c10*);
struct Static1789c10 {
    void* value;
    Static1789c10();
    ~Static1789c10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
