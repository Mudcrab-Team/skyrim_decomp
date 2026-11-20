// Source exposure: binary-analysis; no external implementation source reused.
// Static1781c20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1781c20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1781c20*);
    virtual void release(Static1781c20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1781c20*);
struct Static1781c20 {
    void* value;
    Static1781c20();
    ~Static1781c20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
