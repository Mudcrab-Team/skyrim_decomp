// Source exposure: binary-analysis; no external implementation source reused.
// Static1768770, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1768770;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1768770*);
    virtual void release(Static1768770*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1768770*);
struct Static1768770 {
    void* value;
    Static1768770();
    ~Static1768770() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
