// Source exposure: binary-analysis; no external implementation source reused.
// Static1747c90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1747c90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1747c90*);
    virtual void release(Static1747c90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1747c90*);
struct Static1747c90 {
    void* value;
    Static1747c90();
    ~Static1747c90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
