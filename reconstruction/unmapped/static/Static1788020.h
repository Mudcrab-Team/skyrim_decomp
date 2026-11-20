// Source exposure: binary-analysis; no external implementation source reused.
// Static1788020, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1788020;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1788020*);
    virtual void release(Static1788020*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1788020*);
struct Static1788020 {
    void* value;
    Static1788020();
    ~Static1788020() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
