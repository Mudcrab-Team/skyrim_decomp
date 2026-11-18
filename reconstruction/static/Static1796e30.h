// Source exposure: binary-analysis; no external implementation source reused.
// Static1796e30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1796e30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1796e30*);
    virtual void release(Static1796e30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1796e30*);
struct Static1796e30 {
    void* value;
    Static1796e30();
    ~Static1796e30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
