// Source exposure: binary-analysis; no external implementation source reused.
// Static1763630, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1763630;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1763630*);
    virtual void release(Static1763630*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1763630*);
struct Static1763630 {
    void* value;
    Static1763630();
    ~Static1763630() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
