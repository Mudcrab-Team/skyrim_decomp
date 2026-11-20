// Source exposure: binary-analysis; no external implementation source reused.
// Static1759680, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1759680;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1759680*);
    virtual void release(Static1759680*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1759680*);
struct Static1759680 {
    void* value;
    Static1759680();
    ~Static1759680() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
