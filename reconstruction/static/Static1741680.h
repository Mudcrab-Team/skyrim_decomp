// Source exposure: binary-analysis; no external implementation source reused.
// Static1741680, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1741680;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1741680*);
    virtual void release(Static1741680*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1741680*);
struct Static1741680 {
    void* value;
    Static1741680();
    ~Static1741680() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
