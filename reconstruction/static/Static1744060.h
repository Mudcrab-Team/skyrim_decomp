// Source exposure: binary-analysis; no external implementation source reused.
// Static1744060, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1744060;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1744060*);
    virtual void release(Static1744060*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1744060*);
struct Static1744060 {
    void* value;
    Static1744060();
    ~Static1744060() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
