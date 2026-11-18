// Source exposure: binary-analysis; no external implementation source reused.
// Static1796050, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1796050;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1796050*);
    virtual void release(Static1796050*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1796050*);
struct Static1796050 {
    void* value;
    Static1796050();
    ~Static1796050() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
