// Source exposure: binary-analysis; no external implementation source reused.
// Static1783570, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1783570;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1783570*);
    virtual void release(Static1783570*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1783570*);
struct Static1783570 {
    void* value;
    Static1783570();
    ~Static1783570() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
