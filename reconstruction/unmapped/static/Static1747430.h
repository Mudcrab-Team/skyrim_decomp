// Source exposure: binary-analysis; no external implementation source reused.
// Static1747430, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1747430;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1747430*);
    virtual void release(Static1747430*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1747430*);
struct Static1747430 {
    void* value;
    Static1747430();
    ~Static1747430() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
