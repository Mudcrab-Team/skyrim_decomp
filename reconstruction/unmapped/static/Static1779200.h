// Source exposure: binary-analysis; no external implementation source reused.
// Static1779200, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1779200;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1779200*);
    virtual void release(Static1779200*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1779200*);
struct Static1779200 {
    void* value;
    Static1779200();
    ~Static1779200() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
