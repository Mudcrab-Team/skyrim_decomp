// Source exposure: binary-analysis; no external implementation source reused.
// Static1760570, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1760570;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1760570*);
    virtual void release(Static1760570*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1760570*);
struct Static1760570 {
    void* value;
    Static1760570();
    ~Static1760570() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
