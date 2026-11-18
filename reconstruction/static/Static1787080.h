// Source exposure: binary-analysis; no external implementation source reused.
// Static1787080, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1787080;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1787080*);
    virtual void release(Static1787080*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1787080*);
struct Static1787080 {
    void* value;
    Static1787080();
    ~Static1787080() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
