// Source exposure: binary-analysis; no external implementation source reused.
// Static1766600, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1766600;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1766600*);
    virtual void release(Static1766600*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1766600*);
struct Static1766600 {
    void* value;
    Static1766600();
    ~Static1766600() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
