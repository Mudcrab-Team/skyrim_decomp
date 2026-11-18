// Source exposure: binary-analysis; no external implementation source reused.
// Static1763900, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1763900;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1763900*);
    virtual void release(Static1763900*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1763900*);
struct Static1763900 {
    void* value;
    Static1763900();
    ~Static1763900() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
