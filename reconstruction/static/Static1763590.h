// Source exposure: binary-analysis; no external implementation source reused.
// Static1763590, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1763590;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1763590*);
    virtual void release(Static1763590*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1763590*);
struct Static1763590 {
    void* value;
    Static1763590();
    ~Static1763590() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
