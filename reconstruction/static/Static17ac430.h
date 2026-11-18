// Source exposure: binary-analysis; no external implementation source reused.
// Static17ac430, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ac430;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ac430*);
    virtual void release(Static17ac430*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ac430*);
struct Static17ac430 {
    void* value;
    Static17ac430();
    ~Static17ac430() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
