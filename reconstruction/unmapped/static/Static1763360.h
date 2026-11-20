// Source exposure: binary-analysis; no external implementation source reused.
// Static1763360, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1763360;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1763360*);
    virtual void release(Static1763360*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1763360*);
struct Static1763360 {
    void* value;
    Static1763360();
    ~Static1763360() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
