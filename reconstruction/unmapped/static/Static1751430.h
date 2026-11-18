// Source exposure: binary-analysis; no external implementation source reused.
// Static1751430, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1751430;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1751430*);
    virtual void release(Static1751430*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1751430*);
struct Static1751430 {
    void* value;
    Static1751430();
    ~Static1751430() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
