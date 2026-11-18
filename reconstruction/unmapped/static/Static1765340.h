// Source exposure: binary-analysis; no external implementation source reused.
// Static1765340, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1765340;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1765340*);
    virtual void release(Static1765340*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1765340*);
struct Static1765340 {
    void* value;
    Static1765340();
    ~Static1765340() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
