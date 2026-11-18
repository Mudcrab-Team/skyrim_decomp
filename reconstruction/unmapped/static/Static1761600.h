// Source exposure: binary-analysis; no external implementation source reused.
// Static1761600, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1761600;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1761600*);
    virtual void release(Static1761600*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1761600*);
struct Static1761600 {
    void* value;
    Static1761600();
    ~Static1761600() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
