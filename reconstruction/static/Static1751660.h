// Source exposure: binary-analysis; no external implementation source reused.
// Static1751660, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1751660;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1751660*);
    virtual void release(Static1751660*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1751660*);
struct Static1751660 {
    void* value;
    Static1751660();
    ~Static1751660() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
