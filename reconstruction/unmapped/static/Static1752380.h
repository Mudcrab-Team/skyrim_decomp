// Source exposure: binary-analysis; no external implementation source reused.
// Static1752380, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1752380;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1752380*);
    virtual void release(Static1752380*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1752380*);
struct Static1752380 {
    void* value;
    Static1752380();
    ~Static1752380() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
