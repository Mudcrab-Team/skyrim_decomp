// Source exposure: binary-analysis; no external implementation source reused.
// Static1742050, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1742050;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1742050*);
    virtual void release(Static1742050*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1742050*);
struct Static1742050 {
    void* value;
    Static1742050();
    ~Static1742050() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
