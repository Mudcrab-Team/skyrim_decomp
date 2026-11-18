// Source exposure: binary-analysis; no external implementation source reused.
// Static1763770, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1763770;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1763770*);
    virtual void release(Static1763770*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1763770*);
struct Static1763770 {
    void* value;
    Static1763770();
    ~Static1763770() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
