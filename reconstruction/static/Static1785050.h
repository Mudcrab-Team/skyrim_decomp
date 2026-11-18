// Source exposure: binary-analysis; no external implementation source reused.
// Static1785050, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1785050;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1785050*);
    virtual void release(Static1785050*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1785050*);
struct Static1785050 {
    void* value;
    Static1785050();
    ~Static1785050() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
