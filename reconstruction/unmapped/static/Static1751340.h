// Source exposure: binary-analysis; no external implementation source reused.
// Static1751340, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1751340;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1751340*);
    virtual void release(Static1751340*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1751340*);
struct Static1751340 {
    void* value;
    Static1751340();
    ~Static1751340() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
