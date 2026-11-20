// Source exposure: binary-analysis; no external implementation source reused.
// Static1756430, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1756430;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1756430*);
    virtual void release(Static1756430*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1756430*);
struct Static1756430 {
    void* value;
    Static1756430();
    ~Static1756430() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
