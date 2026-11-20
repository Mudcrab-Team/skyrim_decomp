// Source exposure: binary-analysis; no external implementation source reused.
// Static1790570, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1790570;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1790570*);
    virtual void release(Static1790570*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1790570*);
struct Static1790570 {
    void* value;
    Static1790570();
    ~Static1790570() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
