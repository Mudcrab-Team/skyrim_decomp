// Source exposure: binary-analysis; no external implementation source reused.
// Static1765570, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1765570;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1765570*);
    virtual void release(Static1765570*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1765570*);
struct Static1765570 {
    void* value;
    Static1765570();
    ~Static1765570() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
