// Source exposure: binary-analysis; no external implementation source reused.
// Static1787120, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1787120;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1787120*);
    virtual void release(Static1787120*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1787120*);
struct Static1787120 {
    void* value;
    Static1787120();
    ~Static1787120() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
