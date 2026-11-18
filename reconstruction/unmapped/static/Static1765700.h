// Source exposure: binary-analysis; no external implementation source reused.
// Static1765700, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1765700;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1765700*);
    virtual void release(Static1765700*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1765700*);
struct Static1765700 {
    void* value;
    Static1765700();
    ~Static1765700() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
