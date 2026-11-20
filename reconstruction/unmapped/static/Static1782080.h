// Source exposure: binary-analysis; no external implementation source reused.
// Static1782080, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1782080;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1782080*);
    virtual void release(Static1782080*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1782080*);
struct Static1782080 {
    void* value;
    Static1782080();
    ~Static1782080() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
