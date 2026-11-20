// Source exposure: binary-analysis; no external implementation source reused.
// Static1765430, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1765430;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1765430*);
    virtual void release(Static1765430*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1765430*);
struct Static1765430 {
    void* value;
    Static1765430();
    ~Static1765430() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
