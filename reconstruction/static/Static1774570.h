// Source exposure: binary-analysis; no external implementation source reused.
// Static1774570, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1774570;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1774570*);
    virtual void release(Static1774570*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1774570*);
struct Static1774570 {
    void* value;
    Static1774570();
    ~Static1774570() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
