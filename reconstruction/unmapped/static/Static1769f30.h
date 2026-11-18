// Source exposure: binary-analysis; no external implementation source reused.
// Static1769f30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1769f30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1769f30*);
    virtual void release(Static1769f30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1769f30*);
struct Static1769f30 {
    void* value;
    Static1769f30();
    ~Static1769f30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
