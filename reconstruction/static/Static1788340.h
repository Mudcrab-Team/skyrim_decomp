// Source exposure: binary-analysis; no external implementation source reused.
// Static1788340, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1788340;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1788340*);
    virtual void release(Static1788340*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1788340*);
struct Static1788340 {
    void* value;
    Static1788340();
    ~Static1788340() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
