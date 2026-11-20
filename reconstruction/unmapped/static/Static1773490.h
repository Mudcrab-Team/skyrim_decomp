// Source exposure: binary-analysis; no external implementation source reused.
// Static1773490, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1773490;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1773490*);
    virtual void release(Static1773490*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1773490*);
struct Static1773490 {
    void* value;
    Static1773490();
    ~Static1773490() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
