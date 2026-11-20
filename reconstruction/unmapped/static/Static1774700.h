// Source exposure: binary-analysis; no external implementation source reused.
// Static1774700, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1774700;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1774700*);
    virtual void release(Static1774700*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1774700*);
struct Static1774700 {
    void* value;
    Static1774700();
    ~Static1774700() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
