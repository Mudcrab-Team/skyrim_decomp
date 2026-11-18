// Source exposure: binary-analysis; no external implementation source reused.
// Static1763310, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1763310;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1763310*);
    virtual void release(Static1763310*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1763310*);
struct Static1763310 {
    void* value;
    Static1763310();
    ~Static1763310() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
