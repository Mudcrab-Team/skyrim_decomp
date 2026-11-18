// Source exposure: binary-analysis; no external implementation source reused.
// Static1742570, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1742570;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1742570*);
    virtual void release(Static1742570*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1742570*);
struct Static1742570 {
    void* value;
    Static1742570();
    ~Static1742570() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
