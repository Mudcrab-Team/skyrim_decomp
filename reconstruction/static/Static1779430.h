// Source exposure: binary-analysis; no external implementation source reused.
// Static1779430, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1779430;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1779430*);
    virtual void release(Static1779430*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1779430*);
struct Static1779430 {
    void* value;
    Static1779430();
    ~Static1779430() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
