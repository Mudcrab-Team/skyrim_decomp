// Source exposure: binary-analysis; no external implementation source reused.
// Static1773710, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1773710;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1773710*);
    virtual void release(Static1773710*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1773710*);
struct Static1773710 {
    void* value;
    Static1773710();
    ~Static1773710() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
