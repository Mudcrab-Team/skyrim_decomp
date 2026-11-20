// Source exposure: binary-analysis; no external implementation source reused.
// Static176a430, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176a430;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176a430*);
    virtual void release(Static176a430*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176a430*);
struct Static176a430 {
    void* value;
    Static176a430();
    ~Static176a430() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
