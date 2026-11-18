// Source exposure: binary-analysis; no external implementation source reused.
// Static173c210, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173c210;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173c210*);
    virtual void release(Static173c210*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173c210*);
struct Static173c210 {
    void* value;
    Static173c210();
    ~Static173c210() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
