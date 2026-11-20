// Source exposure: binary-analysis; no external implementation source reused.
// Static1788570, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1788570;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1788570*);
    virtual void release(Static1788570*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1788570*);
struct Static1788570 {
    void* value;
    Static1788570();
    ~Static1788570() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
