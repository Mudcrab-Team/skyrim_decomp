// Source exposure: binary-analysis; no external implementation source reused.
// Static1766010, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1766010;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1766010*);
    virtual void release(Static1766010*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1766010*);
struct Static1766010 {
    void* value;
    Static1766010();
    ~Static1766010() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
