// Source exposure: binary-analysis; no external implementation source reused.
// Static1767050, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1767050;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1767050*);
    virtual void release(Static1767050*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1767050*);
struct Static1767050 {
    void* value;
    Static1767050();
    ~Static1767050() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
