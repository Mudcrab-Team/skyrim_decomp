// Source exposure: binary-analysis; no external implementation source reused.
// Static1788430, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1788430;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1788430*);
    virtual void release(Static1788430*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1788430*);
struct Static1788430 {
    void* value;
    Static1788430();
    ~Static1788430() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
