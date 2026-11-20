// Source exposure: binary-analysis; no external implementation source reused.
// Static1788b60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1788b60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1788b60*);
    virtual void release(Static1788b60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1788b60*);
struct Static1788b60 {
    void* value;
    Static1788b60();
    ~Static1788b60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
