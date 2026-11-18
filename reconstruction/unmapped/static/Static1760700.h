// Source exposure: binary-analysis; no external implementation source reused.
// Static1760700, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1760700;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1760700*);
    virtual void release(Static1760700*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1760700*);
struct Static1760700 {
    void* value;
    Static1760700();
    ~Static1760700() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
