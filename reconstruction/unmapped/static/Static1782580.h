// Source exposure: binary-analysis; no external implementation source reused.
// Static1782580, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1782580;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1782580*);
    virtual void release(Static1782580*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1782580*);
struct Static1782580 {
    void* value;
    Static1782580();
    ~Static1782580() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
