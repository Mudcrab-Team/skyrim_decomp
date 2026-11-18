// Source exposure: binary-analysis; no external implementation source reused.
// Static1763b80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1763b80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1763b80*);
    virtual void release(Static1763b80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1763b80*);
struct Static1763b80 {
    void* value;
    Static1763b80();
    ~Static1763b80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
