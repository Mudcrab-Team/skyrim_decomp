// Source exposure: binary-analysis; no external implementation source reused.
// Static1790430, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1790430;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1790430*);
    virtual void release(Static1790430*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1790430*);
struct Static1790430 {
    void* value;
    Static1790430();
    ~Static1790430() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
