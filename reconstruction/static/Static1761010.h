// Source exposure: binary-analysis; no external implementation source reused.
// Static1761010, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1761010;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1761010*);
    virtual void release(Static1761010*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1761010*);
struct Static1761010 {
    void* value;
    Static1761010();
    ~Static1761010() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
