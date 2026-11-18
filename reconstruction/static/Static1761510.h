// Source exposure: binary-analysis; no external implementation source reused.
// Static1761510, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1761510;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1761510*);
    virtual void release(Static1761510*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1761510*);
struct Static1761510 {
    void* value;
    Static1761510();
    ~Static1761510() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
