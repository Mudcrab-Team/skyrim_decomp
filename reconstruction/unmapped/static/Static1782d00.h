// Source exposure: binary-analysis; no external implementation source reused.
// Static1782d00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1782d00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1782d00*);
    virtual void release(Static1782d00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1782d00*);
struct Static1782d00 {
    void* value;
    Static1782d00();
    ~Static1782d00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
