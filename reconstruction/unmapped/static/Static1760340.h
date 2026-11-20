// Source exposure: binary-analysis; no external implementation source reused.
// Static1760340, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1760340;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1760340*);
    virtual void release(Static1760340*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1760340*);
struct Static1760340 {
    void* value;
    Static1760340();
    ~Static1760340() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
