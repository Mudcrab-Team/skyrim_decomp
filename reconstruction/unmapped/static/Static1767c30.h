// Source exposure: binary-analysis; no external implementation source reused.
// Static1767c30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1767c30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1767c30*);
    virtual void release(Static1767c30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1767c30*);
struct Static1767c30 {
    void* value;
    Static1767c30();
    ~Static1767c30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
