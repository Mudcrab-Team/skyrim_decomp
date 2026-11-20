// Source exposure: binary-analysis; no external implementation source reused.
// Static1785af0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1785af0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1785af0*);
    virtual void release(Static1785af0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1785af0*);
struct Static1785af0 {
    void* value;
    Static1785af0();
    ~Static1785af0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
