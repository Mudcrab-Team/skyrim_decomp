// Source exposure: binary-analysis; no external implementation source reused.
// Static1775880, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1775880;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1775880*);
    virtual void release(Static1775880*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1775880*);
struct Static1775880 {
    void* value;
    Static1775880();
    ~Static1775880() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
