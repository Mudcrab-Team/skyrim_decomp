// Source exposure: binary-analysis; no external implementation source reused.
// Static1769300, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1769300;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1769300*);
    virtual void release(Static1769300*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1769300*);
struct Static1769300 {
    void* value;
    Static1769300();
    ~Static1769300() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
