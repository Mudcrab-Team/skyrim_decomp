// Source exposure: binary-analysis; no external implementation source reused.
// Static1761330, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1761330;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1761330*);
    virtual void release(Static1761330*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1761330*);
struct Static1761330 {
    void* value;
    Static1761330();
    ~Static1761330() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
