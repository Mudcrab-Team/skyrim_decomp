// Source exposure: binary-analysis; no external implementation source reused.
// Static179c430, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179c430;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179c430*);
    virtual void release(Static179c430*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179c430*);
struct Static179c430 {
    void* value;
    Static179c430();
    ~Static179c430() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
