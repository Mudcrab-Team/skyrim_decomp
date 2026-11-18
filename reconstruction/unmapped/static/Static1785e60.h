// Source exposure: binary-analysis; no external implementation source reused.
// Static1785e60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1785e60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1785e60*);
    virtual void release(Static1785e60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1785e60*);
struct Static1785e60 {
    void* value;
    Static1785e60();
    ~Static1785e60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
