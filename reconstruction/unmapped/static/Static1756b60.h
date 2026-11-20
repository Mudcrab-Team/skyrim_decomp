// Source exposure: binary-analysis; no external implementation source reused.
// Static1756b60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1756b60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1756b60*);
    virtual void release(Static1756b60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1756b60*);
struct Static1756b60 {
    void* value;
    Static1756b60();
    ~Static1756b60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
