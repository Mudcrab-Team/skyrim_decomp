// Source exposure: binary-analysis; no external implementation source reused.
// Static1765b60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1765b60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1765b60*);
    virtual void release(Static1765b60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1765b60*);
struct Static1765b60 {
    void* value;
    Static1765b60();
    ~Static1765b60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
