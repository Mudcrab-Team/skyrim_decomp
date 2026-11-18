// Source exposure: binary-analysis; no external implementation source reused.
// Static1794b60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1794b60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1794b60*);
    virtual void release(Static1794b60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1794b60*);
struct Static1794b60 {
    void* value;
    Static1794b60();
    ~Static1794b60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
