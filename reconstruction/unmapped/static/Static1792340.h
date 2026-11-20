// Source exposure: binary-analysis; no external implementation source reused.
// Static1792340, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1792340;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1792340*);
    virtual void release(Static1792340*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1792340*);
struct Static1792340 {
    void* value;
    Static1792340();
    ~Static1792340() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
